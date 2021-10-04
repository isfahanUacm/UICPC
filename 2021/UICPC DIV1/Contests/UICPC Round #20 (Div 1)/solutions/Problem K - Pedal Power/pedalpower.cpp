#include <bits/stdc++.h>
using namespace std;

// Pedal Power

#define num long long int
#define inf LLONG_MAX

int n, x, y, z;
num bike[303][303], road[303][303], path[303], dp[303][303];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            bike[i][j] = road[i][j] = i == j ? 0 : inf;
    int u, v;
    num t;
    cin >> x;
    while(x--){
        cin >> u >> v >> t;
        bike[u][v] = bike[v][u] = t;
    }
    cin >> y;
    while(y--){
        cin >> u >> v >> t;
        road[u][v] = road[v][u] = t;
    }
    cin >> z;
    for(int i = 1; i <= z; i++)
        cin >> path[i];
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                if(bike[i][k] != inf && bike[k][j] != inf)
                    bike[i][j] = min(bike[i][j], bike[i][k] + bike[k][j]);
                if(road[i][k] != inf && road[k][j] != inf)
                    road[i][j] = min(road[i][j], road[i][k] + road[k][j]);
            }
    for(int i = z; i >= 0; i--)
        for(int b = 0; b < n; b++){
            num ans = inf;
            if(i == z){
                if(road[path[i]][b] != inf && bike[b][0] != inf)
                    ans = road[path[i]][b] + bike[b][0];
            }
            else{
                if(road[path[i]][path[i+1]] != inf && dp[i+1][b] != inf)
                    ans = road[path[i]][path[i+1]] + dp[i+1][b];
                for(int s = 0; s < n; s++)
                    if(road[path[i]][b] != inf && bike[b][s] != inf && road[s][path[i+1]] != inf && dp[i+1][s] != inf)
                        ans = min(ans, road[path[i]][b] + bike[b][s] + road[s][path[i+1]] + dp[i+1][s]);
            }
            dp[i][b] = ans;
        }
    cout << dp[0][0] << endl;
}