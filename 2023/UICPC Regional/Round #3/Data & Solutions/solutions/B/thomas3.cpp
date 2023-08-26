// Solution to Black Out
// Author: Thomas Beuman

// Time complexity: O(120*2^24) precalculation, O(120) per move
// Memory: O(2^24)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: precalculate all losing states using DP
// Assumption: making bottom row black is a winning first move

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

const int H = 4, W = 6; // Ignore bottom row
const int S = 1 << (H*W), M = H*W*(H+W)/2; // S = #states, M = #moves
  
int Move[M];
coordinates Coord[M];
bool Losing[S];

int main()
{ int cases, casenr, m = 0, state, s, i, r, c, r1, c1, r2, c2;
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
  
  /*** Determine evaluation for all states ***/
  memset(Losing, false, sizeof(Losing)); // Set all states to winning
  Losing[S-1] = true; // Set state "all black" to losing
  for (s = S-2; s >= 0; s--)
  { // Look for winning move
    for (i = 0; i < M; i++)
      if (Losing[s | Move[i]])
        break;
    if (i == M) // No winning move found
      Losing[s] = true;
  }
  if (!Losing[0])
  { fprintf(stderr, "Making the bottom row black is not a winning move!\n");
    return 0;
  }
  
  /*** Let's play! ***/
  scanf("%d", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { printf("5 1 5 6\n"); // Make bottom row black
    fflush(NULL);
    state = 0;
    while (scanf(" %c%*c%*c%*c%*c", &t) && t == 'M') // Repeat while jury makes a move
    { scanf("%d %d %d %d", &r1, &c1, &r2, &c2); // Read move
      r1--; c1--; r2--; c2--;
      // Update state
      if (r1 == r2)
        for (i = c1; i <= c2; i++)
          state |= 1 << (r1*W+i);
      else
        for (i = r1; i <= r2 && i < H; i++)
          state |= 1 << (i*W+c1);
      if (Losing[state])
      { fprintf(stderr, "Wait, I'm losing?!\n");
        return 0;
      }
      for (i = 0; i < M && !Losing[state | Move[i]]; i++); // Look for winning move
      if (i == M)
      { fprintf(stderr, "How can I not have a winning move?!\n");
        return 0;
      }
      // Output
      printf("%d %d %d %d\n", Coord[i].r1+1, Coord[i].c1+1, Coord[i].r2+1, Coord[i].c2+1);
      fflush(NULL);
      state |= Move[i]; // Update state
    }
  }
  return 0;
}

