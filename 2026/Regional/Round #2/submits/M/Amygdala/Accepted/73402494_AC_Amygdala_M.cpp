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
    vector<bool> hash(N, true);
    for(int i=2; i<hash.size(); i++)
    {
        if(!hash[i]) continue;

        for(int j=i+i; j<hash.size(); j+=i) hash[j] = false;
        prime.push_back(i);
    }
}

void solve()
{
    int dp[N];
    dp[0] = 0; dp[1] = 1;
    int i=0;
    priority_queue<int> pq;
    for(int p : prime){
        int num = p*p;
        if(num > N) break;
        pq.push(-num);
    }
    for(int k=2; k<N; k++){
        dp[k] = dp[k-1];
        if(i<prime.size() && k == prime[i]){
            dp[k]++;
            i++;
        }
        else if(k == -pq.top()){
            dp[k]++;
            pq.push(-k*k);
            pq.pop();
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