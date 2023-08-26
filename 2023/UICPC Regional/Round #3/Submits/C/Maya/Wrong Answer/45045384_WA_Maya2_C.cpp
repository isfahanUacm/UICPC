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
const int maxn = 53;
double arr[maxn];

void solve() {
    int n;
    double mx = 0, t = 0;
    cin >> n;
    string str;
    fori (0, n) {
        cin >> str;
        t = 0;
        forj (0, n) {
            if (str[j] == '1' || str[j] == '.') t++;
            else if (str[j] == 'd') t += 0.5;
        }
        arr[i] = t;
        if (t > mx) mx = t;
    }

    fori (0, n) {
        if (arr[i] == mx) cout << i+1 << ' ';
    }
    cout << endll;
}

int main() {
    ios::sync_with_stdio(false);
		cin.tie(nullptr);
    //cout << fixed << setprecision(9);
    int T; cin >> T; while (T--)
    solve();

    return 0;
}