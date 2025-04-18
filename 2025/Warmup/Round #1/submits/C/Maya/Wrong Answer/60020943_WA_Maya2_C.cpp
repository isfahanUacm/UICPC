#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> vc(k);
    for (int i = 0; i < k; i++) {
        cin >> vc[i];
    }
    
    long long ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += vc[i] * (k - i);
    }
    ans += n;
    cout << ans << endl;

    return 0;
}
