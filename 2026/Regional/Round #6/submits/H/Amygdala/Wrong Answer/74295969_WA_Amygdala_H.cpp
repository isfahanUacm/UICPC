#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<pair<int, int>>
#define vin(v) for(auto &x : v) cin >> x
#define vout(v) for(auto x : v) cout << x << ' '; cout << endl
#define int ll
// #define endl '\n'

int MOD = 104206969ll;

vi primes;
vi twins;

void solve()
{
    int n, k; cin >> n >> k;


    auto p_last = upper_bound(primes.begin(), primes.end(), n);
    auto twin_last = upper_bound(twins.begin(), twins.end(), n);

    if(k > 4) cout << "0";
    else if(k == 4)
    {
        cout << max(0ll ,(n-7)) % MOD;
    }
    else if(k == 3)
    {
        int ans = 0;
        for(int x=1; x<=n-5; x++)
        {
            auto t = upper_bound(twins.begin(), twin_last, n - x - 2);
            ans += (2 * (t - twins.begin())) % MOD;
        }

        cout << ans % MOD;
    }
    else if(k == 2)
    {
        int ans = 0;
        for(int x=1; x<=n-2; x++)
        {
            auto p = upper_bound(primes.begin(), p_last, n-x);
            ans += (p - primes.begin()) % MOD;
        }
        cout << ans % MOD;
    }
    else if(k == 1)
    {
        cout << n % MOD;
    }

    cout << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> hash(5e6 + 100, true);
    for(int i=2; i<hash.size(); i++)
    {
        if(!hash[i]) continue;

        primes.push_back(i);
        for(int j=i+i; j<hash.size(); j+=i) hash[j] = false;
    }
    for(int i=1; i<primes.size()-1; i++) if(primes[i+1] == primes[i]+2) twins.push_back(primes[i]);

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}