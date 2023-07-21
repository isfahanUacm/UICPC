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

const int N = 1e3 + 9;
int arr[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n, greater<int>());
    ll sum = 0;
    for (int i = 0; i < n / 2; i++) sum += arr[i];
    for (int i = n / 2; i < n; i++) sum += arr[i] / 2;
    cout << sum << nl;
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