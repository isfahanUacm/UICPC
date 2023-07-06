#include <bits/stdc++.h>

using namespace std;

void solve()
{
  int b;
  double p;

  cin >> b >> p;

  double max_t = p/(b-1);
  double min_t = p/(b+1);
  double minBPM = 60/max_t;
  double calcBPM = 60*b/p;
  double maxBPM = 60/min_t;
  
  cout << fixed << setprecision(10)
       << minBPM << ' ' << calcBPM << ' ' << maxBPM << endl;

}

int main()
{
  int N;
  cin >> N;
  while (N--)
    solve();

  return 0;
}
