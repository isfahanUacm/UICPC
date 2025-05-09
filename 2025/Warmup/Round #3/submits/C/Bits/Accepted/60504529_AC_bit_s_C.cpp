#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

void solve()
{
//     int n,m,k ; cin >> n >> m >> k;
//     string s ; cin >> s;
//     int op;
//     for(int i = 0 ; i < k ; i++)
//     {
//         cin >> op;
//         if(op == 1)
//         {
//             int x,y,l,r;
//             cin >> x >> y >> l >> r;
//
//         }else
//         {
//             int p ; cin >> p ;
//             char c ; cin >> c;
//         }
//     }
    ll c; cin >> c;
    int n; cin >> n;
    vector<long double> v(n);
    map<long double,bool> mp;
    for(int i=0; i<n; i++){
        cin >> v[i];
        mp[v[i]] = 1;
    }
    for(int i=0; i<n; i++){
        long double num = c/v[i];
        if(mp[num]){
            cout << fixed << setprecision(0) << min(num,v[i]) << " " << max(num,v[i]) << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
//    cin >> n;
    while(n--)
        solve();

    return 0;
}