#include <bits/stdc++.h>
using namespace std;

// Bus Ticket

#define num long long int

num s, p, m, n;
num dp[1000003];
num a[1000003];

num cdp(int i){
    if(i == n)
        return 0;
    if(dp[i] != -1)
        return dp[i];
    num ans = s + cdp(i + 1);
    auto it = lower_bound(a + i, a + n, a[i] + m);
    it--;
    ans = min(ans, cdp(it - a + 1) + p);
    return dp[i] = ans;
}

int main(){
    for(int i = 0; i < 1000003; i++)
        dp[i] = -1;
    cin >> s >> p >> m >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    cout << cdp(0) << endl;
}