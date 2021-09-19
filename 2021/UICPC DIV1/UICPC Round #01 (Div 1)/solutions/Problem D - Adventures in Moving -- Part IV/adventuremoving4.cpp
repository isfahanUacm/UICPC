#include <bits/stdc++.h>
using namespace std;

// Adventures in Moving -- Part IV

int destination, n = 0, stations[103], price[103], dp[103][203];
const int inf = INT_MAX;

int main(){
    cin >> destination;
    while(cin >> stations[n] >> price[n])
        n++;
    stations[n] = destination;
    if(stations[0] > 100){
        cout << "Impossible" << endl;
        return 0;
    }
    for(int i = n; i >= 0; i--)
        for(int tank = 200; tank >= 0; tank--){
            if(i == n){
                dp[i][tank] = (tank >= 100) ? 0 : inf;
                continue;
            }
            dp[i][tank] = inf;
            if(tank < 200 && dp[i][tank+1] != inf)
                dp[i][tank] = dp[i][tank+1] + price[i];
            if(tank >= (stations[i+1] - stations[i]) && dp[i+1][tank-stations[i+1]+stations[i]] != inf)
                dp[i][tank] = min(dp[i][tank], dp[i+1][tank-stations[i+1]+stations[i]]);
        }
    if(dp[0][100-stations[0]] == inf)
        cout << "Impossible" << endl;
    else
        cout << dp[0][100-stations[0]] << endl;
}