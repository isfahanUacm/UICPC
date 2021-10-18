#include <bits/stdc++.h>
using namespace std;

// Restaurant Orders

int n;
int dish[103];
int dp[30003][103];

vector<int> path;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> dish[i];
    for(int s = 0; s <= 30000; s++){
        for(int i = 0; i < n; i++){
            if(s == 0)
                dp[s][i] = 0;
            else{
                dp[s][i] = -2;
                if(i > 0){
                    if(dp[s][i-1] == -1){
                        dp[s][i] = -1;
                        continue;
                    }
                    else if(dp[s][i-1] >= 0 || dp[s][i-1] == -3)
                        dp[s][i] = -3;
                }
                if(s - dish[i] >= 0){
                    if(dp[s-dish[i]][i] == -1){
                        dp[s][i] = -1;
                        continue;
                    }
                    if(dp[s-dish[i]][i] >= 0 || dp[s-dish[i]][i] == -3){
                        if(dp[s][i] == -3){
                            dp[s][i] = -1;
                            continue;
                        }
                        dp[s][i] = i;
                    }
                }
            }
        }
    }
    int m;
    cin >> m;
    while(m--){
        int order;
        cin >> order;
        if(dp[order][n-1] == -2)
            cout << "Impossible" << endl;
        else if(dp[order][n-1] == -1)
            cout << "Ambiguous" << endl;
        else{
            path.clear();
            int it = order;
            int i = n-1;
            while(it != 0){
                if(dp[it][i] == -3)
                    i--;
                else{
                    path.push_back(dp[it][i]+1);
                    it -= dish[dp[it][i]];
                }
            }
            sort(path.begin(), path.end());
            for(int d: path)
                cout << d << " ";
            cout << endl;
        }
    }
}