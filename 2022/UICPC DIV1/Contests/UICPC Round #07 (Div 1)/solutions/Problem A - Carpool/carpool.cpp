#include <bits/stdc++.h>
using namespace std;

// Carpool

const int inf = INT_MAX;

int n, m, k, ans = inf, floyd[17+3][17+3], tsp[(1<<15)+3][15+3], dp[(1<<15)+3], car[15+3], cars[3+3], siz[3+3];

void track(int i){
    if(i == n){
        fill_n(cars, k, 0);
        fill_n(siz, k, 0);
        int curr = 0;
        for(int i = 0; i < n; i++)
            cars[car[i]] += 1 << i, siz[car[i]]++;
        for(int i = 0; i < k; i++){
            if(!cars[i] || siz[i] > 5)
                return;
            curr = max(curr, 5 * siz[i] + dp[cars[i]]);
        }
        ans = min(ans, curr);
        return;
    }
    for(int c = 0; c < k; c++)
        car[i] = c, track(i+1);
}

int main(){
    int x, y, w;
    cin >> n >> m;
    for(int i = 0; i < n + 2; i++)
        for(int j = 0; j < n + 2; j++)
            floyd[i][j] = (i == j) ? 0 : inf;
    while(m--)
        cin >> x >> y >> w, floyd[x][y] = min(floyd[x][y], w), floyd[y][x] = min(floyd[y][x], w);
    for(int k = 0; k < n + 2; k++)
        for(int i = 0; i < n + 2; i++)
            for(int j = 0; j < n + 2; j++)
                if(floyd[i][k] != inf && floyd[k][j] != inf)
                    floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
    for(int mask = 1; mask < (1<<n); mask++)
        for(int i = 0; i < n; i++){
            tsp[mask][i] = inf;
            if(mask == 1 << i)
                tsp[mask][i] = floyd[0][i+1];
            else if(mask & (1 << i))
                for(int j = 0; j < n; j++)
                    if(j != i && (mask & (1 << j)))
                        tsp[mask][i] = min(tsp[mask][i], tsp[mask - (1 << i)][j] + floyd[j+1][i+1]);
        }
    for(int mask = 1; mask < (1<<n); mask++){
        dp[mask] = inf;
        for(int i = 0; i < n; i++)
            if((mask & (1<<i)))
                dp[mask] = min(dp[mask], tsp[mask][i] + floyd[i+1][n+1]);
    }
    k = n / 5 + (n % 5 ? 1 : 0);
    track(0);
    cout << ans << endl;
}