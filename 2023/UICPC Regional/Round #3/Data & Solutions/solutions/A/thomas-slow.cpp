// Solution to Another Dice Game
// Author: Thomas Beuman

// Time complexity: O((n * dice * 2^6) *   6^n  *    6   )
//                  O(     states      * throws * options)
// Memory: O(n * dice * 2^6)

// @EXPECTED_RESULTS@: TIMELIMIT

// Solution method: DFS with memorization (but with inefficient traversal of throws)

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

typedef double dbl; // Use long double for greater accuracy

dbl Prob[41][9][64];
bool Seen[41][9][64];
int Points[6] = {1,2,3,4,5,5};
int Factorial[9] = {1,1,2,6,24,120,720,5040,40320};

// Returns probability of reaching target, given number of dice and values not yet put aside
dbl prob (int target, int dice, int available)
{ if (target <= 0 && !(available & 32)) // Target reached and worm put aside
    return 1.0;
  if (dice == 0) // Failed
    return 0;
  if (target < 0) // Only a worm left to get
    target = 0;
  if (Seen[target][dice][available]) // Already calculated
    return Prob[target][dice][available];
  int Die[8], Number[6];
  int i;
  dbl best, p = 0;
  // Consider all possible outcomes of the throw
  // First possibility: all ones
  for (i = 0; i < dice; i++)
    Die[i] = 0;
  while (true)
  { // Count the values of the dice
    for (i = 0; i < 6; i++)
      Number[i] = 0;
    for (i = 0; i < dice; i++)
      Number[Die[i]]++;
    // Look for best strategy: try all options
    best = 0;
    for (i = 0; i < 6; i++)
      if ((available & (1 << i)) && Number[i] > 0)
        best = max(best, prob(target - Number[i]*Points[i], dice - Number[i], available ^ (1 << i)));
    p += best;
    // Next possible outcome
    for (i = 0; i < dice && Die[i] == 5; i++) // Set dice with worm to one
      Die[i] = 0;
    if (i == dice) // All worms: done
      break;
    Die[i]++; // Increase value of first non-worm die by one
  }
  Seen[target][dice][available] = true;
  return Prob[target][dice][available] = p / pow(6.0, dice);
}

int main()
{ int cases, casenr, n;
  scanf("%d\n", &cases);
  memset(Seen, false, sizeof(Seen));
  for (casenr = 1; casenr <= cases; casenr++)
  { scanf("%d\n", &n);
    printf("%.10lf\n", prob(n, 8, 63));
  }
  return 0;
}

