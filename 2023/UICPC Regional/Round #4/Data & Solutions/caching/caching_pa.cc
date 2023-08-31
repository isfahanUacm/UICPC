/* Sample solution for NCPC'08: Introspective Caching
 * Author: Per Austrin
 * Algorithm: Greedy O(m*log(m))
 */
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;
#define B begin()

int main(void) {
  int r, d, m, res = 0;
  int rd[300000], last[300000], nxt[300000], in[300000];
  memset(last, -1, sizeof(last));
  memset(nxt, 0x1f, sizeof(nxt));
  memset(in, 0, sizeof(in));
  scanf("%d%d%d", &r, &d, &m);
  for (int i = 0; i < m; last[rd[i]] = i, ++i) {
    scanf("%d", rd+i);
    if (last[rd[i]] >= 0) nxt[last[rd[i]]] = i;
  }
  set<int> R;
  for (int i = 0; i < m; ++i) {
    if (in[rd[i]]) R.erase(-i), ++r, in[rd[i]] = 0;
    else if (++res, !r) in[rd[-*R.B]] = r++, R.erase(R.B);
    if (nxt[i] < m) R.insert(-nxt[i]), --r, in[rd[i]] = 1;
  }
  printf("%d\n", res);
  return 0;
}
