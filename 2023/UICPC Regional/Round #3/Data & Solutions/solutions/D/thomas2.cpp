// Solution to Digit Sum
// Author: Thomas Beuman

// Time complexity: O(log b)
// Memory: O(1)

// @EXPECTED_RESULTS@: CORRECT

/*
Solution outline:

Compute the digitsum from 0 to b and from 0 to a-1, and subtract the two

Determine the digitsum from 0 to n-1 per digit
Example: digitsum of the 3rd digit for n = 34567:
  3400 * (0+1+2+3+4+5+6+7+8+9) + 100 * (0+1+2+3+4) + 67 * 5
*/

#include <cstdio>
using namespace std;

typedef long long i64;

// Returns the sum of all digits from 0 to n-1
i64 digitsum (i64 n)
{ int d;
  i64 m, s = 0;
  for (m = 1; m < n; m *= 10)
  { d = (n/m)%10;
    s += (n/m/10)*m * 45 + m * d*(d-1)/2 + (n%m) * d;
  }
  return s;
}

int main()
{ int cases, casenr;
  i64 a, b;
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { scanf("%lld %lld\n", &a, &b);
    printf("%lld\n", digitsum(b+1) - digitsum(a));
  }
  return 0;
}

