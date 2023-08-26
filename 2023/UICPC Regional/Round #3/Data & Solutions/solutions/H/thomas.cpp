// Solution to Hot Dogs in Manhattan
// Author: Thomas Beuman

// Time complexity: O((w+h)^2)
// Memory: O(w*h)

// @EXPECTED_RESULTS@: CORRECT

/*
Solution outline:

First determine all current privacies by doing a "floodfill":
The Manhattan distance is the length of the shortest path along the grid.
Starting from all given points, use BFS find the shortest pathlength to all other points.

Determine the maximum privacy on every diagonal.
For every pair of diagonals, compute the minimum of the distance between them and their privacies.
Maximize this over all pairs; this gives the answer.
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int Privacy[1000][1000];
int BFSqueue[1000000][2];
int MaxPrivacy[1999];

int main()
{ int cases, casenr, n, w, h, i, j, x, y, x2, y2, current, last, p, m, best;
  int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { scanf("%d %d %d\n", &n, &w, &h);
    memset(Privacy, 127, sizeof(Privacy)); // Set all privacies to "infinity"
    for (i = 0; i < n; i++)
    { scanf("%d %d\n", &x, &y);
      Privacy[x][y] = 0;
      BFSqueue[i][0] = x;
      BFSqueue[i][1] = y;
    }
    // Calculate all current privacies with BFS
    last = n;
    for (current = 0; current < last; current++)
    { x = BFSqueue[current][0];
      y = BFSqueue[current][1];
      p = Privacy[x][y];
      for (i = 0; i < 4; i++) // Check all neighboring points
      { x2 = x + dx[i];
        y2 = y + dy[i];
        if (x2 >= 0 && x2 < w && y2 >= 0 && y2 < h && Privacy[x2][y2] > p+1)
        { Privacy[x2][y2] = p+1;
          BFSqueue[last][0] = x2;
          BFSqueue[last][1] = y2;
          last++;
        }
      }
    }
    best = 0;
    // Determine maximum privacy on every x+y=const diagonal
    for (i = 0; i < w+h-1; i++)
    { // Determine the leftmost point on the i-th diagonal
      x = (i < h ? 0 : i+1-h);
      y = i-x;
      m = 0;
      for (; x < w && y >= 0; x++, y--) // Traverse the diagonal
        m = max(m, Privacy[x][y]);
      MaxPrivacy[i] = m;
    }
    // For every pair of diagonals, take the minimum of their maximum privacies and their mutual distance
    for (i = 1; i < w+h-1; i++)
      for (j = 0; j < i; j++)
        best = max(best, min(i-j, min(MaxPrivacy[i], MaxPrivacy[j])));
    // Same now for the x-y=const diagonals
    for (i = 0; i < w+h-1; i++)
    { x = (i < h ? 0 : i+1-h);
      y = h-1-i+x;
      m = 0;
      for (; x < w && y < h; x++, y++)
        m = max(m, Privacy[x][y]);
      MaxPrivacy[i] = m;
    }
    for (i = 1; i < w+h-1; i++)
      for (j = 0; j < i; j++)
        best = max(best, min(i-j, min(MaxPrivacy[i], MaxPrivacy[j])));
    printf("%d\n", best);
  }
  return 0;
}

