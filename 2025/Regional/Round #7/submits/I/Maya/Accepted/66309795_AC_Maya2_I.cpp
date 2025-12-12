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

bool check(string s) {
    string p = "uva";

    if (sz(p) < 3) {
        return false;
    }

    return s[0] == p[0] and s[1] == p[1] and s[2] == p[2];
}

void solve() {
    int n, m;
    cin >> m >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // if upper
            if (s[i][j] >= 'A' and s[i][j] <= 'Z') {
                s[i][j] = s[i][j] - 'A' + 'a';
            }
        }
    }
    int res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string s1 = "";
            int u = i, v = j;
            while (v < m) {
                s1 += s[u][v];
                v++;
            }

            string s2 = "";
            u = i, v = j;
            while (v >= 0) {
                s2 += s[u][v];
                v--;
            }

            string s3 = "";
            u = i, v = j;
            while (u < n and v < m) {
                s3 += s[u][v];
                u++;
                v++;
            }

            string s4 = "";
            u = i, v = j;
            while (u >= 0 and v >= 0) {
                s4 += s[u][v];
                u--;
                v--;
            }

            string s5 = "";
            u = i, v = j;
            while (u < n and v >= 0) {
                s5 += s[u][v];
                u++;
                v--;
            }

            string s6 = "";
            u = i, v = j;
            while (u >= 0 and v < m) {
                s6 += s[u][v];
                u--;
                v++;
            }

            string s7 = "";
            u = i, v = j;
            while (u < n) {
                s7 += s[u][v];
                u++;
            }

            string s8 = "";
            u = i, v = j;
            while (u >= 0) {
                s8 += s[u][v];
                u--;
            }

            if (check(s1)) res++;
            if (check(s2)) res++;
            if (check(s3)) res++;
            if (check(s4)) res++;
            if (check(s5)) res++;
            if (check(s6)) res++;
            if (check(s7)) res++;
            if (check(s8)) res++;
        }
    }

    cout << res << endl;
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

