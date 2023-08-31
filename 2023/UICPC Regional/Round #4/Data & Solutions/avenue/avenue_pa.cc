/* Sample solution for NCPC'08: Aspen Avenue
 * Author: Per Austrin
 * Algorithm: DP
 */
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int N, L, W, dropy[3000];
double best[1100][1100], step;
double hyp(double x, double y) { return sqrt(x*x+y*y); }

double Best(int l, int r) {
  if (l < 0 || r < 0) return 1e30;
  if (l+r == 0) return 0;
  double &res = best[l][r];
  if (res == 0) {
    res = 1e30;
    int ty = dropy[l+r-1];
    res <?= hyp(0, step*(l-1)-ty) + Best(l-1, r);
    res <?= hyp(W, step*(r-1)-ty) + Best(l, r-1);
    //    printf("best %d %d (ty %d) = %lf\n", l, r, ty, res);
    ++res;
  }
  return res-1;
}

int main(void) {
  scanf("%d%d%d", &N, &L, &W);
  int t[2], p[2];
  step = 1.0*L / (N/2-1);
  for (int i = 0; i < N; ++i)
    scanf("%d", dropy+i);
  sort(dropy, dropy+N);
  memset(best, 0, sizeof(best));
  printf("%.10lf\n", Best(N/2, N/2));
  return 0;
}
