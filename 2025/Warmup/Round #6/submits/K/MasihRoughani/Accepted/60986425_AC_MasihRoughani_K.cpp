#include <bits/stdc++.h>
#include <cmath>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, t, k, d;
    cin >> n >> t >> k >> d;
    ll bat = (n + k - 1) / k;
    ll ft = bat * t;
    ll st = ft - 1;
    ll c = (st / t) * k;
    if(st > d) {
        c += ((st - d) / t) * k;
    }
    if(c >= n)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
    return 0;
}
