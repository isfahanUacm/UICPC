/* Sample solution for NCPC'08: Getting Gold
 * Author: Nils Grimsmo
 * 
 * Solution: Breadth first search through the maze.
 */
#include <cassert>
#include <cstdio>

const int MAX_W = 100;
const int MAX_H = 100;

int W, H; // Dimmensions
char M[MAX_H][MAX_W]; // Map

int find(int i, int j) {
  assert(M[i][j] != 'T');
  if (M[i][j] == '#') return 0; // Couldn't go here
  if (M[i][j] == 'v') return 0; // Already been here
  // Okay, so we could go here...
  int gold = M[i][j] == 'G'; // Gold we gather from here
  M[i][j] = 'v'; // Mark that we've been here 
  // Check if there is a draft
  if (M[i-1][j] == 'T' || M[i][j-1] == 'T' 
      || M[i+1][j] == 'T' || M[i][j+1] == 'T') 
    return gold;
  // Okay, no draft, continue search
  gold += find(i-1, j)
        + find(i, j-1)
        + find(i+1, j)
        + find(i, j+1);
  return gold;
}

int main() {
  // Read maze
  scanf("%d %d", &W, &H);
  for (int i = 0; i < H; ++i) {
    scanf("%s", M[i]);
  }
  // Find starting position and search
  for (int i = 0; i < H; ++i)
    for (int j = 0; j < W; ++j) 
      if (M[i][j] == 'P') 
        printf("%d\n", find(i, j));
}
