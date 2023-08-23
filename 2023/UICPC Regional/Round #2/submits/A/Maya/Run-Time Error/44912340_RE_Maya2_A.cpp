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
#define print_arr(arr, n) fori (0, n) cout << arr[i] << ' '; cout << endll
// lower_bound -> greater than or equal
// upper_bound -> greater than
const int maxn = 1e4+3;
string arr[maxn];

void solve() {
	int n;
	cin >> n;
	set<string> st[10];
	set<string> st2;
	fori (0, n) {
		cin >> arr[i];
		st[arr[i].size()].insert(arr[i]);
		if (st2.find(arr[i]) != st2.end()) {
			NO;
			return;
		}
		else st2.insert(arr[i]);
	}
	fori (0, n) {
		string tmp = "";
		forj (0, arr[i].size()-1) {
			tmp += arr[i][j];
			if (st[tmp.size()].find(tmp) != st[tmp.size()].end()) {
				NO;
				return;
			}
		}
	}
	ES;
}

int main() {
    ios::sync_with_stdio(false);
		cin.tie(nullptr);
    //cout << fixed << setprecision(9);
    int T; cin >> T; while (T--)
    solve();

    return 0;
}