#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<vector<int> > d;
vector<vector<bool> > g;

struct Trip {
  int u, v, t;
};
vector<Trip> trips;

void shortest_path(vector<vector<int> >& d) {
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (d[i][k] == -1) continue;
        if (d[k][j] == -1) continue;
        if (d[i][j] == -1 || d[i][k] + d[k][j] < d[i][j]) {
          d[i][j] = d[i][k] + d[k][j];
        }
      }
    }
  }
}

bool find(int i, vector<int>& match, vector<bool>& visited) {
  if (visited[i]) return false;
  visited[i] = true;
  for (int j = 0; j < k; ++j) {
  	if (!g[i][j]) continue;
    if (match[j] == -1 || find(match[j], match, visited)) {
      match[j] = i;
      return true;
    }
  }
  return false;
}

int max_match() {
  int ans = 0;
  vector<int> match(k, -1);
  for (int i = 0; i < k; ++i) {
    vector<bool> visited(k);
    if (find(i, match, visited)) {
      ++ans;
    }
  }
  return ans;
}

int main() {
  cin >> n >> m >> k;
  d.resize(n);
  for (int i = 0; i < n; ++i) {
    d[i].resize(n);
    for (int j = 0; j < n; ++j) {
      if (i == j) {
        d[i][j] = 0;
      } else {
        d[i][j] = -1;
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    d[u][v] = w;
  }
  shortest_path(d);
  g.resize(k);
  for (int i = 0; i < k; ++i) {
    g[i].resize(k);
    for (int j = 0; j < k; ++j) {
      g[i][j] = false;
    }
  }
  for (int i = 0; i < k; ++i) {
    int u, v, t;
    cin >> u >> v >> t;
    --u;
    --v;
    Trip trip;
    trip.u = u;
    trip.v = v;
    trip.t = t;
    trips.push_back(trip);
  }
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      if (i == j) continue;
      if (trips[i].t + d[trips[i].u][trips[i].v] + d[trips[i].v][trips[j].u] <=
          trips[j].t) {
        g[i][j] = true;
      }
    }
  }
  cout << k - max_match() << endl;
  return 0;
}