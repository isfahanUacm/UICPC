#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = int64_t;
using u64 = unsigned int64_t;
using i128 = __int128;
using u128 = unsigned __int128;
using ld = long double;

constexpr int INF32 = 1E9;
constexpr i64 INF64 = 1E18;
constexpr int MOD = 1e9 + 7;

#define sz(x) (int)x.size()
#define F first
#define S second

const int N = 2e5 + 1;

struct KMP
{
    vector<int> s, t;
    int n, m, k;
    vector<int> p, ans;

    KMP(vector<int> s_, vector<int> t_)
    {
        s = s_, t = t_, n = sz(s), m = sz(t), p.assign(m + 1, 0);
    }

    void fill_p()
    {
        p[0] = -1, k = 0;
        for (int i = 2; i <= m; i++)
        {
            while (k != -1 and t[k] != t[i - 1])
                k = p[k];
            p[i] = ++k;
        }
    }

    void match()
    {
        fill_p();
        k = 0;
        for (int i = 0; i < n; i++)
        {
            while (k != -1 and t[k] != s[i])
                k = p[k];
            k++;
            if (k == m)
                ans.push_back(i - m + 1), k = p[k];
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> u(n), v(m);

    int mn1 = 1e6, mn2 = 1e6;
    for (int i = 0; i < n; i++) {
        cin >> u[i];
        mn1 = min(mn1, u[i]);
    }

    for (int i = 0; i < m; i++) {
        cin >> v[i];
        mn2 = min(mn2, v[i]);
    }

    for (int i = 0; i < n; i++) {
        u[i] -= mn1;
    }

    for (int i = 0; i < n; i++) {
        u.push_back(u[i]);
    }
    
    for (int i = 0; i < m; i++) {
        v[i] -= mn2;
    }

    KMP kmp(u, v);
    kmp.match();

    vector<int> ans;
    for (int i : kmp.ans) {
        if (i < n) {
            ans.push_back(i);
        }
    }

    if (sz(ans)) {
        cout << (mn2 - mn1 + 10000) % 10000 << " " << sz(ans) << endl;    
    } else {
        cout << "0 0" << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin >> t;

    while (t--)
        solve();

    return 0;
}

