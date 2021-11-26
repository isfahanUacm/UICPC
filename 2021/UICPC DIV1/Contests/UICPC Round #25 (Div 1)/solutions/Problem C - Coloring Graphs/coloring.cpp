#include <bits/stdc++.h>
using namespace std;

// Graph Coloring

int n;
bool g[13][13], colorable[(1 << 11) + 3], dp[(1 << 11) + 3][13];

int main(){
    cin >> n;
    cin.ignore();
    string line;
    int x;
    for(int i = 0; i < n; i++){
        getline(cin, line);
        stringstream ss(line);
        while(ss >> x)
            g[i][x] = true;
    }
    for(int mask = 1; mask < (1 << n); mask++){
        colorable[mask] = true;
        for(int i = 0; i < n; i++){
            if(mask & (1 << i))
                for(int j = 0; j < n; j++)
                    if(j != i && (mask & (1 << j)) && g[i][j]){
                        colorable[mask] = false;
                        break;
                    }
            if(!colorable[mask])
                break;
        }
    }
    for(int mask = 1; mask < (1 << n); mask++)
        for(int k = 1; k <= n; k++){
            dp[mask][k] = colorable[mask];
            if(!dp[mask][k] && k > 1){
                int prevy = (mask - 1) & mask;
                while(prevy > 0){
                    if(colorable[mask - prevy] && dp[prevy][k-1]){
                        dp[mask][k] = true;
                        break;
                    }
                    prevy = (prevy - 1) & mask;
                }
            }         
        }
    int ans = 1;
    while(!dp[(1 << n) - 1][ans])
        ans++;
    cout << ans << endl;       
}