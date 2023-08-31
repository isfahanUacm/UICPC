/* Sample solution for NCPC'08: Dinner
 * Author: Per Austrin
 * Algorithm: branch and bound (completely unoptimized)
 */
#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define dprintf debug && printf
bool debug = false;

typedef vector<int> vi;
typedef pair<int, int> pii;

int n, maxp;
vi G[600][2];

bool go(int v, int *part, int *sz) {
  while (v <= n && part[v] != -1) ++v;
  if (v > n) return true;
  int npart[600], nsz[2];
  for (int p = 0; p < 2; ++p) {
    queue<pii> Q;
    memcpy(npart+1, part+1, sizeof(int)*n);
    nsz[0] = sz[0];
    nsz[1] = sz[1];
    Q.push(pii(v, p));
    bool ok = true;
    dprintf("try %d -> %d\n", v, p);
    while (ok && !Q.empty()) {
      int w = Q.front().first, p = Q.front().second;
      Q.pop();
      dprintf(" process %d -> %d (%d %d %d %d)\n", w, p,  npart[w], nsz[0], nsz[1], maxp);
      if (npart[w] != -1 && npart[w] == p) continue;
      else if (npart[w] != -1 || nsz[p] == maxp) ok = false;
      else {
	npart[w] = p;
	++nsz[p];
	for (vi::iterator it = G[w][p].begin(); it != G[w][p].end(); ++it) {
	  Q.push(pii(*it, 1-p));
	  dprintf("  implies %d -> %d\n", *it, 1-p);
	}
      }
    }
    dprintf(" tried %d -> %d OK? %d\n", v, p, ok);
    if (ok && go(v+1, npart, nsz)) return true;
  }
  return false;
}

bool cansplit() {
  int part[600], sz[2];
  memset(part, -1, sizeof(part));
  sz[0] = sz[1] = 0;
  return go(1, part, sz);
}

int main(void) {
  int c, meet[600][600];
  scanf("%d%d", &n, &c);
  assert(n <= 400);
  assert(n >= 4);
  maxp = 2*n/3; // <-- change according to problem...
  //  maxp = n/2;
  for (int i = 1; i <= n; ++i) 
    for (int j = 1; j <= n; ++j)
      meet[i][j] = 2008;
  for (int i = 0; i < c; ++i) {
    int a, b, y;
    scanf("%d%d%d", &a, &b, &y);
    assert(y >= 1948 && y < 2008);
    assert(meet[a][b] == 2008);
    meet[a][b] = meet[b][a] = y;
  }
  for (c = 1948; c <= 2008; ++c) {
    for (int i = 1; i <= n; ++i) {
      G[i][0].clear();
      G[i][1].clear();
      for (int j = 1; j <= n; ++j)
	if (i != j) G[i][meet[i][j] < c].push_back(j);
    }
    if (cansplit()) break;
  }
  if (c <= 2008) printf("%d\n", c);
  else printf("Impossible\n");
  return 0;
}
