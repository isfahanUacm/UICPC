#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define int long long
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
using pll = pair<long long, long long>;
using ull = unsigned long long;
#define ff first
#define all(x) (x).begin(), (x).end()
#define ss second
#define MP make_pair
#define pb push_back
#define pf push_front
#define MOD 998244353
#define set_dec(x) cout << fixed << setprecision(x);
#define endl '\n'
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
ll dp1[MAXN];
ll dp2[MAXN];

void dfs(int u, int p) {
    ll k = 1;
    bool fl = false;
    for (int v : adj[u]) {
        if (v != p) {
            fl = true;
        }
    }
    if (!fl) {
        dp2[u] = 1;
        dp1[u] = 1;
    }
    else {
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u);
                dp2[u] *= (dp1[v] + dp2[v]);
                dp2[u] %= MOD;

            }
        }
    }
}

int sumi(int n) {
    return n*(n+1)/2;
}
int32_t main()
{
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin>>n >> k;
        int a[n+1];
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        vector<int> lis;
        int sum=0;
        for (int i=1; i<=n; i++) {
            sum+=a[i];
            int ans=0;
            if (lis.size()==0) {
                lis.pb(a[i]);
            }
            else {
                if (lis.back()<a[i]) {
                    lis.pb(a[i]);
                }
                else {
                    auto it=upper_bound(lis.begin(), lis.end(), a[i]);
                    if (it!=lis.end()) *it=a[i];
                }
            }
            if (lis.size()>lis.back()) {
                ans+=sumi(lis.size()+k-1)-sumi(lis.size()-1);
            }
            else {
                ans+=k*lis.size();
            }
            cout << sum+ans << ' ';
        }
        cout << endl;
    }
}
