#include <bits/stdc++.h>

using namespace std;

double memo[101];

// f(P) = how many rounds to get a prize pack
double f(int P, int LP, int WP, int G, int L)
{
  P = min(100, P);

  if (memo[P] >= 0) {
    return memo[P];
  }

  if (P == 100) {
    return memo[P] = 1/(1 - L/100.0);
  }
  
  memo[P] = 0.0;

  // win this match
  {
    double t = 0.0;

    // get reward
    t += P/100.0;

    // no reward
    t += (1 - P/100.0) * (1 + f(P+WP, LP, WP, G, L));

    memo[P] += t * (1 - L/100.0);
  }

  // lose this match
  {
    double t = 0.0;
    t += 1 + f(P+LP, LP, WP, G, L);
    memo[P] += t * (L/100.0);
  }

  return memo[P];
}

int main()
{
  fill(memo, memo+101, -1.0);
  
  int P = 0, LP, WP, G, L;
  cin >> LP >> WP >> G >> L;

  // number of matches to get a reward, whether we get gorilla or not
  double ans = f(P, LP, WP, G, L);

  // if we failed to get gorilla so we start from P = 0 again
  ans += (1-G/100.0) * f(0, LP, WP, G, L) * 100.0/G;
  
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
