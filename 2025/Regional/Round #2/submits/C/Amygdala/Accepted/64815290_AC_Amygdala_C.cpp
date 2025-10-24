#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';

string bin_str(ll a)
{
    string otp;
    while(a)
    {
        otp.push_back('0' + (a % 2));
        a /= 2;
    }
    return otp;
}

int f(int a)
{
    if(a <= 31) return 32;
    else if(a <= 63) return 64;
    else return 128;
}

void solve()
{
  ll a, b; cin >> a >> b;
  a = abs(a); b = abs(b);

  string s1= bin_str(a), s2 = bin_str(b);
  int ta = s1.size();
  int tb = s2.size();

//  cout << ta << ' ' << tb << endl;

  if(ta + tb - 1 > 63)
  {
      if(ta > tb) ta = 127;
      else tb = 127;
  }
  else if(ta + tb - 1 > 31)
  {
      if(ta > tb) ta = 63;
      else tb = 63;
  }

  int tc = max(ta, tb);

  cout << f(ta) << '\n' << f(tb) << '\n' << f(tc);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }

//    for(int i=1; i<20; i++) cout << i << ':' << is_prime(i) << endl;
    return 0;
}