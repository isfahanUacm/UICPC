/* Sample solution for NCPC'08: Dinner
 * Author: Nils Grimsmo
 *
 * Solution: - Greedily make a local choice to fix the bug with maximal current
 *             p[i] * s[i].
 *           - DP:
 *               - Given a time left, a set of unfixed bugs, and a number of
 *                 failures on unfixed bugs, you will always do the same
 *                 choices.
 *               - Use a bit pattern for the second.
 *               - Keep the p[i]'s updated as you recurse with failures.
 *
 * Running time: O(T^2 2^B)
 */
#include <algorithm>
#include <cassert>
#include <cstdio>

const int MAX_B = 10;
const int MAX_T = 100;

int B, T; 
double f;
double p[MAX_B]; // Fix probability
int s[MAX_B];    // Bug severity

double A[MAX_T][1 << MAX_B][MAX_T];
int N[MAX_B]; // Number of falings on fixing each bug

          // Time left, bugs fixed, total fails on unfixed bugs
double solve(int t = 0, int b = 0, int n = 0) {
  if (t == T || b == ((1 << B) - 1)) return 0;
  if (A[t][b][n] == -1) {
    int i = -1;
    double m = -1; // Maximal expected severity fix
    for (int j = 0; j < B; ++j) 
      if (! (b & (1 << j))) {  // Bug already fixed?
        if (p[j] * s[j] > m) {
          m = p[j] * s[j];
          i = j;
        }
    }
    assert(0 <= i && i <= B);
    // Fail
    double pi = p[i]; // Save this, as we change it
    p[i] *= f; ++N[i];
    double x = (1-pi) * solve(t + 1, b, n + 1);
    p[i] = pi; --N[i];
    // Succeed
    x += p[i] * (s[i] + solve(t + 1, b | (1 << i), n - N[i]));
    A[t][b][n] = x;
  }
  return A[t][b][n];
}

int main() {
  scanf("%d %d %lf", &B, &T, &f);
  for (int i = 0; i < B; ++i) 
    scanf("%lf %d", &p[i], &s[i]);
  for (int t = 0; t < T; ++t) 
    for (int b = 0; b < 1 << B; ++b) 
      for (int f = 0; f < T; ++f) 
        A[t][b][f] = -1;
  for (int i = 0; i < B; ++i) 
    N[i] = 0;
  printf("%.6lf\n", solve());
}
