#include <bits/stdc++.h>
using namespace std;

// Colorland

const int maxn = 2e5 + 3;
const int inf = INT_MAX;

int n, color[maxn], dp[maxn];
vector<int> ind[6]; 

int main(){
    cin >> n;
    string c;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == "Blue")
            color[i] = 0;
        else if(c == "Orange")
            color[i] = 1;
        else if(c == "Pink")
            color[i] = 2;
        else if(c == "Green")
            color[i] = 3;
        else if(c == "Red")
            color[i] = 4;
        else if(c == "Yellow")
            color[i] = 5;
        ind[color[i]].push_back(i);
    }
    dp[n-1] = 1;
    for(int i = n-2; i >= 0; i--){
        dp[i] = inf;
        for(int c = 0; c < 6; c++){
            if(ind[c].empty())
                continue;
            auto it = upper_bound(ind[c].begin(), ind[c].end(), i);
            if(it == ind[c].end())
                continue;
            dp[i] = min(dp[i], 1 + dp[*it]);
        }
    }
    int ans = INT_MAX;
    for(int c = 0; c < 6; c++)
        if(!ind[c].empty())
            ans = min(ans, dp[ind[c].front()]);
    cout << ans << endl;
}