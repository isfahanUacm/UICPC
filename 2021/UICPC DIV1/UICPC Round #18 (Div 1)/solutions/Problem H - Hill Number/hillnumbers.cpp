#include <bits/stdc++.h>
using namespace std;

// Hill Number

#define num long long int

string s;
int n, a[20];

num dp[20][10][2][2];

num cdp(int i, int pr, int inc, int l){
    if(dp[i][pr][inc][l] != -1)
        return dp[i][pr][inc][l];
    num ans = 0;
    if(i == n-1){
        if(l && inc)
            ans = max(0, a[n-1] - pr + 1);
        else if(l && !inc)
            ans = min(a[n-1], pr) + 1;
        else if(!l && inc)
            ans = 9 - pr + 1;
        else 
            ans = pr + 1;
    }
    else if(inc){
        for(int d = pr; d <= (l ? a[i] : 9); d++){
            ans += cdp(i+1, d, true, l && d == a[i]);
            if(d)
                ans += cdp(i+1, d-1, false, l && d == a[i]);
        }
    }
    else{
        for(int d = 0; d <= (l ? min(a[i], pr) : pr); d++)
            ans += cdp(i+1, d, false, l && d == a[i]);
    }
    return dp[i][pr][inc][l] = ans; 
}

int main(){
    cin >> s;
    n = s.size();
    for(int i = 0; i < n; i++)
        a[i] = s[i] - '0';
    bool inc = true;
    for(int i = 1; i < n; i++){
        if(inc){
            if(a[i] < a[i-1])
                inc = false;
        }
        else{
            if(a[i] > a[i-1]){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    for(int i = 0; i < 20; i++)
        for(int pr = 0; pr < 10; pr++)
            for(int inc = 0; inc < 2; inc++)
                for(int l = 0; l < 2; l++)
                    dp[i][pr][inc][l] = -1;
    cout << cdp(0, 0, 1, 1) - 1 << endl;
}