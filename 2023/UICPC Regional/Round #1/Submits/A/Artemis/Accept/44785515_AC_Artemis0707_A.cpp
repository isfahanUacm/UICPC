#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx = 1e3+10;
const ll mo = 2147483647 ;
ll dp[mx][mx];
char base[mx][mx];
bool visited[mx][mx];
ll n;
bool is_reachable(){
    queue<pair<ll,ll>> q;
    q.push({0,0});
    visited[0][0] = true;
    while(q.empty()==false){
        pair<ll,ll> curr = q.front();
        q.pop();
        ll x = curr.first;
        ll y = curr.second;
        if(x==n-1&&y==n-1)return true;
        if(x>0&&visited[x-1][y]==false&&base[x-1][y]=='.'){
            visited[x-1][y] = true;
            q.push({x-1,y});
        }
        if(y>0&&visited[x][y-1]==false&&base[x][y-1]=='.'){
            visited[x][y-1] = true;
            q.push({x,y-1});
        }
        if(x<n-1&&visited[x+1][y]==false&&base[x+1][y]=='.'){
            visited[x+1][y] = true;
            q.push({x+1,y});
        }
        if(y<n-1&&visited[x][y+1]==false&&base[x][y+1]=='.'){
            visited[x][y+1] = true;
            q.push({x,y+1});
        }
    }
    return visited[n-1][n-1];
}
int main(){
    cin >> n;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin >> base[i][j];
        }
    }

    dp[0][0] = 1;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(i==0 && j==0)continue;
            if(base[i][j]=='#')continue;
            if(i>0){
               
                dp[i][j] = (dp[i][j] + dp[i-1][j])%mo;
            }
            if(j>0){
                dp[i][j] = (dp[i][j] + dp[i][j-1])%mo;
             
            }
            
        }
    }

if(dp[n-1][n-1]>0){
    cout<<dp[n-1][n-1]<<endl;
}
else if(is_reachable()){
    cout<<"THE GAME IS A LIE"<<endl;
}
else{
    cout<<"INCONCEIVABLE"<<endl;
}
    return 0;
}