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
int mark[N][N];
int h, w;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int n, m; // DON'T MAKE THEM IN MAIN
 
bool check(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w;
}

void solve() {
    cin >> w >> h;	
    F0R(i, h) F0R(j, w) cin >> g[i][j];
    int x1=0, y1=0;
    F0R(i, h) F0R(j, w) if (g[i][j] == 'P') { x1 = i; y1 = j; }
    queue<pi> q;
    q.push(mp(x1, y1));
    ll ans = 0;
    while (!q.empty()) {
        int xx = q.front().F, yy = q.front().S;
        q.pop();
        bool f = true;
        F0R(i, 4) {
            int x = xx+dx[i], y = yy+dy[i];
            if (check(x, y) && g[x][y] == 'T') f = false;
        }
        if (f) {
            F0R(i, 4) {
                int x = xx+dx[i], y = yy+dy[i];
                if (!mark[x][y] && check(x, y)) {
                    if (g[x][y] == '.') q.push(mp(x, y)), mark[x][y] = 1;
                    else if (g[x][y] == 'G') {
                        q.push(mp(x, y));
                        mark[x][y] = 1;
                        ans++;
                    }
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
