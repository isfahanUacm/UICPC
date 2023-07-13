#include <bits/stdc++.h>

using namespace std;

// I know binsearch is unnecessary...

typedef long long ll;
int Q, M, S, L;

bool check(ll T)
{
  ll num = T/Q;
  if (num * M < L) return false;
  return M*T >= Q*L + S;
}

int main()
{
  cin >> Q >> M >> S >> L;

  if (check(0)) {
    cout << 0 << endl;
    return 0;
  }
  
  ll lo = 0, hi = 1;
  while (!check(hi)) {
    hi *= 2;
  }
  while (hi-lo > 1) {
    ll mid = (lo+hi)/2;
    if (check(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << hi << endl;

  
  return 0;
}
