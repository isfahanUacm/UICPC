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
const int N = 50 + 9;
char g[N][N];
pi r[N][N][N];
int mark[N][N];


int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int n, m; // DON'T MAKE THEM IN MAIN
 
bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solve() {
    memset(mark, -1, sizeof mark);
    cin >> n >> m;
    F0R(i, n) F0R(j, m) cin >> g[i][j];


    F0R(j, m) {
        F0R(i, n) {
            int x = i+dx[0], y = j+dy[0]; 
            if (check(x, y)) {
                if (g[i][j] == g[x][y]) r[i][j][0] = r[x][y][0];
                else r[i][j][0] = mp(x, y);
            }
            else r[i][j][0] = mp(-1, -1);
        }
        F0Rd(i, n) {
            int x = i+dx[1], y = j+dy[1];
            if (check(x, y)) {
                if (g[i][j] == g[x][y]) r[i][j][1] = r[x][y][1];
                else r[i][j][1] = mp(x, y);
            }
            else r[i][j][1] = mp(-1, -1);
        }
    }
    F0R(i, n) {
        F0R(j, m) {
            int x = i+dx[2], y = j+dy[2]; 
            if (check(x, y)) {
                if (g[i][j] == g[x][y]) r[i][j][2] = r[x][y][2];
                else r[i][j][2] = mp(x, y);
            }
            else r[i][j][2] = mp(-1, -1);
        }
        F0Rd(j, m) {
            int x = i+dx[3], y = j+dy[3];
            if (check(x, y)) {
                if (g[i][j] == g[x][y]) r[i][j][3] = r[x][y][3];
                else r[i][j][3] = mp(x, y);
            }
            else r[i][j][3] = mp(-1, -1);
        }
    }

    string s; cin >> s;
    int ans = sz(s) + 1;
    auto last = unique(all(s));
    s.erase(last, s.end());
    s += '*';
    int ss = sz(s);
    debug(s, ss);

    deque<pair<pi, pi>> q;
    if (g[0][0] != s[0]) {
        q.pb(mp(mp(0, 0), mp(0, 0))); 
        mark[0][0] = 0;
    }
    else {
        q.pb(mp(mp(0, 0), mp(0, 1)));
        mark[0][0] = 1;
    }

    while (!q.empty()) {
        int x = q.front().F.F, y = q.front().F.S, l = q.front().S.F, c = q.front().S.S;
        q.pop_front();
        F0R(i, 4) {
            int xx = r[x][y][i].F, yy = r[x][y][i].S;
            if (xx != -1 && mark[xx][yy] < c) {
                if (g[xx][yy] == s[c]) {
                    if (g[xx][yy] == g[x][y]) q.push_front(mp(mp(xx, yy), mp(l, c+1))); 
                    else q.pb(mp(mp(xx, yy), mp(l+1, c+1))); 
                    mark[xx][yy] = c+1;
                    if (c+1 == ss) {
                        ans += l+1;
                        cout << ans << nl;
                        return;
                    }
                }
                else {
                    if (g[xx][yy] == g[x][y]) q.push_front(mp(mp(xx, yy), mp(l, c))); 
                    else q.pb(mp(mp(xx, yy), mp(l+1, c))); 
                    mark[xx][yy] = c;
                }
            }
        }
    }
    cout << ans << nl;
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
