/* Sample solution for NCPC'08: Dinner
 * Author: Nils Grimsmo
 * 
 * Solution: 1. Place the people who can only be in one group, as putting
 *              them in the other would necessarily lead to a too small group.
 *           2. Recursively try to place the rest.  Placing somebody in the 
 *              first group means putting all those he met in/after in the
 *              other, while putting him in the second, means putting those he
 *              met before in the first.
 */
#include <algorithm>
#include <cassert>
#include <cstdio>

using namespace std;

const int MAX_m = 500;
const int MIN_y = 1928;
const int MAX_y = 2008;

int F[MAX_m][MAX_m]; // First meet
int m, c;

// Local to each year Y:
int G[MAX_m]; // Group placement.
int M[3][MAX_m]; // Number met before, or in/after

int count_group(int _g) {
  int _c = 0; 
  for (int a = 0; a < m; ++a) _c += G[a] == _g;
  return _c;
}

bool count_check() {
  // No group larger than 2/3 m
  return 3 * count_group(1) <= 2 * m &&
         3 * count_group(2) <= 2 * m;
}

bool check(int Y, int a, int b) {
  assert(a != b);
  if (G[a] > 0 && G[a] == G[b]) {
    if (G[a] == 1 && F[a][b] >= Y) return false;
    if (G[a] == 2 && F[a][b] <  Y) return false;
  }
  return true;
}

bool check(int Y, int a) {
  for (int b = 0; b < m; ++b) if (a != b) 
    if (!check(Y, a, b)) return false;
  return true;
}

bool check(int Y) {
  for (int a = 0; a < m; ++a) 
    if (!check(Y, a)) return false;
  return true;
}

bool put(int Y, int a, int g) {
  if (G[a] == g) return true;  // Already put in group, OK
  else if (G[a]) return false; // Or in other group, not OK
  G[a] = g;
  if (!count_check() || !check(Y, a)) return false;
  for (int b = 0; b < m; ++b) if (a != b) 
    // If a and b cannot both be in group g
    if ( (g == 1 && F[a][b] >= Y) || (g == 2 && F[a][b] < Y) ) 
      // Put b in the other group
      if (!put(Y, b, 3-g)) return false;
  return true;
}

bool solve(int Y) {
  for (int a = 0; a < m; ++a) {
    // Find first unplaced person
    if (!G[a]) {
      int _H[MAX_m]; copy(G, G+m, _H); // Save setup in case we mess it up
      // Try both groups
      for (int g = 1; g <= 2; ++g) {
        if (put(Y, a, g) && solve(Y)) return true; // Done
        // Clean up
        copy(_H, _H+m, G);
      }
      return false; // Could not put a in either group
    }
  }
  assert(check(Y));
  return true;
}

bool sulve(int Y) {
  fill(G, G+m, 0);
  fill(M[1], M[1]+m, 0);
  fill(M[2], M[2]+m, 0);
  // Count the number met before, and in/after
  for (int a = 0; a < m; ++a) for (int b = 0; b < m; ++b) if (a != b) {
    if (F[a][b] <  Y) ++M[1][a];
    if (F[a][b] >= Y) ++M[2][a];
  }
  // Place some people first, which must be in one group
  for (int a = 0; a < m; ++a) {
    // First group would be too small, must go in second
    if (3 * (M[1][a] + 1) < 1 * m) 
      if (!put(Y, a, 2)) return false;
    // Second group would be too small, must go in first
    if (3 * (M[2][a] + 1) < 1 * m) 
      if (!put(Y, a, 1)) return false;
  }
  // Then try to place the rest
  return solve(Y);
}

int main() {
  scanf("%d %d", &m, &c);
  for (int a = 0; a < m; ++a)
    for (int b = 0; b < m; ++b)
      F[a][b] = F[b][a] = MAX_y;
  for (int i = 0; i < c; ++i) {
    int a, b, y; scanf("%d %d %d", &a, &b, &y);
    F[a-1][b-1] = F[b-1][a-1] = y;
  }
  bool found = false;
  int Y;
  for (Y = MIN_y; Y <= MAX_y; ++Y) {
    if (sulve(Y)) break;
  }
  if (Y <= MAX_y) printf("%d\n", Y);
  else            printf("Impossible\n");
}
