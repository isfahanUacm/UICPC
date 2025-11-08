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
int r, c;
int is, js, ie, je;
vector<string> s;
vector<vector<vector<bool>>> vis;

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

bool valid(int i, int j) {
    return i >= 0 && i < r && j >= 0 && j < c;
}

void dfs(int i, int j, int k) {
    if (vis[i][j][k]) {
        return;
    }

    vis[i][j][k] = true;

    int u, v;
    if (valid(i + dx[(k - 1 + 4) % 4], j + dy[(k - 1 + 4) % 4]) && s[i + dx[(k - 1 + 4) % 4]][j + dy[(k - 1 + 4) % 4]] == '0') {
        dfs(i + dx[(k - 1 + 4) % 4], j + dy[(k - 1 + 4) % 4], (k - 1 + 4) % 4);
    } else if (valid(i + dx[k], j + dy[k]) && s[i + dx[k]][j + dy[k]] == '0') {
        dfs(i + dx[k], j + dy[k], k);
    } else if (valid(i + dx[(k + 1) % 4], j + dy[(k + 1) % 4]) && s[i + dx[(k + 1) % 4]][j + dy[(k + 1) % 4]] == '0') {
        dfs(i + dx[(k + 1) % 4], j + dy[(k + 1) % 4], (k + 1) % 4);
    }
}

void solve() {
    cin >> r >> c;
    cin >> is >> js >> ie >> je;

    s.assign(r, "");
    for (int i = 0; i < r; i++) {
        cin >> s[i];
    }

    is--, js--, ie--, je--;
    vis.assign(r, vector<vector<bool>>(c, vector<bool>(4, false)));
    dfs(is, js, 1);

    int ans = vis[ie][je][0] + vis[ie][je][1] + vis[ie][je][2] + vis[ie][je][3];
    cout << (ans > 0) << endl;
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

