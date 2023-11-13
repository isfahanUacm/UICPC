//Solution by lukasP (Lukáš Poláček)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef long long ll;
int main() {
    int n; scanf("%d", &n);
    vector<ll> a(n);
    rep(i,0,n) scanf("%lld", &a[i]);

    ll money = 100 % a[0], stocks = 100 / a[0];
    ll ma = 100;

    rep(i,1,n) {
        if (a[i] < a[i - 1]) { // Sell
            money += a[i - 1] * stocks;

            ll count = min(100000LL, money / a[i]);
            stocks = count;
            money = money - count * a[i];
        }
        ma = max(ma, money + stocks * a[i]);
    }

    cout << ma << endl;
}
