#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define F first
#define S second
#define pii pair<int, int>
#define piii pair<char, int>
#define vi vector<int>
#define vii vector<pii>
#define pb push_back
#define pf push_front
#define ins insert
#define pbd pop_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define wall cout << '\n' \
                  << "--------------------------------" << '\n';
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define filin                          \
    freopen("problem.in", "r", stdin); \
    freopen("problem.out", "w", stdout);

const int N = 2e5 + 9, MOD = 1e9 + 7, SQ = 548, LG = 20, INF = LLONG_MAX;

ll pw(ll a, ll b) { return b == 0 ? 1LL : (pw(a * a, b / 2) * (b % 2 == 0 ? 1LL : a)); }
ll pwm(ll a, ll b) { return b == 0 ? 1LL : (pw(a * a % MOD, b / 2) % MOD * (b % 2 == 0 ? 1LL : a)) % MOD; }

auto solve(ll N, ll Y) -> pair<string, ll>
{
    ll step = 1, L = 0, R = 0, X = 0;
    int i = 0;

    while (llabs(step) < N)
    {
        N -= llabs(step);
        X += step;

        L = min(L, X);
        R = max(R, X);

        step = i & 1 ? 2 * step : -step;
        i++;
    }

    ll sig = step > 0 ? 1 : -1;
    X += sig * N;

    auto ok = X < L or X > R;

    if (not ok)
        return {"Nao", -1};

    ll ans = Y - X;

    return {"Sim", ans};
}

int main()
{
    ios::sync_with_stdio(false);

    ll N, Y;
    cin >> N >> Y;

    auto [ans, X] = solve(N, Y);

    cout << ans << '\n';

    if (ans == "Sim")
        cout << X << '\n';

    return 0;
}