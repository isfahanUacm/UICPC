#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define vi vector <int>
#define all(x) x.begin(),x.end()

const int N = 1e6+9 , INF = 1e18 ;
vi adj[N];
int dis[N] , n;

int d(int a , int b){
    fill(dis , dis+n , INF);
    queue<int> q;
    q.push(a);
    dis[a]=0;
    while(!q.empty()){
        int v=q.front();
        for(int u : adj[v]){
            if(dis[v]+1 < dis[u]){
                dis[u]=dis[v]+1;
                q.push(u);
            }
        }
        q.pop();
    }
    return((dis[b] >= INF ? -1 : dis[b]));
}
int f(int a){
    fill(dis , dis+n , INF);
    queue<int> q;
    q.push(a);
    dis[a]=0;
    int mx=0;
    while(!q.empty()){
        int v=q.front();
        for(int u : adj[v]){
            if(dis[v]+1 < dis[u]){
                dis[u]=dis[v]+1;
                mx=max(mx , dis[u]);
                q.push(u);
            }
        }
        q.pop();
    }
    return mx;
}


int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T=1;
    cin >> T;
    while(T--) {
       int  m;
       cin >> n >> m;
       for(int i=0 ; i<n ; i++){
           adj[i].clear();
       }
       int a , b , c;
       cin >> a >> b >> c;
       a--; b--; c--;
       for(int i=0 ; i<m ; i++){
           int u , v;
           cin >> u >> v;
           u--;
           v--;
           adj[u].pb(v);
           adj[v].pb(u);
       }

       if(d(a , c)==-1){
           if(d(b , c)==1){
               cout << "Tie" << endl;
           }
           else if(d(b , c) == -1){
               cout << (d(a , b)==-1 ? "Tie" : "Alice") << endl;
           }
           else{
               cout << "Alice" << endl;
           }
       }
       else{
           if(d(b , c)==1){
               cout << (d(a , c) == 1 ? "Tie" : "Bob")  << endl;
           }
           else if(d(b , c)==-1){
               int db=f(b)+f(c)+1;
               if(d(a , c) < db){
                   cout << "Alice" << endl;
               }
               else if(d(a , c) > db){
                   cout << "Bob" << endl;
               }
               else{
                   cout << "Tie" << endl;
               }
           }
           else{
               if(d(a , c) < d(b , c)){
                   cout << "Alice" << endl;
               }
               else if(d(a , c) > d(b , c)){
                   cout << "Bob" << endl;
               }
               else{
                   cout << "Tie" << endl;
               }
           }
       }

    }

}
