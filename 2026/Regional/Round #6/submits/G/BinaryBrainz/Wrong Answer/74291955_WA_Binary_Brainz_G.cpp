#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    long long n;
    cin >> n;
    long long b;
    cin >> b;
    vector<long long> v(n-1);
    for (long long i = 0; i < n-1; i++) {
        cin>>v[i];
    }

    sort(v.rbegin(), v.rend());

    ll ans  = v[0];
    for (int i = 1 ; i < n ; i++) {
        if (v[i] < 0)
            break;
        ans += v[i];
    }

    cout << (ans + b >= 0 ? (ans+b) : -1);

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    solve();

    return 0;
}