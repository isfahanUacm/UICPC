#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<long long> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    sort(s.begin(), s.end(), greater<long long>());
    vector<long long> pref(n+1, 0);
    for (int i = 1; i <= n; ++i) pref[i] = pref[i-1] + s[i-1];
    long double best = 0;
    for (int k = 1; k <= n; ++k) {
        long double total = (long double)pref[k] + (long double)a[k];
        long double avg = total / k;
        if (avg > best) best = avg;
    }
    cout.setf(std::ios::fixed);
    cout << setprecision(7) << (double)best << '\n';
    return 0;
}
