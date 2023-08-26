// Solution to Black Out
// Author: Thomas Beuman

// Time complexity: O(#moves) (= 165)
// Memory: O(#moves)

// @EXPECTED_RESULTS@: WRONG-ANSWER

// Solution method: make a random legal move

#include <cstdio>
#include <cstring>
using namespace std;

struct coordinates
{ int r1, c1, r2, c2;
  coordinates() {}
  coordinates (int x1, int y1, int x2, int y2)
  { r1 = x1; c1 = y1; r2 = x2; c2 = y2;
  }
};

const int H = 5, W = 6;
const int M = H*W*(H+W)/2; // S = #states, M = #moves

int Move[M];
coordinates Coord[M];

// Returns (pseudo)random integer
long long rseed = 42;
int randnr()
{ return (int)(rseed = (16807 * rseed) % 0x7fffffff);
}

int main()
{ int cases, casenr, state, n, m = 0, i, r, c, r1, c1, r2, c2;
  char t;
  
  /*** Determine all possible moves ***/
  // Single squares
  for (r = 0; r < H; r++)
    for (c = 0; c < W; c++)
    { Move[m] = 1 << (r*W+c);
      Coord[m] = coordinates(r, c, r, c);
      m++;
    }
  // Horizontal
  for (r = 0; r < H; r++)
    for (c = 0; c < W-1; c++)
    { Move[m] = (1 << (r*W+c)) | (1 << (r*W+c+1));
      Coord[m] = coordinates(r, c, r, c+1);
      m++;
      for (c2 = c+2; c2 < W; c2++)
      { Move[m] = Move[m-1] | (1 << (r*W+c2));
        Coord[m] = coordinates(r, c, r, c2);
        m++;
      }
    }
  // Vertical
  for (c = 0; c < W; c++)
    for (r = 0; r < H-1; r++)
    { Move[m] = (1 << (r*W+c)) | (1 << (r*W+c+W));
      Coord[m] = coordinates(r, c, r+1, c);
      m++;
      for (r2 = r+2; r2 < H; r2++)
      { Move[m] = Move[m-1] | (1 << (r2*W+c));
        Coord[m] = coordinates(r, c, r2, c);
        m++;
      }
    }
  
  /*** Let's play! ***/
  scanf("%d", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { state = 0;
    while (true)
    { // Take random legal move
      n = 0; // Number of legal moves
      for (i = 0; i < M; i++)
        // Check for legality and accept with probability 1/n
        if ((state | Move[i]) > state && randnr() % (++n) == 0)
          m = i;
      // Output
      printf("%d %d %d %d\n", Coord[m].r1+1, Coord[m].c1+1, Coord[m].r2+1, Coord[m].c2+1);
      fflush(NULL);
      state |= Move[m]; // Update state
      scanf(" %c%*c%*c%*c%*c", &t); // Read response
      if (t == 'G')
        break;
      scanf("%d %d %d %d", &r1, &c1, &r2, &c2); // Read move
      r1--; c1--; r2--; c2--;
      // Update state
      if (r1 == r2)
        for (i = c1; i <= c2; i++)
          state |= 1 << (r1*W+i);
      else
        for (i = r1; i <= r2; i++)
          state |= 1 << (i*W+c1);
    }
  }
  return 0;
}

