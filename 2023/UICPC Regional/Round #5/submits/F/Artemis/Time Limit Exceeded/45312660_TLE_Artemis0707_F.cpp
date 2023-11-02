#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mx = 55;
const ll mx2 = 1e4+10;
ll r,c;
string goal;
char grid[mx][mx];
ll dist[mx][mx][mx2];
ll ans =0;
pair<ll,ll> mov[4] = {{1,0},{-1,0},{0,1},{0,-1}};
vector<pair<ll,ll>> adj[mx][mx];

bool in_range(ll x, ll y){
    return x>=0 && x<r && y>=0 && y<c;
}
pair<ll,ll> next_down_cell(ll x,ll y){
    x++;
    while(in_range(x,y) && grid[x][y] == grid[x-1][y]){
        x++;
    }
    return {x,y};
}
pair<ll,ll> next_up_cell(ll x,ll y){
    x--;
    while(in_range(x,y) && grid[x][y] == grid[x+1][y]){
        x--;
    }
    return {x,y};
}
pair<ll,ll> next_rigth_cell(ll x,ll y){
    y++;
    while(in_range(x,y) && grid[x][y] == grid[x][y-1]){
        y++;
    }
    return {x,y};
}
pair<ll,ll> next_left_cell(ll x,ll y){
    y--;
    while(in_range(x,y) && grid[x][y] == grid[x][y+1]){
        y--;
    }
    return {x,y};
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;
    for(ll i = 0; i < r; i++){
        for(ll j = 0; j < c; j++){
            cin >> grid[i][j];
        }
    }
    cin >> goal;
    goal += '*';

    for(ll i = 0; i < r; i++){
        for(ll j = 0; j < c; j++){
            for(ll k = 0; k < mx2; k++){
                dist[i][j][k] = 1e9;
            }
        }
    }

    for(ll i = 0; i < r; i++){
        for(ll j = 0; j < c; j++){
            pair<ll,ll> v = next_down_cell(i,j);
            if(in_range(v.first,v.second)){
                adj[i][j].push_back(v);
            }
            v = next_up_cell(i,j);
            if(in_range(v.first,v.second)){
                adj[i][j].push_back(v);
            }
            v = next_rigth_cell(i,j);
            if(in_range(v.first,v.second)){
                adj[i][j].push_back(v);
            }
            v = next_left_cell(i,j);
            if(in_range(v.first,v.second)){
                adj[i][j].push_back(v);
            }
        }
    }

    queue<pair<pair<ll,ll>,ll>> q;
    q.push({{0,0},0});
    dist[0][0][0] = 0;

    while(!q.empty()){
        ll x = q.front().first.first;
        ll y = q.front().first.second;
        ll k = q.front().second;
        q.pop();
        if(k==goal.length()){
            ans = dist[x][y][k];
            break;
        }
        vector<pair<pair<ll,ll>,ll>> adj2;
        pair<ll,ll> v = next_down_cell(x,y);
        
        for(auto v:adj[x][y]){
            adj2.push_back({{v.first,v.second},k});
        }
        
        if(k<goal.length() && grid[x][y] == goal[k]){
            adj2.push_back({{x,y},k+1});
        }
        for(auto u:adj2){
            if(dist[u.first.first][u.first.second][u.second] == 1e9){
                dist[u.first.first][u.first.second][u.second] = dist[x][y][k]+1;
                q.push({{u.first.first,u.first.second},u.second});
                if(u.second == goal.length()){
                    ans = dist[u.first.first][u.first.second][u.second];
                    break;
                }
            }
        }

    }
    cout << ans << endl;

    return 0;
}