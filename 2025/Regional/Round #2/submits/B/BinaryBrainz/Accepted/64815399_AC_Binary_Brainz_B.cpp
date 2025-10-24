#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>

void solve() {
    int n , m;
    cin >> n >> m;
    vll solve(m , 0) , attempt(m , 0) , inc(m , 0);
    char c;
    int num;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c >> num;
            if(num or c == '+'){
                attempt[j] ++;
            }
            if(c == '+'){
                solve[j]++;
            }
            inc[j] += num;
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << solve[i] << " " << attempt[i] << " " << inc[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;
    while (T--)
        solve();
    return 0;
}