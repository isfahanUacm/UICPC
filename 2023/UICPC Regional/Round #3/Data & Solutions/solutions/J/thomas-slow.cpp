// Solution to John's Book Stack
// Author: Thomas Beuman

// Time complexity: O(n * 2^n)
// Memory: O(n)

// @EXPECTED_RESULTS@: TIMELIMIT

/*
Solution outline:

Look for topmost unsorted book, put it on top.
Repeat until the entire stack is sorted.

Waaaaay too slow
*/

#include <cstdio>
#include <list>
using namespace std;

typedef long long i64;

int main()
{ int cases, casenr, n, i, b;
  i64 steps;
  list<int>::iterator p, q;
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { scanf("%d\n", &n);
    list<int> Stack;
    for (i = 0; i < n; i++)
    { scanf("%d", &b);
      Stack.push_back(b);
    }
    steps = 0;
    for (steps = 0; true; steps++)
    { for (p = q = Stack.begin(), p++; p != Stack.end() && *p >= *q; q = p++); // Look for topmost unsorted book
      if (p == Stack.end()) // Done
        break;
      // Put it on top
      Stack.push_front(*p);
      Stack.erase(p);
    }
    printf("%lld\n", steps);
  }
  return 0;
}

