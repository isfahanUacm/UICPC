#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int n;
ll p[18], sum, dp[18][33][5];

ll cdp(int i, ll rem_sum, int win){
    if (i == n) {
        if (rem_sum > 0 || (rem_sum == 0 && win))
            return 1;
        return 0;
    }
    if (dp[i][rem_sum][win] != -1)
        return dp[i][rem_sum][win];
    ll res = 0;
    for (int point = rem_sum; point >= 0; --point) {
        if (win == 1) {
            if (point < p[i])
                res += cdp(i+1, rem_sum - point, 2);
            else if (point == p[i])
                res += cdp(i+1, rem_sum - point, 1);
            else
                res += cdp(i+1, rem_sum - point, 0);
        }
        else
            res += cdp(i+1, rem_sum - point, win);
    }
    return dp[i][rem_sum][win] = res;
}

int main()
{
    while (cin>>n && n) {
        sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> p[i], sum += p[i];
            for (int j = 0; j < 33; ++j) {
                dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
            }
        }
        cout << cdp(0, sum, 1) << endl;
    }
    return 0;
}

