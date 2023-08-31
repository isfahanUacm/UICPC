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
const int N =  1e2 + 9;
vector<string> code[N];
string names[N];
int ans[N];

void rspace(string& l, string& l1) {
    int n = sz(l);
    char pch = ' ';
    F0R(i, n) {
        if (pch == ' ' && l[i] == ' ') continue;
        l1 += l[i];
        pch = l[i];
    }
    if (l1.back() == ' ') l1.pop_back();
}

void solve() {
    int n; cin >> n;
    string waste; getline(cin, waste);
    F0R(i, n) {
        string name; getline(cin, name);
        names[i] = name;
        while (true) {
            string line, line1 = ""; getline(cin, line);
            if (line == "***END***") break;
            rspace(line, line1);
            debug(line, line1);
            if (line1 != "") code[i].pb(line1);
        }
    }
    int i = 0;
    while (true) {
        string line, line1 = ""; getline(cin, line);
        if (line == "***END***") break;
        rspace(line, line1);
        debug(line, line1);
        if (line1 != "") {
            F0R(j, n) {
                if (sz(code[j]) > i && code[j][i] == line1) ans[j]++;
            }
            i++; 
        }
    }
    int mx = *max_element(ans, ans+n);
    if (mx == 0) {
        cout << 0 << nl;
        return;
    }
    cout << mx << ' ';
    F0R(i, n) {
        if (ans[i] == mx) {
            cout << names[i] << ' ';
        }
    }
    cout << nl;
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
