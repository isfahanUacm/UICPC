#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const string colors = "ROYGBIV";

int n, m;

struct Edge
{
  int v, d, c;
  Edge(int vv, int dd, int cc)
    : v{vv}, d{dd}, c{cc} {}
};

vector<vector<Edge>> G;

typedef pair<int,int> State;
typedef pair<ll,State> DijkNode;
  
ll solve()
{
  priority_queue<DijkNode, vector<DijkNode>, greater<DijkNode>> pq;
  map<State, int> D;
  
  State start{0,0}, dest{0,(1<<7)-1};
  DijkNode src{0, start};
  D[start] = 0;
  pq.push(src);

  while (!pq.empty()) {
    auto curr = pq.top();
    pq.pop();

    auto curr_state = curr.second;
    auto curr_dist = curr.first;

    if (curr_state == dest) {
      return D[curr_state];
    }
    if (curr_dist > D[curr_state]) continue;

    auto u = curr_state.first;
    for (auto e : G[u]) {
      State next{e.v, curr_state.second | (1 << e.c)};
      ll next_d = curr_dist + e.d;
      if (D.find(next) == D.end() || next_d < D[next]) {
	D[next] = next_d;
	pq.emplace(next_d, next);
      }
    }

  }
  assert(false);
  return -1;
}

int main()
{
  cin >> n >> m;
  G.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v, d;
    char c;
    cin >> u >> v >> d >> c;
    u--;  v--;
    int cindex = colors.find(c);
    G[u].emplace_back(v, d, cindex);
    G[v].emplace_back(u, d, cindex);
  }

  cout << solve() << endl;
  
  return 0;
}
