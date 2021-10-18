#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int n, logn=0;

void min_jmp(vector<vll> &T, int i, ll v0) {
    T[i][0] = v0;
    for (int b = 0; b < logn; ++b)
        T[i][b+1] = min(T[i][b], T[max(i-(1<<b), 0)][b]);
}

int prev_smaller(vector<vll> &T, int i, ll v) {
    for (int b = logn; b >= 0 && i >= 0; --b)
        if (T[i][b] >= v) i -= 1<<b;
    return max(i, -1);
}

int main(void) {
    scanf("%d", &n);
    while ((2<<logn) <= n) ++logn;
    
    vll a(n), a_sum(n+1);
    for (ll &x: a) scanf("%lld", &x);
    partial_sum(a.begin(), a.end(), a_sum.begin()+1);
    
    vector<vll> surplus(n+1, vll(logn+1)), deficit(n+1, vll(logn+1)), opt_glide(n+1, vll(logn+1));
    vll opt(n+1);
    for (int i = 1; i <= n; ++i) {
        opt[i] = max(a_sum[i]-1, 0LL);
        if (a[i-1] == 0) opt[i] = min(opt[i], opt[i-1]);
        int r = prev_smaller(surplus, i-1, a_sum[i]-i+1);
        if (r >= 0) {
            int l = prev_smaller(deficit, r-1, i-a_sum[i]), b = 0;
            while ((2<<b) < r-l) ++b;
            opt[i] = min(opt[i], 2*a_sum[i] - i - 1 + min(opt_glide[r][b],
                                                          opt_glide[l+(1<<b)][b]));
        }

        min_jmp(surplus, i, a_sum[i]-i);
        min_jmp(deficit, i, i-a_sum[i]);
        min_jmp(opt_glide, i, opt[i] - 2*a_sum[i] + i);
    }
    
    ll ans = 1LL<<60;
    for (int i = 1; i <= n; ++i)
        ans = min(ans, opt[i] + max(a_sum[n] - a_sum[i] - 1, 0LL));
    printf("%lld\n", ans);
    return 0;
}
