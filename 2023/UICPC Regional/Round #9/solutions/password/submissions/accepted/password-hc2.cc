#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 500;

int main()
{
  int n;
  cin >> n;

  double prob[MAX_N];

  for (int i = 0; i < n; i++) {
    string pw;
    
    cin >> pw;
    cin >> prob[i];
  }
  sort(prob, prob+n);

  double ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += prob[n-i] * i;
  }

  cout << setprecision(4) << fixed << ans << endl;
  return 0;
}
