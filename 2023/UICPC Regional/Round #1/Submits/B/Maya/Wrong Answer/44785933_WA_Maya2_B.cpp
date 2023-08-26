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
// lower_bound -> greater than or equal
// upper_bound -> greater than
const int maxn = 1e5+9;
int arr[maxn];

void solve() {
    int n;
    cin >> n;
    fori (0, n) cin >> arr[i];

    ll cnt = 0;
    fori (0, n) {
        ll t=0;
        forj (i+1, n) {
            if (arr[j] < arr[i]) t++;
        }
        // 2 from t
        cnt += ((t-1) * t) / 2;
    }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    //cout << fixed << setprecision(9);
    //int T; cin >> T; while (T--)
    solve();

    return 0;
}