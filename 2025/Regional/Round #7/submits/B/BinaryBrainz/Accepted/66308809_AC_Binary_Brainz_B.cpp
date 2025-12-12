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
    if(n / 1000){
        if((n / 10) % 10 == 0){
            cout << "-1";
            return;
        }
        cout << n / 100 << " ";
        cout << n % 100 ;
    }
    else if(n / 100){
        if((n / 10) % 10 == 0 && n % 10 != 0){
            cout << n / 10 << " ";
            cout << n % 10;

        }
        else if((n / 10) % 10 != 0 && n % 10 == 0){
            cout << n / 100 << " ";
            cout << n % 100;

        }
        else{
            cout << -1;
            return;
        }
    }
    else if(n / 10){
        if(n % 10 == 0){
            cout << -1;
            return;
        }
        else{
            cout << n / 10 << " ";
            cout << n % 10;
        }
    }
    else{
        cout << -1;
    }
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