#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {
    int n , s;
    cin >> n >> s;
    char c;
    cin >> c;
    if(c == 'R'){
        cout << s - 1 << " ";
        int d = n - s;
        d++;
        if(d % 2 == 1){
            cout << d / 2 + 1 << " " << d / 2 + 1;
        }
        else{
            d /= 2;
            cout << d << " " << d;
        }
    }
    else{
        int d = s;
        if(d % 2 == 1){
            cout << d / 2 + 1 << " " << d / 2 + 1 << " ";
        }
        else{
            d /= 2;
            cout << d << " " << d << " ";
        }
        cout << n - s;
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