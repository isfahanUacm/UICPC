#include <bits/stdc++.h>
using namespace std;

// Slow Leak

#define num long long int
#define inf LLONG_MAX

int n, m, t;
bool station[503];
num d, leak[503][503], first[503][503], last[503][503];

void floyd(){
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(leak[i][k] != inf && leak[k][j] != inf){
                    int f = (last[i][k] == inf) ? i : last[i][k];
                    int s = (first[k][j] == inf) ? j : first[k][j];
                    num no_station = leak[f][k] + leak[k][s];
                    if(no_station <= d && leak[i][f] + no_station + leak[s][j] < leak[i][j]){
                        leak[i][j] = leak[i][f] + no_station + leak[s][j];
                        if(first[i][k] == inf)
                            first[i][j] = first[k][j];
                        else
                            first[i][j] = first[i][k];
                        if(last[k][j] == inf)
                            last[i][j] = last[i][k];
                        else
                            last[i][j] = last[k][j];
                    }
                }
}

int main(){
    int x, y;
    num w;
    cin >> n >> m >> t >> d;
    while(t--)
        cin >> x, station[x-1] = true;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            if(i == j){
                leak[i][j] = 0;
                first[i][j] = last[i][j] = station[i] ? i : inf;
            }
            else
                leak[i][j] = first[i][j] = last[i][j] = inf;
        }
    while(m--){
        cin >> x >> y >> w;
        if(w > d)
            continue;
        x--, y--;
        leak[x][y] = leak[y][x] = w;
        if(station[x] && station[y])
            first[x][y] = last[y][x] = x, first[y][x] = last[x][y] = y;
        else if(station[x])
            first[x][y] = last[x][y] = first[y][x] = last[y][x] = x;
        else if(station[y])
            first[x][y] = last[x][y] = first[y][x] = last[y][x] = y;
    }
    floyd();
    floyd();
    if(leak[0][n-1] == inf)
        cout << "stuck" << endl;
    else
        cout << leak[0][n-1] << endl;    
}