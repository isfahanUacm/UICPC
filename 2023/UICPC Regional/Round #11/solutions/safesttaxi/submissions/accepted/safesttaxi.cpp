#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

// Lane ID -> (row, col, direction, lane)
map<int, tuple<int, int, int, int>> id_to_rcdl;
// (row, col, direction, lane) -> Lane ID
map<tuple<int, int, int, int>, int> rcdl_to_id;
// Lane ID -> left/straight/right permissions
map<int, tuple<bool, bool, bool>> id_to_permission;
// Row/col/direction of start/destination
int rs0, cs0, rs1, cs1, ds, rd0, cd0, rd1, cd1, dd;
// Left turns / lane changes allowed
int n_left, n_lane;
// Lane ID -> lane count
map<int, int> id_to_lcnt;
// Lane ID -> length
map<int, int> id_to_len;

// A directed graph
struct Graph {
  // Start node
  int s;
  // Destination node(s)
  set<int> t;
  // Edges: from_node -> (to_node, weight)
  map<int, vector<pair<int, int>>> edge;
};

// Returns the direction of edge (r0, c0) -> (r1, c1)
// 0: south
// 1: east
// 2: north
// 3: west
int direction(const int r0, const int c0, const int r1, const int c1) {
  if ((r0 + 1 == r1) && (c0 == c1)) {
    return 0;
  }
  if ((r0 == r1) && (c0 + 1 == c1)) {
    return 1;
  }
  if ((r0 - 1 == r1) && (c0 == c1)) {
    return 2;
  }
  if ((r0 == r1) && (c0 - 1 == c1)) {
    return 3;
  }
  cerr << "invalid direction: " << r0 << " " << c0 << " " << r1 << " " << c1
       << endl;
  return -1;
}

// Returns the (row, col) when going direction 'd' from (r, c)
tuple<int, int> go_direction(const int r, const int c, const int d) {
  int r1, c1;
  if (d == 0) {
    return {r + 1, c};
  }
  if (d == 1) {
    return {r, c + 1};
  }
  if (d == 2) {
    return {r - 1, c};
  }
  if (d == 3) {
    return {r, c - 1};
  }
  return {-1, -1};
}

// Parses a lane description into (turn_left, go_straight, turn_right)
tuple<bool, bool, bool> permission(const string& f) {
  const bool left = f.find('L') != string::npos;
  const bool straight = f.find('S') != string::npos;
  const bool right = f.find('R') != string::npos;
  return {left, straight, right};
}

// Converts Lane ID into Node ID, by splitting each lane into (n_left + 1) *
// (n_lane + 1) nodes.
int id_to_node(const int id, const int left, const int lane) {
  return id * (n_left + 1) * (n_lane + 1) + left * (n_lane + 1) + lane;
}

// Parses a vector of lanes (from left to right) into intervals of left-turn /
// straight / right-turn lanes. (-1, -1) means an empty interval.
void lanes_to_ranges(const vector<tuple<bool, bool, bool>>& lanes,
                     pair<int, int>* left, pair<int, int>* straight,
                     pair<int, int>* right) {
  left->first = -1;
  left->second = -1;
  straight->first = -1;
  straight->second = -1;
  right->first = -1;
  right->second = -1;
  for (int i = 0; i < lanes.size(); ++i) {
    if (get<0>(lanes.at(i))) {
      left->second = i;
    }
    if (get<1>(lanes.at(i))) {
      straight->second = i;
    }
    if (get<2>(lanes.at(i))) {
      right->second = i;
    }
  }
  for (int i = lanes.size() - 1; i >= 0; --i) {
    if (get<0>(lanes.at(i))) {
      left->first = i;
    }
    if (get<1>(lanes.at(i))) {
      straight->first = i;
    }
    if (get<2>(lanes.at(i))) {
      right->first = i;
    }
  }
}

// Returns the (row, col, direction) when turning left from (r, c, d).
tuple<int, int, int> turn_left(const int r, const int c, const int d) {
  const auto [r1, c1] = go_direction(r, c, d);
  return {r1, c1, (d + 1) % 4};
}

// Returns the (row, col, direction) when going straight from (r, c, d).
tuple<int, int, int> go_straight(const int r, const int c, const int d) {
  const auto [r1, c1] = go_direction(r, c, d);
  return {r1, c1, d};
}

// Returns the (row, col, direction) when turning right from (r, c, d).
tuple<int, int, int> turn_right(const int r, const int c, const int d) {
  const auto [r1, c1] = go_direction(r, c, d);
  return {r1, c1, (d + 3) % 4};
}

// Builds the graph
Graph build_graph() {
  Graph g;
  // Start node: the right-most lane of (rs0, cs0, ds), no left turns, no lane
  // changes.
  const int slcnt = id_to_lcnt.at(rcdl_to_id.at({rs0, cs0, ds, 0}));
  const int sid = rcdl_to_id.at({rs0, cs0, ds, slcnt - 1});
  g.s = id_to_node(sid, 0, 0);
  // Destination nodes: the right-most lane of (rd0, cd0, dd), any left turns in
  // (0..n_left), any lane changes in (0..n_lane).
  const int dlcnt = id_to_lcnt.at(rcdl_to_id.at({rd0, cd0, dd, 0}));
  const int did = rcdl_to_id.at({rd0, cd0, dd, dlcnt - 1});
  for (int left = 0; left <= n_left; ++left) {
    for (int lane = 0; lane <= n_lane; ++lane) {
      g.t.insert(id_to_node(did, left, lane));
    }
  }
  for (const auto& [id, rcdl] : id_to_rcdl) {
    const auto& [r, c, d, l] = rcdl;
    const auto& [pl, ps, pr] = id_to_permission.at(id);
    const int lcnt = id_to_lcnt.at(id);
    const int half_len = id_to_len.at(id) / 2;
    // Parses lanes of (r, c, d) into intervals of left-turn, straight,
    // right-turn.
    vector<tuple<bool, bool, bool>> lanes;
    for (int i = 0; i < lcnt; ++i) {
      lanes.push_back(id_to_permission.at(rcdl_to_id.at({r, c, d, i})));
    }
    pair<int, int> l_range, s_range, r_range;
    lanes_to_ranges(lanes, &l_range, &s_range, &r_range);

    set<int> l_target_id, s_target_id, r_target_id;
    if (l_range.first >= 0 && l_range.second >= 0 && pl) {
      // Computes the target lane IDs if turning left.
      const auto [l_target_r, l_target_c, l_target_d] = turn_left(r, c, d);
      const int l_lcnt =
          id_to_lcnt.at(rcdl_to_id.at({l_target_r, l_target_c, l_target_d, 0}));
      if (l == l_range.second) {
        // Right-most left-turn lane. May turn into the rest of the lanes.
        for (int i = l - l_range.first; i < l_lcnt; ++i) {
          l_target_id.insert(
              rcdl_to_id.at({l_target_r, l_target_c, l_target_d, i}));
        }
      } else {
        // Normal left-turn lane. May turn into one lane only.
        l_target_id.insert(rcdl_to_id.at(
            {l_target_r, l_target_c, l_target_d, l - l_range.first}));
      }
    }
    if (s_range.first >= 0 && s_range.second >= 0 && ps) {
      // Computes the target lane IDs if going straight.
      const auto [s_target_r, s_target_c, s_target_d] = go_straight(r, c, d);
      const int s_lcnt =
          id_to_lcnt.at(rcdl_to_id.at({s_target_r, s_target_c, s_target_d, 0}));
      if (l == s_range.second) {
        // Right-most straight lane. May go into the rest of the lanes.
        for (int i = l - s_range.first; i < s_lcnt; ++i) {
          s_target_id.insert(
              rcdl_to_id.at({s_target_r, s_target_c, s_target_d, i}));
        }
      } else {
        // Normal straight lane. May go into one lane only.
        s_target_id.insert(rcdl_to_id.at(
            {s_target_r, s_target_c, s_target_d, l - s_range.first}));
      }
    }
    if (r_range.first >= 0 && r_range.second >= 0 && pr) {
      // Computes the target lane IDs if turning right.
      const auto [r_target_r, r_target_c, r_target_d] = turn_right(r, c, d);
      const int r_lcnt =
          id_to_lcnt.at(rcdl_to_id.at({r_target_r, r_target_c, r_target_d, 0}));
      if (l == r_range.first) {
        // Left-most right-turn lane. May go into the rest of the lanes.
        for (int i = 0; i < r_lcnt - (r_range.second - l); ++i) {
          r_target_id.insert(
              rcdl_to_id.at({r_target_r, r_target_c, r_target_d, i}));
        }
      } else {
        // Normal right-turn lane. May go into one lane only.
        r_target_id.insert(rcdl_to_id.at({r_target_r, r_target_c, r_target_d,
                                          r_lcnt - 1 - (r_range.second - l)}));
      }
    }
    for (int left = 0; left <= n_left; ++left) {
      for (int lane = 0; lane <= n_lane; ++lane) {
        vector<pair<int, int>> edge;
        if (lane != n_lane && l != 0) {
          // Lane change to the left
          edge.push_back(
              {id_to_node(rcdl_to_id.at({r, c, d, l - 1}), left, lane + 1), 0});
        }
        if (lane != n_lane && l != lcnt - 1) {
          // Lane change to the right
          edge.push_back(
              {id_to_node(rcdl_to_id.at({r, c, d, l + 1}), left, lane + 1), 0});
        }
        if (left != n_left && pl) {
          // Turn left
          for (const int lid : l_target_id) {
            edge.push_back({id_to_node(lid, left + 1, lane),
                            half_len + id_to_len.at(lid) / 2});
          }
        }
        if (ps) {
          // Go straight
          for (const int sid : s_target_id) {
            edge.push_back({id_to_node(sid, left, lane),
                            half_len + id_to_len.at(sid) / 2});
          }
        }
        if (pr) {
          // Turn right
          for (const int rid : r_target_id) {
            edge.push_back({id_to_node(rid, left, lane),
                            half_len + id_to_len.at(rid) / 2});
          }
        }
        g.edge.insert({id_to_node(id, left, lane), edge});
      }
    }
  }
  return g;
}

// Returns the shortest path from start to destination in the graph. Returns -1
// if no path exists.
int shortest_path(const Graph& g) {
  map<int, int> node_to_dist;
  node_to_dist.insert({g.s, 0});
  // Priority queue stores (distance, node) so that distance is the first key.
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push(make_pair(0, g.s));
  while (!pq.empty()) {
    pair<int, int> front = pq.top();
    pq.pop();
    const int dist = front.first;
    const int node = front.second;
    if (g.t.find(node) != g.t.end()) {
      return dist;
    }
    // This is necessary because a node may be pushed multiple times in the
    // queue.
    if (dist == node_to_dist.at(node)) {
      for (const auto& [v, l] : g.edge.at(node)) {
        if (node_to_dist.find(v) == node_to_dist.end() ||
            node_to_dist.at(node) + l < node_to_dist.at(v)) {
          node_to_dist[v] = node_to_dist.at(node) + l;
          pq.push(make_pair(node_to_dist.at(v), v));
        }
      }
    }
  }
  return -1;
}

int main() {
  int m, n, k;
  cin >> m >> n >> k;
  int r;
  cin >> r;
  int id = 0;
  for (int i = 0; i < r; ++i) {
    int r0, c0, r1, c1, t;
    cin >> r0 >> c0 >> r1 >> c1 >> t;
    int d = direction(r0, c0, r1, c1);
    for (int j = 0; j < k; ++j) {
      string f;
      cin >> f;
      id_to_rcdl.insert({id, make_tuple(r0, c0, d, j)});
      rcdl_to_id.insert({make_tuple(r0, c0, d, j), id});
      id_to_permission.insert({id, permission(f)});
      id_to_lcnt.insert({id, k});
      id_to_len.insert({id, t});
      ++id;
    }
  }
  int orders;
  cin >> orders;
  for (int i = 0; i < orders; ++i) {
    cin >> rs0 >> cs0 >> rs1 >> cs1;
    ds = direction(rs0, cs0, rs1, cs1);
    cin >> rd0 >> cd0 >> rd1 >> cd1;
    dd = direction(rd0, cd0, rd1, cd1);
    cin >> n_left >> n_lane;
    const Graph g = build_graph();
    const int ans = shortest_path(g);
    cout << ans << endl;
  }
  return 0;
}