// l a s h v

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define endll '\n'
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fori(x, u) for (int i = x; i < u; ++i)
#define forj(x, u) for (int j = x; j < u; ++j)
#define sortv(a) sort(a.begin(), a.end())
#define ES cout << "YES\n"
#define NO cout << "NO\n"
#define sep() cout << "------------------------------------------------------\n"
#define print_map(mp) for (auto x : mp) cout << x.first << ": " << x.second << endll
#define print_vec(vc) for (auto x : vc) cout << x << ' '; cout << endll
// lower_bound -> greater than or equal
// upper_bound -> greater than
const int maxn = 2e5+9;
map<string, double> mp2;
string king;

double dfs(string child, map<string, pair<string, string>>&  mp) {
	if (child == king) return 1.0;
	if (mp2[child] != -1) return mp2[child];

	if (!mp.count(child)) return 0.0;
	else {
		mp2[child] = dfs (mp[child].first, mp)/2 +
				dfs (mp[child].second, mp)/2;
		return mp2[child];
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	cin >> king;
	map<string, pair<string, string>> mp;
	string child, p1, p2;
	fori (0, n) {
		cin >> child >> p1 >> p2;
		mp2[child] = -1; mp2[p1] = -1; mp2[p2] = -1;
		mp[child] = {p1, p2};
	}
	string maxb;
	double mxb = 0;
	fori (0, m) {
		cin >> child;
		double tmp = dfs (child, mp);
		if (tmp > mxb) {
			mxb = tmp;
			maxb = child;
		}
	}
	cout << maxb << endll;
}

int main() {
    ios::sync_with_stdio(false);
		cin.tie(nullptr);
	//cout << fixed << setprecision(4);
	//int T; cin >> T; while (T--)
    solve();

    return 0;
}