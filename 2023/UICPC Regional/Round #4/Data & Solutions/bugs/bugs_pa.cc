/* Sample solution for NCPC'08: Best Compression Ever
 * Author: Per Austrin
 * Algorithm: DP - Runtime O(T^2*2^B).
 */
#include <cstdio>
#include <cassert>
#include <cstring>

int B, T;
double f;
double p[20];
int s[20], fails[20];

int next[1<<10][110];
double solve[1<<10][110][110];

double Solve(int left, int T, int F) {
  assert(left >= 0 && T >= 0 && F >= 0);
  if (!T || !left) return 0;
  double &res = solve[left][T][F];
  if (!res) {
    int &bug = next[left][F];
    if (bug == -1) {
      double bestv = -1;
      for (int b = 0; b < B; ++b)
	if ((left & (1<<b)) && p[b]*s[b] > bestv)
	  bug = b, bestv = p[b]*s[b];
    }
    assert(0 <= bug && bug < B && (left & (1<<bug)));
    double q = p[bug];
    p[bug] *= f;
    ++fails[bug];
    res += 1 + (1-q) * Solve(left, T-1, F+1);
    --fails[bug];
    p[bug] = q;
    res += q * (s[bug] + Solve(left & ~(1<<bug), T-1, F - fails[bug]));
  }
  return res-1;
}

int main(void) {
  scanf("%d%d%lf", &B, &T, &f);
  assert(0 <= B && B <= 10);
  assert(0 <= T && T <= 100);
  assert(0 <= f && f <= 1);
  for (int i = 0; i < B; ++i) {
    scanf("%lf%d", p+i, s+i);
    assert(0 <= p[i] && p[i] <= 1);
    assert(1 <= s[i] && s[i] <= 10000);
  }
  memset(next, -1, sizeof(next));
  memset(solve, 0, sizeof(solve));
  memset(fails, 0, sizeof(fails));
  printf("%.10lf\n", Solve((1<<B)-1, T, 0));
  return 0;
}
