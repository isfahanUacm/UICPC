#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define MOD 998244353

ll poww(ll a, ll b) {
    if (b == 0)return 1;
    ll ans = poww(a, b / 2);
    ans = (ans * ans) % MOD;
    if (b % 2 == 1)
        ans = (ans * a) % MOD;
    return ans;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(n);
    vector<bool> t(n);
    vector<int> s(m+1,0);
    ll f = 0;
    ll sec = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        t[i] = 0;

        if (s[a[i]] < k) {
            s[a[i]]++;
            t[i] = 1;
            f++;
        }
    }

    for (int i = 0; i < n; i++) {
        if ((s[b[i]] < k) && (!t[i])) {
            s[b[i]]++;
            sec++;
        }
    }

    cout << f << ' ' << sec;

}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
        if (t != 0)
            cout << endl;
    }
}

