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
// #define int unsigned int
#define int ll
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


bool valid(int d, vector<int>& v, int T)
{
    int sum = 0;
    for(auto x : v) sum += (x + d - 1) / d;
    if(sum <= T) return true;
    return false;
}

void solve()
{
    int n, t; cin >> n >> t;
    vector<int> v(n); vin(v);

    int mn = 1, mx = 1e12+10;
    while(mn < mx)
    {
        int mid = (mn + mx) / 2;

        if(valid(mid, v, t)) mx = mid;
        else mn = mid + 1;
    }

    cout << mx << endl;
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