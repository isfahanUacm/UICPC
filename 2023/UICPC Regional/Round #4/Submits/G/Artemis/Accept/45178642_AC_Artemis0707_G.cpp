#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mx = 51;
char grid[mx][mx];
ll visited[mx][mx];
ll h,w;
ll si,sj;
pair<ll,ll> mov[4] = {{1,0},{-1,0},{0,1},{0,-1}};

bool in_range(ll x, ll y){
    return (x >= 0 && x < h && y >= 0 && y < w);
}
bool may_danger(ll x, ll y){
    for(auto m:mov){
        ll vx = x + m.first;
        ll vy = y + m.second;
        if(in_range(vx,vy) && grid[vx][vy] == 'T') return true;
    }
    return false;
}
void dfs(ll x, ll y){
    visited[x][y] = 1;
    if(may_danger(x,y)){
        return;
    }
    for(auto m:mov){
        ll vx = x + m.first;
        ll vy = y + m.second;
        if(in_range(vx,vy) && grid[vx][vy] != '#' && visited[vx][vy]==0){
            dfs(vx,vy);
        }

    }
}
int main(){
    cin >> w >> h;
    for(ll i = 0; i < h; i++){
        for(ll j = 0; j < w; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'P'){
                si = i;
                sj = j;
            }
         }
        }
    dfs(si,sj);
    ll ans =0;
    for(ll x=0;x<h;x++){
        for(ll y=0;y<w;y++){
            if(visited[x][y]==1 && grid[x][y] == 'G')ans++; 
            
        }
    }
    cout<<ans<<endl;

}
    