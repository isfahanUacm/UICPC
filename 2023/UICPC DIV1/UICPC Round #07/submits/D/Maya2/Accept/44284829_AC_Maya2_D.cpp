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

const int N = 3e5 + 9;
int a[N], b[N], sh[N];
multiset<int> s1, s2;

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
        s1.insert(a[i]);
        s2.insert(b[i]);
        while ((*s1.begin()) == (*s2.begin())) {
            s1.erase(s1.begin());
            s2.erase(s2.begin());
            if (sz(s1) == 0) {
                sh[i] = 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << ' ';
        if (i != n - 1 && sh[i]) cout << "# ";
    }
    cout << nl;
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