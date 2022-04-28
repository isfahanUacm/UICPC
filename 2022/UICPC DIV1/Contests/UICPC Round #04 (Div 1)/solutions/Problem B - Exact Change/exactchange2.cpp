#include <bits/stdc++.h>
using namespace std;

#define num long long int

num t, cost, n, coin[103];
pair<num, num> dp[103][10003];
const pair<num, num> d = {-1, -1};

pair<num, num> cdp (int i, num val){
    if (i == n){
        if (val <= 0)
            return {abs(val), 0};
        else
            return {INT_MAX, 0};
    }

    if (val <= 0)
        return {abs(val), 0};
    
    if (dp[i][val] != d)
        return dp[i][val];
    
    pair<num, num> ans1 = cdp(i + 1, val - coin[i]);
    ans1 = {ans1.first, ans1.second + 1};
    pair<num, num> ans2 = cdp(i + 1, val);

    return dp[i][val] = min(ans1, ans2);
}

int main(){
    cin >> t;
    while (t--){
        cin >> cost;
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> coin[i];
            for (int j = 0; j <= cost; j++)
                dp[i][j] = {-1, -1};
        }
        
        pair<num, num> ans = cdp(0, cost);
        
        cout << cost +  ans.first << " " << ans.second << endl;
    }
    return 0;
}