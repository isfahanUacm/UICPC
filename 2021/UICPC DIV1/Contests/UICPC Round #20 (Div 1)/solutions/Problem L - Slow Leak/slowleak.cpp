#include <bits/stdc++.h>
using namespace std;

// Slow Leak

#define num long long int
#define inf LLONG_MAX

int n, m, t, tmp, tmp2;
num d, tmp3;
bool rs[503];
num floyd[503][503];
num nexty[503][503];
num prevy[503][503];

inline void set_edge(int x, int y, num d){
    floyd[x][y] = d;
    if(rs[x] && rs[y])
        nexty[x][y] = prevy[x][y] = 0;
    else if(rs[x] && !rs[y]){
        nexty[x][y] = d;
        prevy[x][y] = 0;
    }
    else if(!rs[x] && rs[y]){
        nexty[x][y] = 0;
        prevy[x][y] = d;
    }
}

void run_floyd(){
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                if(rs[k]){
                    if(floyd[i][k] != inf && floyd[k][j] != inf && floyd[i][k] + floyd[k][j] < floyd[i][j]){
                        floyd[i][j] = floyd[i][k] + floyd[k][j];
                        nexty[i][j] = (nexty[k][j] == inf) ? floyd[k][j] : nexty[k][j];
                        prevy[i][j] = (prevy[i][k] == inf) ? floyd[i][k] : prevy[i][k];
                    }
                }
                else{
                    if(floyd[i][k] != inf && floyd[k][j] != inf && floyd[i][k] + floyd[k][j] < floyd[i][j] && (((nexty[i][k] == inf) ? floyd[i][k] : nexty[i][k]) + ((prevy[k][j] == inf) ? floyd[k][j] : prevy[k][j])) <= d){
                        floyd[i][j] = floyd[i][k] + floyd[k][j];
                        if(nexty[k][j] != inf)
                            nexty[i][j] = nexty[k][j];
                        else if(nexty[i][k] != inf)
                            nexty[i][j] = nexty[i][k] + floyd[k][j];
                        else nexty[i][j] = inf;
                        if(prevy[i][k] != inf)
                            prevy[i][j] = prevy[i][k];
                        else if(prevy[k][j] != inf)
                            prevy[i][j] = floyd[i][k] + prevy[k][j];
                        else prevy[i][j] = inf;
                    }
                }
            }
}

int main(){
    cin >> n >> m >> t >> d;
    fill_n(rs, n, false);
    rs[0] = true;
    while(t--){
        cin >> tmp;
        rs[tmp-1] = true;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            if(i == j){
                floyd[i][j] = 0;
                prevy[i][j] = nexty[i][j] = rs[i] ? 0 : inf;
            }
            else 
                floyd[i][j] = prevy[i][j] = nexty[i][j] = inf;
        }
    while(m--){
        cin >> tmp >> tmp2 >> tmp3;
        if(tmp3 <= d){
            set_edge(tmp-1, tmp2-1, tmp3);
            set_edge(tmp2-1, tmp-1, tmp3);
        }
    }
    run_floyd();
    run_floyd();
    if(floyd[0][n-1] != inf)
        cout << floyd[0][n-1] << endl;
    else cout << "stuck" << endl;
}