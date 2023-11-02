#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef DEBUG
#include "/home/mmd/debug.h"
#else
#define debug(x...)
#define arrdebug(x, s)
#define delay()
#define LINE
#define TIME
#endif


const int MOD = 1000000007;
//const int MOD = 998244353;
const char nl = '\n';
const int N = 1e2 + 9;
int g[N][N];
pi p[N][N];

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int n, m; // DON'T MAKE THEM IN MAIN
 
bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int ru(int x1, int y1, int x2, int y2) {
    memset(g, 0, sizeof g);
    int ans = abs(x1 - x2) + abs(y1 - y2);
    if (x1 > x2) swap(x1, x2);
    FOR(i, x1, x2+1) g[i][y1] = 1;
    if (y1 > y2) swap(y1, y2);
    FOR(i, y1, y2+1) g[x2][i] = 1;

    return ans;
}

int lu (int x1, int y1, int x2, int y2) {
    memset(g, 0, sizeof g);
    int ans = abs(x1 - x2) + abs(y1 - y2);
    if (y1 > y2) swap(y1, y2);
    FOR(i, y1, y2+1) g[x1][i] = 1;
    if (x1 > x2) swap(x1, x2);
    FOR(i, x1, x2+1) g[i][y2] = 1;

    return ans;
}

int bfs(int x1, int y1, int x2, int y2) {
    if (g[x1][y1] || g[x2][y2]) return -1;
    queue<pi> q;
    q.push(mp(x1, y1));

    while (!q.empty()) {
        int x = q.front().F, y = q.front().S;
        q.pop();
        F0R(i, 4) {
            int xx = x + dx[i], yy = y + dy[i];
            if (check(xx, yy) && g[xx][yy] == 0) {
                p[xx][yy] = mp(x, y);
                if (xx == x2 && yy == y2) return g[x][y] + 1;
                g[xx][yy] = g[x][y] + 1;
                q.push(mp(xx, yy));
            }
        }
    }

    return -1;
}

void solve() {
    cin >> n >> m, n++, m++;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    if (min(x1, x2) == min(x3, x4) && max(x1, x2) == max(x3, x4) &&
            min(y1, y2) == min(y3, y4) && max(y1, y2) == max(y3, y4)) {
        if ((min(x1, x2) == 0 && max(x1, x2) == n-1) || (min(y1, y2) == 0 && max(y1, y2) == m-1)) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        int ans = 2 * (abs(x1 - x2) + abs(y1 - y2)) + 4;
        cout << ans << nl;
        return;
    }
    
    int mn = 1e9;
    int dis1 = ru(x1, y1, x2, y2);
    int dis2 = bfs(x3, y3, x4, y4);
    if (dis2 != -1) cmin(mn, dis1+dis2);

    dis1 = lu(x1, y1, x2, y2);
    dis2 = bfs(x3, y3, x4, y4);
    if (dis2 != -1) cmin(mn, dis1+dis2);

    dis1 = ru(x3, y3, x4, y4);
    dis2 = bfs(x1, y1, x2, y2);
    if (dis2 != -1) cmin(mn, dis1+dis2);

    dis1 = lu(x3, y3, x4, y4);
    dis2 = bfs(x1, y1, x2, y2);
    if (dis2 != -1) cmin(mn, dis1+dis2);

    memset(g, 0, sizeof g);
    g[x3][y3] = 1, g[x4][y4] = 1;
    dis1 = bfs(x1, y1, x2, y2);
    if (dis1 != -1) {
        memset(g, 0, sizeof g); 
        int x = x2, y = y2, xx, yy;
        while (x != x1 || y != y1) {
            g[x][y] = 1;
            xx = p[x][y].F, yy = p[x][y].S;
            x = xx, y = yy;
        }
        g[x][y] = 1;
    }
    dis2 = bfs(x3, y3, x4, y4);
    if (dis1 != -1 && dis2 != -1) cmin(mn, dis1+dis2);

    memset(g, 0, sizeof g);
    g[x1][y1] = 1, g[x2][y2] = 1;
    dis1 = bfs(x3, y3, x4, y4);
    if (dis1 != -1) {
        memset(g, 0, sizeof g);
        int x = x4, y = y4, xx, yy;
        while (x != x3 || y != y3) {
            g[x][y] = 1;
            xx = p[x][y].F, yy = p[x][y].S;
            x = xx, y = yy;
        }
        g[x][y] = 1;
    }
    dis2 = bfs(x1, y1, x2, y2);
    if (dis1 != -1 && dis2 != -1) cmin(mn, dis1+dis2);
    
    if (mn == 1e9) cout << "IMPOSSIBLE\n";
    else cout << mn << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
        LINE
    }
    TIME

    return 0;
}
