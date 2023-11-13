#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct sets {
  vector<int> par, size;
  sets(int n): par(vi(n)), size(vi(n)) {
    for (int i = 0; i < n; ++i) par[i] = i;
  }

  int get_par(int u) {
    if (par[u] != u) par[u] = get_par(par[u]);
    return par[u];
  }

  bool join(int u, int v) {
    u = get_par(u);
    v = get_par(v);
    if (u == v) return false;
    if (size[u] < size[v]) par[u] = v;
    else par[v] = u, size[u] += size[u] == size[v];
    return true;
  }
};

int main(void) {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);

  vi ans(q);
  vector<vector<pii>> undo(q);
  vector<vi> col(n, vi(m, 0));
  vector<set<int>> x_rem(m), y_rem(n);
 
  for (int x = 0; x < n; ++x)
    for (int y = 0; y < m; ++y) {
      x_rem[y].insert(x);
      y_rem[x].insert(y);
    }

  for (auto &u: undo) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    auto take = [&col, &u, &x_rem, &y_rem](int x, int y) {
      col[x][y] = 1;
      u.push_back(pii(x, y));
      y_rem[x].erase(y);
      x_rem[y].erase(x);
    };
    --x1; --y1;
    if (x2-x1 > 1)
      for (auto it = x_rem[y1].lower_bound(x1); it != x_rem[y1].end() && *it < x2; take(*it++, y1));
    else
      for (auto it = y_rem[x1].lower_bound(y1); it != y_rem[x1].end() && *it < y2; take(x1, *it++));
  }
  
  sets S(n*m);
  int black = 0, components = n*m;

  for (int x = 0; x < n; ++x)
    for (int y = 0; y < m; ++y) {
      if (col[x][y]) ++black;
      else {
	if (x > 0 && col[x-1][y] == 0)
	  components -= S.join(m*(x-1)+y, m*x+y);
	if (y > 0 && col[x][y-1] == 0)
	  components -= S.join(m*x+y-1, m*x+y);
      }
    }

  for (int i = q-1; i >= 0; --i) {
    ans[i] = components - black;
    for (auto p: undo[i]) {
      col[p.first][p.second] = 0;
      const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
      for (int dir = 0; dir < 4; ++dir) {
	int nx = p.first + dx[dir], ny = p.second + dy[dir];
	if (0 <= nx && nx < n && 0 <= ny && ny < m && col[nx][ny] == 0)
	  components -= S.join(m*p.first+p.second, m*nx+ny);
      }
    }
    black -= undo[i].size();
  }

  for (auto a: ans)
    printf("%d\n", a);
}
