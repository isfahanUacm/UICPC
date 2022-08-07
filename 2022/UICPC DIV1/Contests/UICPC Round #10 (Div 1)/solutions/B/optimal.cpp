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
    vector<pair<int, int>> p(n * n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int a;
            cin >> a;
            p[a - 1] = make_pair(i, j);
        }
    }
    
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
