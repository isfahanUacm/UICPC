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

vi k_is_2(1e7 + 10, 0), k_is_3(1e7 + 10, 0);
vi sum2(k_is_2.size()), sum3(k_is_3.size());

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
        // for(int x=1; x<=n-5; x++)
        // {
        //     auto t = upper_bound(twins.begin(), twin_last, n - x - 2);
        //     ans += (2 * (t - twins.begin())) % MOD;
        // }

        ans = 2 * sum3[n-3];
        cout << ans % MOD;
    }
    else if(k == 2)
    {
        int ans = 0;
        // for(int x=1; x<=n-2; x++)
        // {
        //     auto p = upper_bound(primes.begin(), p_last, n-x);
        //     ans += (p - primes.begin()) % MOD;
        // }

        ans = sum2[n-1];
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

    vector<bool> hash(1e7 + 10, true);
    for(int i=2; i<hash.size(); i++)
    {
        if(!hash[i]) continue;

        primes.push_back(i);
        for(int j=i+i; j<hash.size(); j+=i) hash[j] = false;
    }
    for(int i=1; i<primes.size()-1; i++) if(primes[i+1] == primes[i]+2) twins.push_back(primes[i]);

    int point = 0;
    k_is_2[1] = 0;
    for(int i=2; i<k_is_2.size()-1; i++)
    {
        k_is_2[i] = k_is_2[i-1];
        if(point < primes.size() && primes[point] == i) point++, k_is_2[i]++;
        k_is_2[i] %= MOD;
    }

    // cout << "HERE" << endl;

    point = 0;
    k_is_3[1] = 0;
    for(int i=2; i<k_is_3.size()-1; i++)
    {
        k_is_3[i] = k_is_3[i-1];
        if(point < twins.size() && twins[point] == i) point++, k_is_3[i]++;
        k_is_3[i] %= MOD;
    }

    for(int i=1; i<sum2.size(); i++) sum2[i] = (sum2[i-1] + k_is_2[i]) % MOD;
    for(int i=1; i<sum3.size(); i++) sum3[i] = (sum3[i-1] + k_is_3[i]) % MOD;

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}