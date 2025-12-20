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
bool tst = true;

void solve() {
    int n;
    cin >> n;

    if (n == 0) {
        tst = false;
        return;
    }

    string s, t;
    cin >> s >> t;

    int u = 0, v = 0;
    for (char c : s) {
        u += (c == 'a');
    }

    for (char c : t) {
        v += (c == 'a');
    }

    if (u != v) {
        cout << "no" << endl;
        return;
    }

    int k = 0;

    bool valid = true;
    string com;
    for (int i = 0; i < n and k < 10000 and valid; i++) {
        if (s[i] != t[i]) {
            com.push_back(s[i] - 'a' + 'A');
            k += 1;
            for (int j = 0; j < n; j++) {
                if (s[j] == s[i]) {
                    int z = j;
                    while (z < n and s[z] == s[i]) {
                        z += 1;
                    }

                    if (z < n) {
                        swap(s[z], s[j]);
                    } else {
                        valid = false;
                    }

                    break;
                }
            }
            i = -1;
        }
    }

    bool same = true;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            same = false;
        }
    }

    cout << (same ? "yes" : "no") << endl;
    if (same) {
        cout << com << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (tst)
        solve();

    return 0;
}