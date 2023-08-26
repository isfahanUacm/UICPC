// Solution to Black Out
// Author: Thomas Beuman

// Time complexity: O(1)
// Memory: O(1)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: start by making the center row black, then copy/rotate the jury's move

#include <cstdio>
using namespace std;

int main()
{ int cases, casenr, r1, c1, r2, c2;
  char c;
  scanf("%d", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { printf("3 1 3 6\n");
    fflush(NULL);
    while (scanf(" %c%*c%*c%*c%*c", &c) && c == 'M') // Repeat while jury makes a move
    { scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
      printf("%d %d %d %d\n", 6-r2, 7-c2, 6-r1, 7-c1); // Rotate move
      fflush(NULL);
    }
  }
  return 0;
}

