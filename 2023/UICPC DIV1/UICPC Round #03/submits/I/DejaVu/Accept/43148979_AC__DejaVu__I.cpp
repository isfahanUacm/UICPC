#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+20;
int a[maxn];

int main() {
    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    if (n%2 != 0) {
        cout << "still running" << "\n";
    }
    else {
        long long ans = 0;
        for (int i=1; i<n; i+=2) {
            ans += a[i] - a[i-1];
        }
        cout << ans << "\n";
    }



    return 0;
}