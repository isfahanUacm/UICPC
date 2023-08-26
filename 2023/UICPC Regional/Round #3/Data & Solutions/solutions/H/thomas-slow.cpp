// Solution to Hot Dogs in Manhattan
// Author: Thomas Beuman

// Time complexity: O(n*w*h)
// Memory: O(w*h)

// @EXPECTED_RESULTS@: TIMELIMIT

/*
Solution outline:

First determine the current privacy of every point by determining the Manhattan distances
to all points in the set and taking the minimum. (This should be too slow)

Do a binary search over the final answer:
Set a target privacy; consider all points that have this privacy or a larger one.
Now we want to see if there are two such points that are far enough apart.
For this, we only need to consider points which have the smallest/largest y-coordinate for each x-coordinate.
These are at most 2(w+1) such points; we can then try all pairs.
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int Px[1000], Py[1000];
int Privacy[1000][1000];
int ToCheck[2000][2];

int main()
{ int cases, casenr, n, w, h, i, j, x, y, m;
  int lowerbound, upperbound, target;
  bool possible;
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { scanf("%d %d %d\n", &n, &w, &h);
    for (i = 0; i < n; i++)
      scanf("%d %d\n", &Px[i], &Py[i]);
    memset(Privacy, 127, sizeof(Privacy)); // Set all privacies to "infinity"
    for (x = 0; x < w; x++)
      for (y = 0; y < h; y++)
        for (i = 0; i < n; i++)
          Privacy[x][y] = min(Privacy[x][y], abs(x-Px[i]) + abs(y-Py[i]));
    // Binary search over answer
    lowerbound = 1;
    upperbound = w + h + 1;
    while (lowerbound + 1 < upperbound)
    { target = (lowerbound + upperbound) / 2;
      m = 0;
      // For every column, only consider the two points with highest/lowest y-coordinate
      for (x = 0; x < w; x++)
      { for (y = 0; y < h && Privacy[x][y] < target; y++);
        if (y < h)
        { ToCheck[m][0] = x;
          ToCheck[m][1] = y;
          m++;
          for (y = h-1; Privacy[x][y] < target; y--);
          ToCheck[m][0] = x;
          ToCheck[m][1] = y;
          m++;
        }
      }
      // Try every possible combination
      possible = false;
      for (i = 1; i < m; i++)
        for (j = 0; j < i; j++)
          if (abs(ToCheck[i][0] - ToCheck[j][0]) + abs(ToCheck[i][1] - ToCheck[j][1]) >= target)
            possible = true;
      if (possible)
        lowerbound = target;
      else
        upperbound = target;
    }
    printf("%d\n", lowerbound);
  }
  return 0;
}

