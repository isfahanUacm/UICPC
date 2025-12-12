#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define int ll

const int N = 2e5+9;

vector<int> adj[N];
pInt p[N];
int a[N];
int par[N] , sz[N];

void ms(int a){
    par[a]=a;
    sz[a]=1;
}
int fs(int a){
    if(par[a]==a){
        return a;
    }
    return par[a] = fs(par[a]);
}
void us(int a , int b){
    a=fs(a); b=fs(b);
    if(a==b){
        return;
    }
    if(sz[a] < sz[b]){
        swap(a , b);
    }
    par[b]=a;
    sz[a]+=sz[b];
}

void solve()
{
    int n;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> p[i].first;
        p[i].second=i;
        a[i]=p[i].first;
        ms(i);
    }
    for(int i=0 ; i<n ; i++){
        int x;
        cin >> x;
        x--;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    sort(p , p+n);
    reverse(p , p+n);
    int ans=0 , mx=0;
    for(int j=0 ; j<n ; j++){
        int i = p[j].second;
        int cnt=0;
        for(int v : adj[i]){

            if(a[v] >= a[i]){
                us(i , v);
                cnt++;
            }
        }
        if(cnt == 0 || (cnt==1 && sz[fs(i)]%2==1)){
            ans++;
        }
        mx = max(mx , ans*a[i]);
//        cout << ans << ' ' << a[i] << endl;
    }
    cout << mx << '\n';

}

int32_t main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

//    for(int i=1; i<20; i++) cout << i << ": " << f(i) << endl;

    return 0;
}
