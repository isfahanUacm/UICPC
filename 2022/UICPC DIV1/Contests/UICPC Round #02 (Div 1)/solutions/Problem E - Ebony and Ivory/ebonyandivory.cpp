#include <bits/stdc++.h>
using namespace std;

set<int> black{2, 5, 7, 10, 12, 14, 17, 19, 22, 24, 26, 29, 31, 34, 36, 38,
                41, 43, 46, 48, 50, 53, 55, 58, 60, 62, 65, 67, 70, 72, 74, 
                77, 79, 82, 84, 86};

int s[4], l;
int cost[4][6][6][13];
int notes[10003];

int dp[10003][6];

int cdp(int i, int f){
    if(dp[i][f] != -1)
        return dp[i][f];
    if(i == l)
        return dp[i][f] = 0;
    int mn = min(notes[i-1], notes[i]);
    int mx = max(notes[i-1], notes[i]);
    if(mx == mn)
        return dp[i][f] = cdp(i+1, f);
    int ans = INT_MAX;
    for(int nf = 1; nf <= 5; nf++){
        int subp = cdp(i + 1, nf);
        if(subp == INT_MAX)
            continue;
        int index = 0;
        if(black.find(mn) != black.end())
            index += 2;
        if(black.find(mx) != black.end())
            index += 1;
        int act = (mn == notes[i-1]) ? (cost[index][f][nf][mx-mn]) : (cost[index][nf][f][mx-mn]);
        if(act == INT_MAX)
            continue;
        ans = min(ans, subp + act);
    }
    return dp[i][f] = ans;       
}

int main(){
    cin >> s[0] >> s[1] >> s[2] >> s[3] >> l;
    int fl, fu;
    for(int i = 0; i < 4; i++){
        for(int f1 = 1; f1 <= 5; f1++)
            for(int f2 = 1; f2 <= 5; f2++)
                for(int k = 1; k <= 12; k++)
                    cost[i][f1][f2][k] = INT_MAX;
        for(int j = 0; j < s[i]; j++){
            cin >> fl >> fu;
            for(int k = 1; k <= 12; k++)
                cin >> cost[i][fl][fu][k];
        }
    }
    for(int i = 0; i < l; i++)
        cin >> notes[i];
    for(int i = 0; i <= l; i++)
        for(int f = 1; f <= 5; f++)
            dp[i][f] = -1;
    int ans = INT_MAX;
    for(int f = 1; f <= 5; f++)
        ans = min(ans, cdp(1, f));
    cout << ans << endl;   
}