#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int h[n], mini = 5000;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int t;
    cin >> t;

    int ans;
    for (int i = 0; i < n; i++) {
        int rem = t % h[i];
        if (mini > rem) {
            ans = h[i];
            mini = rem;
        }
    }
    cout << ans;
    return 0;
}
