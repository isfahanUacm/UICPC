#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> r(m + 1), w(m + 1);
    
    for (int i = 1; i <= m; i++)
        cin >> r[i] >> w[i];
    
    for (int j = 0; j <= n; j++) {
        bool works = true;
        for (int i = 1; i <= m; i++) {
            if (r[i] > j or w[i] > n - j) {
                works = false;
                break;
            }
        }
        if (works) {
            cout << string(j, 'R') + string(n - j, 'W') << endl;
            return;
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 1; i <= t; i++) {
        solve();
    }
    
    return 0;
}
