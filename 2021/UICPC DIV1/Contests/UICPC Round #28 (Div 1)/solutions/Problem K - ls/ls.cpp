#include <bits/stdc++.h>
using namespace std;

// ls

string p, s;
int dp[103][103];

bool cdp(int i, int j){
    if(dp[i][j] != -1)
        return dp[i][j];
    if(i == 0 && j == 0)
        return dp[i][j] = true;
    bool ans = false;
    if(i >= 1 && p[i-1] == '*'){
        if(cdp(i-1, j))
            return dp[i][j] = true;
        if(j >= 1 && cdp(i, j-1))
            return dp[i][j] = true;
    }
    if(i >= 1 && j >= 1 && p[i-1] == s[j-1] && cdp(i-1, j-1))
        return dp[i][j] = true;
    return dp[i][j] = false;
}

int main(){
    cin >> p;
    int n;
    cin >> n;
    while(n--){
        cin >> s;
        for(int i = 0; i < 103; i++)
            for(int j = 0; j < 103; j++)
                dp[i][j] = -1;
        if(cdp(p.size(), s.size()))
            cout << s << endl;
    }
}