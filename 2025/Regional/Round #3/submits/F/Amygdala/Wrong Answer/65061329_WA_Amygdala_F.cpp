#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';
#define pb push_back

const int N = 200;
double a[N] , mx[N] , mn[N];
string s[N];

void dfs(int v, vector<vector<int>>& adj, vector<bool>& mark){
    mark[v] = 1;
    for(int u : adj[v]){
        if(!mark[u])
            dfs(u,adj,mark);
    }
}


void solve()
{
    int n;  cin >> n;
    map<string,int> mp;
    vector<vector<int>> adj;
    int j = 1;
    for(int i=0; i<n; i++){
        string a,b,c,d; cin >> a >> b >> c >> d;
        a.pop_back();
        if(mp[a] == 0) {
            mp[a] = j++;
            adj.push_back(vector<int>());
        }
        if(mp[d] == 0) {
            mp[d] = j++;
            adj.push_back(vector<int>());
        }
        adj[mp[a]-1].push_back(mp[d]-1);
        adj[mp[d]-1].push_back(mp[a]-1);
    }

    j--;
    vector<bool> mark(j,0);
    dfs(0,adj,mark);
    for(int i=0; i<j; i++)
        if(!mark[i]){
            cout << "impossible\n";
            return;
        }
    cout << "possible\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

//    for(int i=1; i<20; i++) cout << i << ':' << is_prime(i) << endl;
    return 0;
}