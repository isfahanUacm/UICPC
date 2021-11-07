#include <bits/stdc++.h>
using namespace std;

// NTNU Orienteering

#define num long long int

int c, l, dp[1003];
num floyd[203][203];
pair<num, pair<num, int>> courses[1003];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> c >> l;
        int m = (c * (c - 1)) / 2, u, v, w;
        while(m--)
            cin >> u >> v >> w, floyd[u][v] = w, floyd[v][u] = w;
        for(int k = 0; k < c; k++)
            for(int i = 0; i < c; i++)
                for(int j = 0; j < c; j++)
                    floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
        for(int i = 0; i < l; i++)
            cin >> courses[i].second.second >> courses[i].first >> courses[i].second.first;
        sort(courses, courses + l);
        int ans = 0;
        for(int i = l - 1; i >= 0; i--){
            dp[i] = 1;
            for(int j = i + 1; j < l; j++)
                if(courses[i].second.first + floyd[courses[i].second.second][courses[j].second.second] <= courses[j].first)
                    dp[i] = max(dp[i], 1 + dp[j]);
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
}