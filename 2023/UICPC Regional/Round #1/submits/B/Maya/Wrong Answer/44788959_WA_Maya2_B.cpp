#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pi pair<int, int>
#define pl pair<ll, ll>
#define F first
#define S second
#define vi vector<int>
#define vl vector<ll>
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
#define debug(...) 
#define arrdebug(...) 
#define delay() 
#define LINE 
#define TIME 
#endif
/**************************************************************/

const int N = 2e5 + 9;
int a[N], l[N], h[N];

//point_update + range_query  //range_update + point_query
//0-indexed _ range[l, r]
template <class T> 
struct BIT { 
    vector<T> bit;
    int n;
    
    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    BIT(T const a[], int n) : BIT(n) {  //for point update -> O(n)
        for (int i = 0; i < n; i++) {
            bit[i] += a[i];
            int r = i | (i + 1);
            if (r < n) bit[r] += bit[i];
        }
    }
    void upd(int i, T val) {
        if (i < 0) return;
        for (; i < n; i = i | (i + 1)) bit[i] += val;
    }
    void upd(int l, int r, T val) {
        upd(l, val);
        upd(r + 1, -val);
    }
    T query(int r) {
        T ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
        return ret;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};


void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    BIT<int> bit1(n);
    BIT<int> bit2(n);
    for (int i = 0; i < n; i++) {
        l[i] = bit1.query(a[i] + 1, n);
        bit1.upd(a[i], 1);
    }
    for (int i = n - 1; i >= 0; i--) {
        h[i] = bit2.query(0, a[i] - 1);
        bit2.upd(a[i], 1);
    }
    arrdebug(l, n); arrdebug(h, n);
    for (int i = 0; i < n; i++) {
        if (l[i] != -1 && h[i] != -1) ans += 1ll * l[i] * h[i];
    }

    cout << ans << nl;
}

int32_t main()
{
    fastio();
    solve();
    
    #ifdef LOCAL
    LINE
    TIME
    #endif
    
    return 0;
}