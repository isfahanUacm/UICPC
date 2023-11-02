#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx = 110;

ll n,m;
ll grid[mx][mx];
ll deptha[mx][mx];
ll depthb[mx][mx];
pair<ll,ll> parenta[mx][mx];
pair<ll,ll> parentb[mx][mx];
pair<ll,ll> mov[4] = {{1,0},{-1,0},{0,1},{0,-1}};
pair<ll,ll> a1,a2,b1,b2;
bool in_range(ll x, ll y){
    return (x >= 0 && x <= n && y >= 0 && y <= m);
}
bool other_goal(ll x, ll y, ll w){
    if(w==1){
        return (x == b2.first && y == b2.second) || (x == b1.first && y == b1.second);
    }
    else{
        return (x == a2.first && y == a2.second) || (x == a1.first && y == a1.second);
    }
}
void bfsa(ll x, ll y){
    queue<pair<ll,ll>> q;
    q.push({x,y});
    grid[x][y] = 1;
    deptha[x][y] = 0;
    while(!q.empty()){
        pair<ll,ll> u = q.front();
        q.pop();
        for(auto m:mov){
            pair<ll,ll> v = {u.first + m.first, u.second + m.second};
            if(in_range(v.first, v.second) && grid[v.first][v.second] == -1 && !other_goal(v.first, v.second, 1)){
                grid[v.first][v.second] = 1;
                deptha[v.first][v.second] = deptha[u.first][u.second] + 1;
                parenta[v.first][v.second] = u;
                q.push(v);
            }
        }
    }
}

void bfsb(ll x, ll y){
    queue<pair<ll,ll>> q;
    q.push({x,y});
    grid[x][y] = 2;
    depthb[x][y] = 0;
    while(!q.empty()){
        pair<ll,ll> u = q.front();
        q.pop();
        for(auto m:mov){
            pair<ll,ll> v = {u.first + m.first, u.second + m.second};
            if(in_range(v.first, v.second) && grid[v.first][v.second] == -1 && !other_goal(v.first, v.second, 2)){
                grid[v.first][v.second] = 2;
                depthb[v.first][v.second] = depthb[u.first][u.second] + 1;
                parentb[v.first][v.second] = u;
                q.push(v);
            }
        }
    }
}

int main(){
    memset(grid, -1, sizeof(grid));
    memset(deptha, 0, sizeof(deptha));
    memset(depthb, 0, sizeof(depthb));
    for(ll i=0;i<mx;i++)
        for(ll j=0;j<mx;j++)
            parenta[i][j] = {-1,-1}, parentb[i][j] = {-1,-1};


    cin >> n >> m;
    cin >> a1.first >> a1.second >> a2.first >> a2.second;
    cin >> b1.first >> b1.second >> b2.first >> b2.second;

    
    
    bfsa(a1.first, a1.second);
   
    memset(grid, -1, sizeof(grid));
    pair<ll,ll> cur = a2;
    //cout<<cur.first<<" "<<cur.second<<endl;
    if(parenta[a2.first][a2.second].first != -1 && parenta[a2.first][a2.second].second != -1){
        while(true){

            grid[cur.first][cur.second] = 1;
            cur = parenta[cur.first][cur.second];
            //cout<<cur.first<<" "<<cur.second<<endl;
            if(cur.first == -1 && cur.second == -1)
                break;
        }
    }
    


    bfsb(b1.first, b1.second);

    
    ll ans = -1;
    if(grid[a2.first][a2.second] == 1 && grid[b2.first][b2.second] == 2)
        ans  = deptha[a2.first][a2.second] + depthb[b2.first][b2.second];
    
    
    memset(grid, -1, sizeof(grid));
    memset(deptha, 0, sizeof(deptha));
    memset(depthb, 0, sizeof(depthb));
    for(ll i=0;i<mx;i++)
        for(ll j=0;j<mx;j++)
            parenta[i][j] = {-1,-1}, parentb[i][j] = {-1,-1};

    bfsb(b1.first, b1.second);
    memset(grid, -1, sizeof(grid));
    cur = b2;
if(parentb[b2.first][b2.second].first != -1 && parentb[b2.first][b2.second].second != -1){
        cur = b2;
        while(true){
            grid[cur.first][cur.second] = 2;
            cur = parentb[cur.first][cur.second];
            if(cur.first == -1 && cur.second == -1)
                break;
        }
    }   
    
    
    bfsa(a1.first, a1.second);
    

    if(grid[a2.first][a2.second] == 1 && grid[b2.first][b2.second] == 2){
        if(ans == -1)
            ans = deptha[a2.first][a2.second] + depthb[b2.first][b2.second];
        else
            ans = min(ans, deptha[a2.first][a2.second] + depthb[b2.first][b2.second]);
    }
   
    if(ans == -1)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << ans << endl;

    return 0;


}
