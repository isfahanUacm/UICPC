#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n)
#define sint(s) string (s); cin >> (s)
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n'
// #define int ll
#define endl '\n'

int a[30] , b[20];
int num1=0 , num2=0;

string x , y , z;

// int f(int ind){
//     if(ind > x.size()+y.size()){
//         int sum=num1+num2;
//     }
//     if(ind > x.size()){
//         ind-=x.size();
//         if(a[y[ind]]!=-1){
//             num2*=10;
//             num2+=a[y[ind]];
//             return(f(x.size()+ind+1));
//         }
//         int res=0;
//         for(int i=1 ; i<10 ; i++){
//             if(b[i]==-1){
//                 a[y[ind]]=i;
//                 b[i]=y[ind];
//                 num2*=10;
//                 num2+=i;
//                 res+=f(x.size()+ind+1);
//                 a[y[ind]]=-1;
//                 b[i]=-1;
//             }
//         }
        

//     }
// }


void solve()
{
    unsigned ll a, b, c; cin >> a >> b;
    __int128_t res = (__int128_t)(a) * b;
    c = a * b;
    
    vector<int> v(3, -1);
    if(c != res) v[2] = 128;
    else if((int)(a*b) == c) v[2] = 32;
    else v[2] = 64;

    if((int)a == a) v[0] = 32;
    else v[0] = 64;

    if((int)b == b) v[1] = 32;
    else v[1] = 64;

    if(v[0] < v[2] && v[1] < v[2])
    {
        if(v[1] > v[0]) v[1] = v[2];
        else v[0] = v[2];
    }

    for(auto x : v) cout << x << '\n';
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}