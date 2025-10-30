#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {
    ld d , a , o , ma , mo;
    cin >> d >> a >> o >> ma >> mo;
    a -= ma * d;
    if(a <= 0){
        cout << 0;
        return;
    }
    o -= mo * d;
    if(o <= 0){
        cout << 100;
        return;
    }
    ld sum = o + a;
    ld ans = a / sum;
    cout << fixed << setprecision(10) <<ans * 100;
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