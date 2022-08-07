#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>


using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<pair<int, int>> p;
    p.reserve(n * n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> a[i][j];
            p.emplace_back(i, j);
        }
    }
    
    sort(p.begin(), p.end(), [&](auto x, auto y) { return a[x.first][x.second] < a[y.first][y.second]; });
    
    vector<long long> row_cnt(n, 0), col_cnt(n, 0);
    long long ans = (long long)(n) * n * (n - 1) * (n - 1) / 2;
    for(auto x : p) {
        ans -= row_cnt[x.first] * col_cnt[x.second];
        ++row_cnt[x.first];
        ++col_cnt[x.second];
    }
    
    cout << ans << "\n";
    
    return 0;
}
