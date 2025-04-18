#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

void solve()
{
    int n; cin >> n;
    vector<int> inp(n);
    vector<string> rd (3);
    for(int i=0; i<n; i++) cin >> inp[i];
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = inp[0];
    dp[0][1] = inp[0] * 2;
    dp[0][2] = inp[0];
    dp[1][0] = inp[0]*2 + inp[1];
    dp[1][1] = inp[0] + inp[1]*2;
    dp[1][2] = inp[0] + inp[1];

    rd[0] = "MO";
    rd[1] = "OM";
    rd[2] = "OO";


    for(int i=2; i<n; i++)
    {
        dp[i][0] = dp[i-1][1] + inp[i];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + inp[i]*2;
        dp[i][2] = max(dp[i-1][0], dp[i-1][2]) + inp[i];

        string rd0 = rd[1] + "O";
        string rd1;
        if(dp[i-1][0] > dp[i-1][2]) rd1 = rd[0] + "M";
        else rd1 = rd[2] + "M";
        string rd2;
        if(dp[i-1][0] > dp[i-1][2]) rd2 = rd[0] + "O";
        else rd2 = rd[2] + "O";

        rd[0] = rd0;
        rd[1] = rd1;
        rd[2] = rd2;

//        for(auto x : rd) cout << x << endl;
//        cout << endl;
    }

//    for(auto x : dp)
//    {
//        for(auto y : x) cout << y << ' ';
//        cout << endl;
//    } cout << endl;

    cout << max(max(dp[n-1][0], dp[n-1][1]) , dp[n-1][2]) << '\n';
    string ans = rd[0];
    if(dp[n-1][0] < dp[n-1][1]){
        if(dp[n-1][1] > dp[n-1][2])
            ans = rd[1];
        else
            ans = rd[2];
    }
    else if(dp[n-1][2] > dp[n-1][0])
        ans = rd[2];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
//    cin >> n;
    while(n--)
        solve();

    return 0;
}