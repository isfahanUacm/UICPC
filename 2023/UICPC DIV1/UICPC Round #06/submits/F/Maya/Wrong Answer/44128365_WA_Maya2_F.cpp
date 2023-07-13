/**
 * created by: poconut(MPouya)
 */
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MOD1 998244353
#define INF 2e9
#define nl " \n"
#define pb push_back
#define pf push_front
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long double ld; typedef pair<int, int> pii; typedef long long ll; typedef unsigned long long ull; typedef long double ld;
#ifdef ONPC
#define fastio()
#define arrdebug(x, s) cout<< #x << ": ";_print(x, s); cout << endl;
#define debug(x) cout << #x <<": "; _print(x); cout << endl;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#else
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define debug(x)
#define arrdebug(x, s)
#endif
void _print(const int& t) {cout << t;} void _print(const ll& t) {cout << t;} void _print(const char& t) {cout << t;} void _print(const string& t) {cout << t;} void _print(const ld& t) {cout << t;} void _print(const double& t) {cout << t;}
template <class T, class V> void _print(const pair<T, V>& p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}";}
template <class T> void _print(const vector<T>& v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set<T>& v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(const multiset<T>& v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(const map<T, V>& v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(const T& a, int s) { cout << "[ "; for (auto i: a) { if(!s--) break;_print(i); cout << " "; } cout << "]"; }
/*******************************************************************************/

int xt, yt;
int w, p;
vector<pair<pii, pii>> walls;
vector<pair<pii, pii>> pirates;

struct pt {
    long long x, y;
    pt() {}
    pt(long long _x, long long _y) : x(_x), y(_y) {}
    pt operator-(const pt& p) const { return pt(x - p.x, y - p.y); }
    long long cross(const pt& p) const { return x * p.y - y * p.x; }
    long long cross(const pt& a, const pt& b) const { return (a - *this).cross(b - *this); }
};

ld dis(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
}
ld deg(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2-x1)*(x3-x1)+(y2-y1)*(y3-y1);
}
int sgn(const long long& x) { return x >= 0 ? x ? 1 : 0 : -1; }

bool inter1(long long a, long long b, long long c, long long d) {
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}

bool check_inter(const pt& a, const pt& b, const pt& c, const pt& d) {
    if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
    return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) &&
           sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}
/*
bool intersect(int w1x, int w1y, int w2x, int w2y, int x1, int y1, int xt, int yt) {
    if (

}
*/

bool ok(pair<pii, pii> p) {
    bool ans = false;
    ld r = dis(p.ff.ff, p.ff.ss, p.ss.ff, p.ss.ss);
    ld dist = dis(p.ff.ff, p.ff.ss, xt, yt);
    if (dist <= r && deg(p.ff.ff, p.ff.ss, p.ss.ff, p.ss.ss, xt, yt)>=0) {
        ans = true;
        for (auto x: pirates) {
            if (x.ff.ff == p.ff.ff && x.ff.ss == p.ff.ss) continue;
            if (deg(p.ff.ff, p.ff.ss, p.ss.ff, p.ss.ss, xt, yt)==
                    dis(p.ff.ff, p.ff.ss, x.ff.ff, x.ff.ss)*dis(p.ff.ff, p.ff.ss, xt, yt)) {
                ans = false;
                break;
            }
        }
        for (auto x: walls) {
            struct pt w1, w2, pp, t;
            w1.x = x.ff.ff;
            w1.y = x.ff.ss;
            w2.x = x.ss.ff;
            w2.y = x.ss.ss;
            pp.x = p.ff.ff;
            pp.y = p.ff.ss;
            t.x = xt;
            t.y = yt;

            if (check_inter(w1, w2, pp, t)) {
                ans = false;
                break;
            }
            /*
            */
        }
    }
    return ans;
}

int solve() {
    cin >> w >> p;
    cin >> xt >> yt;
    walls.resize(w);
    pirates.resize(p);

    for (int i=0; i<w; i++) {
        cin >> walls[i].ff.ff >> walls[i].ff.ss >> walls[i].ss.ff >> walls[i].ss.ss;
    }

    for (int i=0; i<p; i++) {
        cin >> pirates[i].ff.ff >> pirates[i].ff.ss >> pirates[i].ss.ff >> pirates[i].ss.ss;
    }

    for (auto pi: pirates) {
        if (ok(pi)) {
            cout << "visible" << nl;
        } else {
            cout << "not visible" << nl;
        }
    }
    /*
    */


	return 0;
}

int main() {
    fastio();

	int T = 1;
	//cin >> T;
	while (T--) {
		if (solve()) {
			break;
		}
		#ifdef ONPC
        cout<<"__________"<<endl;
		#endif
	}
	#ifdef ONPC
    cout<<endl<<"finished in "<<clock()*1.0/CLOCKS_PER_SEC<<" sec"<<endl;
	#endif
    return 0;
}


