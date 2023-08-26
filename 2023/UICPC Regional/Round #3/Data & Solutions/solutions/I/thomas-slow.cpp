// Solution to Integer Lists
// Author: Thomas Beuman

// Time complexity: O(p*n)
// Memory: O(n)

// @EXPECTED_RESULTS@: TIMELIMIT

// Solution method: simulate using a list (with reversals)

#include <cstdio>
#include <list>
using namespace std;

int main()
{ int cases, casenr, n, i, x;
  list<int>::iterator j;
  char p[100001];
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { // Read input
    list<int> L;
    scanf("%s\n%d\n[", p, &n);
    for (i = 0; i < n; i++)
    { scanf("%d%*c", &x);
      L.push_back(x);
    }
    scanf("%*c "); // Read redundant characters (']', newline)
    // Process program
    for (i = 0; p[i] != '\0'; i++)
    { if (p[i] == 'R' && p[i+1] == 'R') // Slight optimization: ignore two consecutive R's
        i++;
      else if (p[i] == 'R')
        L.reverse(); // This is O(n) !!!
      else if (L.empty()) // Drop on empty list
        break;
      else
        L.pop_front();
    }
    // Output
    if (p[i] != '\0') // Drop on empty list
      printf("error\n");
    else if (L.empty()) // Empty list
      printf("[]\n");
    else
    { for (j = L.begin(); j != L.end(); j++)
        printf("%c%d", j == L.begin() ? '[' : ',', *j);
      printf("]\n");
    }
  }
  return 0;
}

