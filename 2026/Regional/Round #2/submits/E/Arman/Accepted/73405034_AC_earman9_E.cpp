#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>

using namespace std;
using ll = long long;

int main(){
    
    ll q;
    cin >> q;

    while (q--){
        ll n;
        cin >> n;
        ll size = n;
        vector<ll> numbs;
        ll counter = 0;
        bool fine = false;
        vector<int> check(n + 1, 0);
        for (ll i = 0; i < size; i++){
            ll temp;
            cin >> temp;
            if (!check[temp]){
                counter++;
            }
            check[temp]++;
            if (check[temp] >= 2)
                fine = true;
        }
        if (counter % 2 == 0 || fine)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}