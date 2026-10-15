#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n)
#define sint(s) string (s); cin >> (s)
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n'
#define int ll
// #define endl '\n'

int how_many(int p, int l)
{
    int mul = p, otp = 1;
    while(mul <= l) mul *= p, otp++;

    return otp - 1;
}

vector<int> primes;

void solve()
{
    int n, m; cin >> n >> m ;
    int l = n + m - 1;

    cout << "YES\n";

    int num = 1;
    for(auto p : primes)
    {
        int hm = how_many(p, l);
        if(!hm) break;
        for(int i=0; i<hm; i++) num *= p;
    }
    // cout << "num = " << num << endl; return;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++) cout << num << ' ';
        cout << '\n';
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> hash(1000, true);
    for(int i=2; i<hash.size(); i++)
    {
        if(!hash[i]) continue;

        for(int j=i+i; j<hash.size(); j+= i) hash[j] = false;
        primes.push_back(i);
    }
    // for(int i=0; i<20; i++) cout  << primes[i] << ' '; cout << endl; return 0;
    // cout << primes.back() << endl; return 0;

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}