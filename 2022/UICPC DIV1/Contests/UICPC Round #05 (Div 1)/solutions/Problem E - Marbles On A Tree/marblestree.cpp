#include <bits/stdc++.h>
using namespace std;

int n, v, m, d, par[10003], marbles[10003], a, noc[10003];

int main(){
    
    while (cin >> n && n){
        queue<int> q;
        
        fill_n(par, n + 1, -1);
        
        for (int i = 0; i < n; i++){
            cin >> v >> m >> d;
            marbles[v] = m;
            noc[v] = d;
            for (int j = 0; j < d; j++)
                cin >> a, par[a] = v;
        }

        for (int i = 1; i <= n; i++)
            if (!noc[i])
                q.push(i);
        
        int cur, dif, res = 0;
        
        while(!q.empty()){
            cur = q.front(); q.pop();
            
            if (par[cur] == -1)
                continue;
            
            dif = marbles[cur] - 1;
            res += abs(dif);
            marbles[cur] = 1;
            marbles[par[cur]] += dif;
            noc[par[cur]]--;
            
            if (!noc[par[cur]])
                q.push(par[cur]);
        }

        cout << res << endl;
    }
    
    return 0;
}