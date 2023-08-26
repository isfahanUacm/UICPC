// Solution to John's Book Stack
// Author: Thomas Beuman

// Time complexity: O(n^2)
// Memory: O(n)

// @EXPECTED_RESULTS@: CORRECT

/*
Solution outline:

Look for topmost unsorted book, put it in its correct place, calculate how many steps this takes.
Repeat until the entire stack is sorted.

This solution uses an array.
*/

#include <cstdio>
using namespace std;

typedef long long i64;

int Stack[50];

int main()
{ int cases, casenr, n, i, j, k;
  i64 steps, s;
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { scanf("%d\n", &n);
    for (i = 0; i < n; i++)
      scanf("%d", &Stack[i]);
    steps = 0;
    while (true)
    { for (i = 1; i < n && Stack[i] >= Stack[i-1]; i++); // Look for topmost unsorted book
      if (i == n) // Done
        break;
      // Compute number of steps needed to put it in the right place
      s = 1ll;
      k = 2;
      for (j = 0; Stack[j] < Stack[i]; j++)
      { if (Stack[j] == Stack[j+1])
          k++;
        else
        { s *= k;
          k = 2;
        }
      }
      steps += s;
      // Put it (i) in its correct place (j)
      k = Stack[i];
      for (; i > j; i--)
        Stack[i] = Stack[i-1];
      Stack[j] = k;
    }
    printf("%lld\n", steps);
  }
  return 0;
}

