#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    int r_max = 0, w_max = 0;
    
    for (int i = 1; i <= m; i++) {
        int r, w;
        cin >> r >> w;
        r_max = max(r_max, r);
        w_max = max(w_max, w);
    }
    
    if (r_max + w_max > n)
        cout << "IMPOSSIBLE" << endl;
    else cout << string(r_max, 'R') + string(n - r_max, 'W') << endl;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 1; i <= t; i++) {
        solve();
    }
    
    return 0;
}
