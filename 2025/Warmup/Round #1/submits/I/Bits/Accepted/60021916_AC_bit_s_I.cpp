#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

void solve()
{
    int n; cin >> n;
    vector<ll> inp(n);
    vector<string> rd (3);
    for(int i=0; i<n; i++) cin >> inp[i];
    vector<vector<ll>> dp(n, vector<ll>(2));
    dp[0][0] = inp[0];
    dp[0][1] = inp[0] * 2;

    rd[0] = "O";
    rd[1] = "M";


    for(int i=1; i<n; i++)
    {
        dp[i][0] = max(dp[i-1][1], dp[i-1][0]) + inp[i];
        dp[i][1] = dp[i-1][0] + inp[i]*2;

        string rd1 = rd[0] + "M";
        string rd0;
        if(dp[i-1][0] > dp[i-1][1]) rd0 = rd[0] + "O";
        else rd0 = rd[1] + "O";

        rd[0] = rd0;
        rd[1] = rd1;


//        for(auto x : rd) cout << x << endl;
//        cout << endl;
    }

//    for(auto x : dp)
//    {
//        for(auto y : x) cout << y << ' ';
//        cout << endl;
//    } cout << endl;

    cout << max(dp[n-1][0], dp[n-1][1]) << '\n';
    string ans = rd[0];
    if(dp[n-1][0] < dp[n-1][1]){
            ans = rd[1];
    }

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