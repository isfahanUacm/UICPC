#include <bits/stdc++.h>
#include <functional>
using namespace std;

using u32 = unsigned;
using i64 = int64_t;
using u64 = unsigned int64_t;
using i128 = __int128;
using u128 = unsigned __int128;
using ld = long double;
using my_pair = pair<int, pair<int, int>>;

constexpr int INF32 = 1E9;
constexpr i64 INF64 = 1E18;
constexpr int MOD = 1e9 + 7;

#define sz(x) (int)x.size()
#define F first
#define S second

const int N = 2e5 + 1;
int cnt = 1;

void solve() {
    char s;
    int l, m, a;
    cin >> s >> l >> m >> a;

    string sent;
    sent.push_back(s);
    for (int i = 1; i < l; i++) {
        int u = sent.back() - 'a';
        u *= m;
        u += i * a;
        u %= 26;
        sent.push_back(char(u + 'a'));
    }

    vector<int> chars[26];
    for (int i = 0; i < l; i++) {
        chars[sent[i] - 'a'].push_back(i);
    }

    cout << "Case " << cnt++ << ": " << endl;
    int n;
    cin >> n;
    while (n--) {
        char s1;
        int l1, m1, a1;
        cin >> s1 >> l1 >> m1 >> a1;

        string pat;
        pat.push_back(s1);
        for (int i = 1; i < l1; i++) {
            int u = pat.back() - 'a';
            u *= m1;
            u += i * a1;
            u %= 26;
            pat.push_back(char(u + 'a'));
        }

        bool val = true;

        int j = 0;
        for (int i = 0; i < l1; i++) {
            int c = pat[i] - 'a';
            auto it = lower_bound(chars[c].begin(), chars[c].end(), j);
            if (it == chars[c].end()) {
                val = false;
                break;
            }
            j = (*it) + 1;
        }

        if (val) {
            cout << "BRAVO" << endl;
        } else {
            cout << "REPEAT" << endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}

