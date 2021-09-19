#include <bits/stdc++.h>
using namespace std;

// Restaurant Ratings

#define num long long int

int n, a[15 + 3], sum;
num ans, dp1[15 + 3][33], dp2[15 + 3][33][3];

num cdp1(int i, int s){
    if(dp1[i][s] != -1)
        return dp1[i][s];
    if(i == n)
        return dp1[i][s] = 1;
    num ans = 0;
    for(int c = 0; c <= 30; c++)
        if(c <= s)
            ans += cdp1(i+1, s-c);
    return dp1[i][s] = ans;
}

num cdp2(int i, int s, int j){
    if(dp2[i][s][j] != -1)
        return dp2[i][s][j];
    if(i == n)
        return dp2[i][s][j] = !s;
    num ans = 0;
    if(j){
        for(int c = 0; c < a[i]; c++)
            if(c <= s)
                ans += cdp2(i+1, s-c, 0);
        if(a[i] <= s)
            ans += cdp2(i+1, s-a[i], 1);
    }
    else{
        for(int c = 0; c <= 30; c++)
            if(c <= s)
                ans += cdp2(i+1, s-c, 0);
    }
    return dp2[i][s][j] = ans;
}

int main(){
    while(cin >> n){
        if(!n)
            break;
        sum = 0;
        for(int i = 0; i < n; i++)
            cin >> a[i], sum += a[i];
        ans = 0;
        if(sum){
            for(int i = 0; i <= n; i++)
                for(int s = 0; s < sum; s++)
                    dp1[i][s] = -1;
            ans += cdp1(0, sum-1);
        }
        for(int i = 0; i <= n; i++)
            for(int s = 0; s <= sum; s++)
                for(int j = 0; j < 2; j++)
                    dp2[i][s][j] = -1;
        ans += cdp2(0, sum, 1);
        cout << ans << endl;
    }
}