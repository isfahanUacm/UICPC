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
#define int unsigned int
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
    ll a, b;
    cin >> a >> b;

    int a1 = 0;
    while(a) a = a >> 1, a1++;

    int a2 = 0;
    while(b) b = b >> 1, a2++;

    int a3 = a1 + a2;

    int b1;
    if(a1 > 32)
    {
        if(a1 > 64) b1 = 128;
        else b1 = 64;
    }
    else b1 = 32;

    int b2;
    if(a2 > 32)
    {
        if(a2 > 64) b2 = 128;
        else b2 = 64;
    }
    else b2 = 32;

    int b3;
    if(a3 > 32)
    {
        if(a3 > 64) b3 = 128;
        else b3 = 64;
    }
    else b3 = 32;

    if(b1 < b3 && b2 < b3)
    {
        if(b1 < b2) b2 = b3;
        else b1 = b3;
    }

    cout << b1 << ' ' << b2 << ' ' << b3 << endl;
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