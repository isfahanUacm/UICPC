#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
//#define int long long
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
const int MAXN = 2e6 + 4;
vector<int> prms;
int is_prime[MAXN];
ll dp[MAXN];
int cnt[MAXN];
ll ans[MAXN];
void sieve() {
    dp[1] = 1;
    is_prime[0] = 0;
    is_prime[1] = 0;
    fill(is_prime, is_prime + MAXN, 1);
    is_prime[0] = 0;
    is_prime[1] = 0;
    for (int i = 2; i < MAXN; i++) {
        if (is_prime[i]) {
            prms.pb(i);
            cnt[i] = 1;
            dp[i] = 3;
        }
        for (int p : prms) {

            if (i * p >= MAXN) {
                break;
            }
            is_prime[i * p] = 0;
            if (i % p == 0) {
                cnt[i * p] = cnt[i] + 1;
                dp[i * p] = dp[i] / (2 * cnt[i] + 1) * (2 * cnt[p * i] + 1);
                break;
            }
            else {
                dp[i * p] += dp[i] * 3;
                cnt[p * i] = 1;
            }
        }
    }
    for (int i = 2; i < MAXN; i++) {
        ans[i] = (dp[i] - 1)/2 + ans[i-1];
    }
}
int main() {
    fast int tt;
    cin >> tt;
    sieve();
    while (tt--) {
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
}
