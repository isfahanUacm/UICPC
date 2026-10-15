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
        ll counterB = 0;
        ll counterW = 0;
        vector<bool> check(n + 1, false);
        for (ll i = 0; i < size; i++){
            ll temp;
            cin >> temp;
            if (!check[temp]){
                if (temp % 2 == 0)
                    counterB++;
                else
                    counterW++;
                check[temp] = true;
            }
            else{
                if (counterB < counterW)
                    counterB++;
                else if (counterW < counterB)
                    counterW++;
            }
        }
        if (counterB == counterW)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}