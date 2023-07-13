#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll solve(ll n, ll m)
{
  if (m == n-1) {
    return m*(m+1)/2;
  }

  // clique size
  ll k = ceil((3 + sqrt(9 - 8*(n-m)))/2);
  ll ans = m*(m+1)/2 - (m-(n-k))*(m-(n-k)+1)/2;

  m -= n-k;
  n = k;

  ll next = 1;
  for (int nn = 2; nn <= n; nn++) {
    ans += next;
    next += nn-1;
  }
  return ans;
}

int main()
{
  ll n, m;
  cin >> n >> m;


  cout << solve(n, m) << endl;
  
  return 0;
}
