#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {
    int n;
    cin >> n;
    string s , t;
    cin >> s >> t;
    ll sum = 0;
    string ans;
    ans.resize(n);
    for (int i = 0; i < n / 2; ++i) {
        vll a(4);
        a[0] = int(s[i]);
        a[1] = int(t[i]);
        a[2] = int(s[n - i - 1]);
        a[3] = int(t[n - i - 1]);
        sort(a.begin(), a.end());
        ll d = (a[1] + a[2]) / 2;
        ans[i] = char(d);
        ans[n - i - 1] = char(d);
    }
    if(n % 2){
        int i = n / 2;
        sum = int(s[i]) + int(t[i]);
        sum /= 2;
        ans[i] += char(sum);
    }
    cout << ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;
    while (T--)
        solve();
    return 0;
}