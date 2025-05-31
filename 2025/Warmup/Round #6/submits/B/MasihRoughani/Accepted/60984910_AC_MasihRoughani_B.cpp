#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n % 2 == 0){
            cout << n/2 << " " << n/2 << "\n";
        }
        else {
            ll ee = -1;
            for (ll i = 2; i * i <= n; i++){
                if(n % i == 0){
                    ee = i;
                    break;
                }
            }
            if(ee == -1){
                cout << 1 << " " << n - 1 << "\n";
            }
            else {
                ll d = n / ee;
                cout << d << " " << n - d << "\n";
            }
        }
    }
    return 0;
}
