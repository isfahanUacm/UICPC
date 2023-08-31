/**
 * created by: poconut(MPouya)
 */
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MOD1 998244353
#define nl "\n"
#define INF 2e9
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ar array
#define lb lower_bound
#define ub upper_bound
#define tostr to_string
typedef string str; typedef long double ld; typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl; typedef pair<int, int> pi; typedef pair<ll, ll> pl; typedef vector<pi> vpi; typedef vector<pl> vpl;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#ifdef ONPC
#include "/home/pouya/cp.cpp"
#else
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define debug(...)
#define arrdebug(...)
#define delay()
#define LINE
#define TIME
#endif
/*******************************************************************************/

void solve() {
    int n;
    cin >> n;
    vector<pair<int, str>> names;
    vector<vector<string>> vc;
    string name;

    for (int i=0; i<n; i++) {
        cin >> name;
        names.pb({0, name});
        string line, line2 = "";
        vector<str> tmp;
        cin.ignore();
        while (true) {
            getline (cin, line);
            if (line == "***END***") break;
            line2 = "";
            for (char c : line) if (c != ' ') line2 += c;
            tmp.pb(line2);
        }
        vc.push_back(tmp);
    }

    vector<str> code;
    string line, line2 = "";
    while (true) {
        getline (cin, line);
        if (line == "***END***") break;
        line2 = "";
        for (char c : line) if (c != ' ') line2 += c;
        code.pb(line2);
    }

    for (int i=0; i<sz(vc); i++) {
        auto f = vc[i];
        int j=0, c=0, mx = 0;
        for (str s: f) {
            if (j<sz(code) and s==code[j++]) {
                c++;
            } else {
                c = 0;
            }
            mx = max(mx, c);
        }
        names[i].ff = mx;
    }
    sort(all(names));
    int x = names.back().ff;
    cout << x;
    if (x==0) {
        cout << nl;
        return;
    }
    for (int i=0; i<names.size(); i++) {
        if (names[i].ff==x) {
            cout << ' ' <<  names[i].ss;
        }
    } cout << nl;


}
int main() {
    fastio();
	int T = 1;
	//cin >> T;
	while (T--) {
        solve();
        LINE
	}
    TIME
    return 0;
}


