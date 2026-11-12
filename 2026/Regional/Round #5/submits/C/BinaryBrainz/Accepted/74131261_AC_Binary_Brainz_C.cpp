#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin >> n;
    ll N = 1e6 + 5;
    vector<int> v(N);
    v[1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = i + i; j <= N; j += i) {
            v[j] = 1;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] == 0) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}