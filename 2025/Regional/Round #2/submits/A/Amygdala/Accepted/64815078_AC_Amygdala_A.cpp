#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';

void solve()
{
  int n , k ;
  char c;
  cin >> n >> k >> c;
  if(c == 'L'){
      cout << (k+1)/2 << ' ' << (k+1)/2 << ' ' << n-k << endl;
  }
  else{
      cout << k-1 << ' ' << (n-k+2)/2 << ' ' << (n-k+2)/2  << endl;
  }
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