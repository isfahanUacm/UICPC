#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 500;

int main()
{
  int n;
  cin >> n;

  int prob[MAX_N];

  for (int i = 0; i < n; i++) {
    string pw;
    char ch;
    int d;
    
    cin >> pw;
    cin >> prob[i];
    prob[i] *= 10000;
    cin >> ch >> d;
    prob[i] += d;
  }
  sort(prob, prob+n);

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += prob[n-i] * i;
  }

  cout << ans/10000 << '.' << setw(4) << setfill('0')
       << ans%10000 << endl;
  return 0;
}
