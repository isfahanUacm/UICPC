#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll max_prixe = 100000;
ll price[400];
int main() {
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> price[i];
    }
    
    ll money = 100;
    ll share = 0;

    if (price[0] <= 100) {
        share = money / price[0];
        money %= price[0];
    }

    for (ll i = 1; i < n; ++i) {
        if (price[i] < price[i - 1]) {
            money += share * price[i - 1];

            if (money / price[i] <= max_prixe) {
                share = money / price[i];
                money %= price[i];
            }
            else {
                share = max_prixe;
                money -= share * price[i];
            }
        }
    }
    cout << share * price[n - 1] + money << endl;
}