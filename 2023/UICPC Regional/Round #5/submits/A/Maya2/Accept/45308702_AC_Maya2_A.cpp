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
const int maxn = 1e6+3;
double arr[maxn];
double bb[maxn];

void solve() {
	int p, a, b, c, d, n;
	cin >> p >> a >> b >> c >> d >> n;
	for (int k = 1; k <= n; ++k) {
		arr[k] = p * (sin(a*k + b) + cos(c*k + d) + 2);
	}
	double koch = arr[1];
	fori (2, n+1) {
		if (arr[i] < koch) koch = arr[i];
	}
	bb[n] = arr[n];
	for (int i = n-1; i > 0; --i) {
		bb[i] = min (arr[i], bb[i+1]);
	}
	koch = arr[1] - bb[1];
	fori (1, n+1) {
		if (koch < arr[i] - bb[i]) koch = arr[i] - bb[i];
	}
	cout << koch << endll;
}

int main() {
    ios::sync_with_stdio(false);
		cin.tie(nullptr);
    cout << fixed << setprecision(6);
    //int T; cin >> T; while (T--)
    solve();

    return 0;
}