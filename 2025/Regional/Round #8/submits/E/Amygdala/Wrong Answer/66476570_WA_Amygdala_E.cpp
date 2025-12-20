#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';

string v[110];
bool f(int a, int n, int m){
    bool start = 1;
    int st = 0;
    for(int i=0; i<n; i++){
        if(v[i][0] != v[st][0]){
            if(i-st > a)
                return false;
            else if(i-st < a) {
                if (st == 0)
                    start = 0;
                else
                    return false;
            }
            st = i;
        }else if(i-st > a)
            return false;
        int s = 0;
        while(s < m) {
            int j = s;
            for (; j < m; j++) {
                if (v[i][j] != v[i][s])
                    break;
            }
            if(j-s != a){
                if(j==m || s==0 || start){}
                else{
                    return false;
                }
            }
            s = j;
        }
    }
    return true;
}
void solve(int n,int m)
{
    for(int i=0; i<n; i++)
        cin >> v[i];

    int r=0,c=0;
    bool flag = 0;
    for(int i=0; i<m; i++){
        if(v[0][i] != v[0][0]){
            flag = 1;
            c++;
        }else if(flag){
            flag = 0;
            break;
        }
    }
    if(flag){
        c = max(c,m-c);
    }
    flag = 0;
    for(int i=0; i<n; i++){
        if(v[i][0]!= v[0][0]){
            flag = 1;
            r++;
        }else if(flag){
            flag = 0;
            break;
        }
    }
    if(flag){
        r = max(r,n-r);
    }
    int a = max(r,c);
    if(f(a,n,m)){
        if(f(a+1,n,m))
            cout << 0 << '\n';
        else
            cout << a << '\n';
    }else{
        cout << "-1\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    int n=1, m=1;
//    cin >> t;
    while(n)
    {
        cin >> n >> m;
        if(!n) break;
        solve(n, m);
    }

    return 0;
}