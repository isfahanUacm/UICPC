#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define endll '\n'
#define pii pair<int, int>
#define foor(x, u) for (int i = x; i < u; ++i)
#define sv(a) sort(a.begin(), a.end())
#define sa(a, n) sort(a, a+n)
const int maxn = 100;

void solve() {
    int n, m, tmp;
    cin >> n >> m;
    vector<bitset<maxn>> arr(n);
    foor (0, n) arr[i][i] = 0;
    foor (0, m) {
        cin >> tmp;
        arr[tmp-1][tmp-1] = 1;
    }

    for (int di = 1; di < n; ++di) {
        for (int i = 0; i < n-di; ++i) {
            int j = i +  di;
            if (arr[i][j-1] == 1 || arr[i+1][j] == 1) 
                arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }

    int ans = 0;
    foor (0, n) {
        for (int j = i; j < n; ++j) {
            if (arr[i][j]) ans++;
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    //int T; cin >> T; while (T--)
    solve();

    return 0;
}