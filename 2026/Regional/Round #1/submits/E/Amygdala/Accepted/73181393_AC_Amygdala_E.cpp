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

void solve()
{
    
    // cin >> x >> y >> z;
    // fill(a, a+30 , -1);
    // fill(b, b+20 , -1);
    // f(0);
    int n,q;    cin >> n >> q;
    char c[100][100] ;
    int at[100][100];

    for(int i=0; i<n; i++)
        for(int j=0; j<q; j++){
            cin >> c[i][j] >> at[i][j];
        }
    
    for(int j=0; j<q; j++){
        int ans1 = 0, ans2=0, ans3=0;
        for(int i=0; i<n; i++){
            if(c[i][j] == '+'){
                ans1++;
            }
            else{
                if(at[i][j] > 0) ans3++;
            }
            ans2+=at[i][j];
        }
        cout << ans1 << " " << ans1+ans3 << " " << ans2 << '\n';
    }


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