#include <bits/stdc++.h>
using namespace std;

// String Factoring

int n;
string str;

int dp[203][203];

int cdp(int lptr, int rptr){
    if(dp[lptr][rptr] != -1)
        return dp[lptr][rptr];
    if(lptr == rptr)
        return dp[lptr][rptr] = 1;
    int len = rptr - lptr + 1;
    int ans = len;
    for(int k = len-1; k >= 1; k--)
        if(len % k == 0){
            bool factor = true;
            for(int i = k; i < len; i++)
                if(str[lptr+i] != str[lptr+i%k]){
                    factor = false;
                    break;
                }
            if(factor)
                ans = min(ans, cdp(lptr, lptr+k-1));
        }
    for(int p = lptr; p < rptr; p++)
        ans = min(ans, cdp(lptr, p) + cdp(p+1, rptr));
    return dp[lptr][rptr] = ans;
}

int main(){
    cin >> str;
    n = str.size();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dp[i][j] = -1;
    cout << cdp(0, n-1) << endl;
}