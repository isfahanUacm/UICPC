#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll binom[51][51];

void solve()
{
  ll N, v1, v2, W;
  cin >> N >> v1 >> v2 >> W;

  ll sum = 0;
  int rem = N - v1 - v2;
  for (int r = 0; r <= rem; r++) {
    if (v1 + r > N/2) {
      sum += binom[rem][r];
    }
  }

  if (sum == 0) {
    cout << "RECOUNT!" << endl;
  } else if (sum *100 > (W << rem) ) {
    cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
  } else {
    cout << "PATIENCE, EVERYONE!" << endl;
  }

}

int main()
{
  for (int n = 0; n <= 50; n++) {
    binom[n][n] = binom[n][0] = 1;
    for (int k = 1; k < n; k++) {
      binom[n][k] = binom[n-1][k] + binom[n-1][k-1];
    }
  }
  
  int T;
  cin >> T;
  while (T--)
    solve();
  
  return 0;
}
