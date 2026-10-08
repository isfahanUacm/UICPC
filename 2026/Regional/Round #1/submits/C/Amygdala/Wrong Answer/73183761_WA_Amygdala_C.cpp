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

int a[100] , b[20];
int num1=0 , num2=0;
int v[100], w[20];
bool ans = 0;
int ans1=0;
int ans2=0;
int c=0;

string x , y , z;

int f(int ind){
    if(ind >= x.size()+y.size()){
        int sum=num1+num2;
        // cout << "sum: " <<sum << ' ';
        string s=to_string(sum);
        if(s.size() != z.size()){
            return 0;
        }
        memset(v,-1,sizeof v);
        memset(w,-1,sizeof w);
        for(int i=0 ; i<s.size() ; i++){
            if((a[z[i]]!= -1 && a[z[i]]!=(s[i]-'0') ) || (b[s[i]-'0'] != -1 && b[s[i]-'0']!= z[i]) || (v[z[i]]!= -1 && v[z[i]]!=(s[i]-'0') || (w[s[i]-'0'] != -1 && w[s[i]-'0']!= z[i]))){
                return 0;
            }
            v[z[i]]=(s[i]-'0');
            w[s[i]-'0'] = z[i];
        }
        //cout << s << '\n';
        if(ans==0){
            ans = 1;
            ans1 = num1;
            ans2 = num2;
            c = sum;
        }
        return 1;

    }
    if(ind >= x.size()){
        ind-=x.size();
        if(a[y[ind]]!=-1){
            num2*=10;
            num2+=a[y[ind]];
            return(f(x.size()+ind+1));
        }
        int res=0;
        for(int i=(ind == 0) ; i<10 ; i++){
            if(b[i]==-1){
                a[y[ind]]=i;
                b[i]=y[ind];
                num2*=10;
                num2+=i;
                res+=f(x.size()+ind+1);
                a[y[ind]]=-1;
                b[i]=-1;
                num2/=10;
            }
        }
        return res;
        

    }
    if(a[x[ind]]!=-1){
        num1*=10;
        num1+=a[x[ind]];
        return f(ind+1);
    }
    int res=0;
    for(int i=(ind == 0) ; i<10 ; i++){
        if(b[i]==-1){
            a[x[ind]]=i;
            b[i]=x[ind];
            num1*=10;
            num1+=i;
            res+=f(ind+1);
            a[x[ind]]=-1;
            b[i]=-1;
            num1/=10;
        }
    }
    return res;
}


void solve()
{
    cin >> x >> y >> z;
    fill(a, a+100 , -1);
    fill(b, b+20 , -1);
    cout << f(0) << endl;
    if(ans){
        cout << ans1 << '\n' << ans2 << '\n' << c << '\n';
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