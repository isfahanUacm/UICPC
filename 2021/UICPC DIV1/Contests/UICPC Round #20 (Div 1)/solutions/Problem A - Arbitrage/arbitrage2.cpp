#include <bits/stdc++.h>
using namespace std;

// Arbitrage?

#define inf LLONG_MIN

int n, m;
string names[203];
map<string, int> id;
double floyd[203][203];

char tmp[5];

int main(){
    while(1){
        scanf("%d", &n);
        if(!n)
            break;
        id.clear();
        for(int i = 0; i < n; i++)
            scanf("%s", tmp), names[i] = string(tmp), id[names[i]] = i;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                floyd[i][j] = i == j ? 1 : inf;
        scanf("%d", &m);
        while(m--){
            int u, v;
            double x, y;
            scanf("%s", tmp), u = id[string(tmp)];
            scanf("%s", tmp), v = id[string(tmp)];
            scanf("%lf:%lf", &x, &y);
            floyd[u][v] = y / x;
        }
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(floyd[i][k] != inf && floyd[k][j] != inf)
                        floyd[i][j] = max(floyd[i][j], floyd[i][k] * floyd[k][j]);
        bool ans = true;
        for(int i = 0; i < n; i++)
            if(floyd[i][i] > 1){
                ans = false;
                break;
            }
        cout << (ans ? "OK" : "Arbitrage") << endl;
    }
}