// Complexity: O(sqrt(a) + sqrt(b))

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// -1 - prime, 0 - squarefull, 1 - squarefree not prime
int sqfree(ll x) {
  int isp = -1;
  for (ll p = 2; p*p <= x; ++p)
    if (x%(p*p) == 0) return 0;
    else if (x%p == 0) isp = 1;

  return isp;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main() {
  ll a, b;

  cin >> a >> b;

  int sa = sqfree(a), sb = sqfree(b);

  if (sa == -1 && sb == -1 && a != b)
    cout << "full credit" << endl;
  else if (sa && sb && gcd(a, b) == 1)
    cout << "partial credit" << endl;
  else
    cout << "no credit" << endl;

  return 0;
}
