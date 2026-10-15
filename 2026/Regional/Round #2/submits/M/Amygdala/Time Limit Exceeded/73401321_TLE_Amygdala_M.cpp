#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n)
#define sint(s) string (s); cin >> (s)
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n'
#define int ll

int N = 1e6+10;
// #define endl '\n'

vector<int> prime;
void f(){
    prime.push_back(2);
    for(int i=3; i<N; i+=2){
        bool flag = true;
        for(int j : prime){
            if(i%j==0){
                flag = false;
                break;
            }
        }
        if(flag)
            prime.push_back(i);
    }
}

void solve()
{
    int dp[N];
    dp[0] = 0; dp[1] = 1;
    int i=0, j=0;
    for(int k=2; k<N; k++){
        dp[k] = dp[k-1];
        if(i<prime.size() && k == prime[i]){
            dp[k]++;
            i++;
        }
        if(j<prime.size() && k == prime[j]*prime[j]){
            dp[k]++;
            j++;
        }
    }
    int t;  cin >> t;
    while(t--){
        int m;  cin >>m;
        cout << dp[m] << '\n';
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    f();
    while(t--)
    {
        solve();
    }

    return 0;
}