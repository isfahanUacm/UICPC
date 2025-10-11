#include <bits/stdc++.h>
#include <functional>
using namespace std;

using u32 = unsigned;
using i64 = int64_t;
using u64 = unsigned int64_t;
using i128 = __int128;
using u128 = unsigned __int128;
using ld = long double;
using my_pair = pair<int, pair<int, int>>;

constexpr int INF32 = 1E9;
constexpr i64 INF64 = 1E18;
constexpr int MOD = 1e9 + 7;

#define sz(x) (int)x.size()
#define F first
#define S second

const int N = 2e5 + 1;
int cnt = 1;

void solve() {
    int n;
    cin >> n;
    
    vector<int> s(n);
    for (int &x : s) 
        cin >> x;

    vector<int> p(n);
    sort(s.begin(), s.end());

    int i = 0, j = n - 1, val = n - 1;

    for (int k = 0; k < n; k++) {
        if (k % 2 == 1) {
            p[i++] = s[val--];
        } else {
            p[j--] = s[val--];
        }
    }

    cout << "Case "<< cnt++ << ":" << endl; 
    for (int k = 0; k < n; k++) {
        cout << p[k] << " \n"[k + 1 == n];
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}

