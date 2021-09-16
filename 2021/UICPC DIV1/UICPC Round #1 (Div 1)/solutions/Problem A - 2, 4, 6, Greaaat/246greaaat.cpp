#include <bits/stdc++.h>
using namespace std;

// 2, 4, 6, Greaaat

#define long long long int

const int maxn = 503;
const int maxT = 4e5+3;

const long inf = LLONG_MAX;

int n, T, s[maxn], tr[maxT];
map<int, int> forw, backw;
long d[maxn], dp[maxT];
vector<int> ans;

int main(){
    cin >> n >> T;
    s[0] = d[0] = 1;
    for(int i = 1; i <= n; i++)
        cin >> s[i] >> d[i];
    for(int i = 0; i <= n; i++){
        if(s[i] > 0){
            if(forw.find(s[i]) == forw.end() || d[i] < d[forw[s[i]]])
                forw[s[i]] = i;
        }
        else if(s[i] < 0){
            if(backw.find(s[i]) == backw.end() || d[i] < d[backw[s[i]]])
                backw[s[i]] = i;
        }
    }
    fill_n(dp, 2*T+1, inf);
    dp[0] = 0;
    for(pair<int, int> p : forw){
        for(int i = 0; i+p.first <= 2*T; i++)
            if(dp[i] != inf && dp[i]+d[p.second] < dp[i+p.first])
                dp[i+p.first] = dp[i]+d[p.second], tr[i+p.first] = p.second;
    }
    for(pair<int, int> p: backw){
        for(int i = 2*T; i + p.first >= 0; i--)
            if(dp[i] != inf && dp[i]+d[p.second] < dp[i+p.first])
                dp[i+p.first] = dp[i]+d[p.second], tr[i+p.first] = p.second;
    }
    int it = T;
    while(it)
        ans.push_back(tr[it]), it -= s[tr[it]];
    cout << ans.size() << endl;
    for(int it : ans)
        cout << it+1 << " ";
    cout << endl;
}