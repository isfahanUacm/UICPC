/* Sample solution for NCPC'08: Aspen avenue
 * Author: Nils Grimsmo
 *
 * Solution: - Sort the trees dropped on the left side.
 *           - From the bottom of the avenue, put the next unplanted
 *             tree into either the lowest "hole" on the left or 
 *             right side (one of these is always the optimal move).
 *           - Do dynamic programming on the number of trees planted 
 *             so far on the left and right side.
 *               (This means remember the answer for having planted 
 *                these trees, having the rest to go.  Otherwise, you
 *                may end up calculating it multiple times.  
 *                See the source code.)
 *
 * Running time: O(n^2)
 */
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

const int MAX_N = 2000;

int N;
double L, W;
double DR[MAX_N]; // Drop position
double td;        // Tree distance
double C[MAX_N/2+1][MAX_N/2+1]; // Cost of moving this many to the left 
                                // and that many to the right

// Euclidean distance
double dist(double x1, double y1, double x2, double y2) {
  double xd = x2 - x1, yd = y2 - y1;
  return sqrt(xd*xd + yd*yd);
}

             // Trees placed so far on left and right
double solve(int le, int ri) {
  if (C[le][ri] == -1) { // Not calculated before
    double c = INFINITY;
    int tot = le + ri; 
    if (tot == N) c = 0.0;  // No trees left to place...
    // Place next tree on left or right
    if (le < N/2) c = min(c, dist(0, DR[tot], 0, le * td) + solve(le + 1, ri));
    if (ri < N/2) c = min(c, dist(0, DR[tot], W, ri * td) + solve(le, ri + 1));
    C[le][ri] = c;
  } 
  return C[le][ri];
}

int main() {
  scanf("%d %lf %lf", &N, &L, &W);
  td = L / (N/2 - 1); // -1 as we need tree at end of road also
  for (int i = 0; i < N; ++i) 
    scanf("%lf", &DR[i]);
  sort(DR, DR + N);
  for (int le = 0; le <= N/2; ++le) 
    for (int ri = 0; ri <= N/2; ++ri) 
      C[le][ri] = -1;
  printf("%.10lf\n", solve(0, 0));
} 
