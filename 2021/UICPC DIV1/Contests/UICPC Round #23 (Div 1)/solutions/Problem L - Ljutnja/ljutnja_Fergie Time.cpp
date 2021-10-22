#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pld pair<ld, ld>
#define watch(x) cout << #x << " : " << x << endl
const ll mod = 1e9 + 7;
const ll maxN = 200200;
string waste;



int main()
{
    ll m ,n;
    ll sum=0;
    cin >> m >> n;
    ll input;
    multiset <ll> candy;
    for (ll i=0;i<n;i++)
    {
        cin >> input;
        sum += input;
        candy.insert(input);
    }

    sum -= m;
    ll ans=0;
    ll t = 0;
    ll candy1;
    ll number = n;
    while(candy.size())
    {
       candy1 = *candy.begin();
       candy.erase(candy.begin());
        t = min(candy1,sum/number);
        sum -= t;
        t *= t;
        ans += t;
        number--;
     }

    cout << ans;
}
