#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> diff2beauty(11, -1000);
    for (int i = 0; i < n; i++) {
        int b, d;
        cin >> b >> d;
        diff2beauty[d] = max(diff2beauty[d], b);
    }
    int total_beauty = 0;
    for (int d = 1; d <= 10; d++) total_beauty += diff2beauty[d];

    if (total_beauty < 0) cout << "MOREPROBLEMS\n";
    else cout << total_beauty << "\n";
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    
    int t;
    cin >> t;
    while (t--) solve();
}
