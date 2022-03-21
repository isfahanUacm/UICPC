#include <bits/stdc++.h>
using namespace std;

// The Uxuhul Voting System

int n, m;

int pref[103][11];
int dp[103][11];

int cdp(int i, int mask){
    if(i == m)
        return mask;
    if(dp[i][mask] != -1)
        return dp[i][mask];
    int subp = cdp(i + 1, mask & 4 ? mask - 4 : mask + 4);
    int mpref = pref[i][subp];
    int subp2 = cdp(i + 1, mask & 2 ? mask - 2 : mask + 2);
    if(pref[i][subp2] < mpref){
        subp = subp2;
        mpref = pref[i][subp2];
    }
    int subp3 = cdp(i + 1, mask & 1 ? mask - 1 : mask + 1);
    if(pref[i][subp3] < mpref){
        subp = subp3;
        mpref = pref[i][subp3];
    }
    return dp[i][mask] = subp;
}

int main(){
    cin >> n;
    while(n--){ 
        cin >> m;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < 8; j++){
                cin >> pref[i][j];
                dp[i][j] = -1;
            }
        int ans = cdp(0, 0);
        cout << ((ans & 4) ? "Y" : "N") << ((ans & 2) ? "Y": "N") << ((ans & 1) ? "Y" : "N") << endl; 
    }
}