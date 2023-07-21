#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pi pair<int, int>
#define pl pair<ll, ll>
#define F first
#define S second
#define vi vector<int>
#define pb push_back
#define pf push_front
#define nl '\n'
#define MOD 1000000007
#define MOD1 998244353
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define fastio() ios_base::sync_with_stdio(false);cin.tie(0);
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
/**************************************************************/
#ifdef LOCAL
#include "/home/mamad/debug.h"
#else
#define debug(...) 42
#define arrdebug(...) 42
#endif
/**************************************************************/

vector<ll> v1, v2;

void solve()
{
    ll a, b, x, y;
    cin >> a >> b;
    x = a, y = b;
    ll sq1 = sqrt(a) + 1, sq2 = sqrt(b) + 1;
    for (ll i = 2; i <= sq1; i++) {
        while (a % i == 0) {
            v1.pb(i);
            a /= i;
            if (a == 1) break;
        }
    }
    if (a != 1) v1.pb(a);

    for (ll i = 2; i <= sq2; i++) {
        while (b % i == 0) {
            v2.pb(i);
            b /= i;
        }
    }
    if (b != 1) v2.pb(b);
    v2.insert(v2.end(), all(v1));
    sort(all(v2));
    arrdebug(v1, 100);
    arrdebug(v2, 100);

    if (sz(v2) == 2 && x != y) cout << "full credit\n";
    else {
        ll pn = -1;
        for (int i = 0; i < sz(v2); i++) {
            if (v2[i] == pn) {
                cout << "no credit\n";
                return;
            }
            pn = v2[i];
        }
        cout << "partial credit\n";
    }
}

int32_t main()
{
    fastio();
    solve();
    
    #ifdef LOCAL
    cout << "____________________" << endl << endl;
    cout << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    
    return 0;
}