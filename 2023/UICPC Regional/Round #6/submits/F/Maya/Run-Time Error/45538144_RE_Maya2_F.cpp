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
const int maxn = 2e4+9;
bool grid[maxn][maxn];

void solve() {
	int x, y;
	cin >> x >> y;
	fori (0, x) {
		forj (0, y) {
			grid[i][j] = false;
		}
	}
	int ver[4] = {4, 3, 2, 1};
	int hor[4] = {2, 1, 4, 3};
	int i = 1, j = 1;
	int dir = 1;
	ll cnt = 0;
	while (true) {
		if (!grid[i][j]) cnt++;
		grid[i][j] = true;

		if (dir == 1) { i++; j++; }
		else if (dir == 2) { i--; j++; }
		else if (dir == 3) { i--; j--; }
		else { i++; j--; }

		if (i == 0 || i == x-1) {
			if (j == 0 || j == y-1) break;
			dir = hor[dir-1];
		}
		else if (j == 0 || j == y-1) {
			if (i == 0 || i == x-1) break;
			dir = ver[dir-1];
		}
	}
	cout << cnt+2 << endll;
}

int main() {
    ios::sync_with_stdio(false);
		cin.tie(nullptr);
	//cout << fixed << setprecision(4);
	int T; cin >> T; while (T--)
    solve();

    return 0;
}