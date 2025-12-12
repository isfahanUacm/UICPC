#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
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
 
        step = i & 1 ? 2*step : -step;
        i++;
    }
 
    ll sig = step > 0 ? 1 : -1;
    X += sig*N;
 
    auto ok = X < L or X > R;
 
    if (not ok)
        return { "Nao", -1 };
 
    ll ans = Y - X;
 
    return { "Sim", ans };
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