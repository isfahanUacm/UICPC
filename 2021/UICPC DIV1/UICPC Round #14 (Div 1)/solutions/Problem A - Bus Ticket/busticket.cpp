#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll dp[1000003];
int trips[1000003];
int s, p, m, n;

ll cdp(int i){
    if(i == n)
        return 0;
    if(dp[i] != -1)
        return dp[i];
    ll res = s + cdp(i+1);
    int nxt = upper_bound(trips+i, trips+n, trips[i]+m-1) - trips;
    res = min(res, p + cdp(nxt));
    return dp[i] = res;
}

int main()
{
    cin >> s >> p >> m >> n;
    for (int i = 0; i < n; ++i) {
        cin >> trips[i];
        dp[i] = -1;
    }
    cout << cdp(0) << endl;
    return 0;
}

