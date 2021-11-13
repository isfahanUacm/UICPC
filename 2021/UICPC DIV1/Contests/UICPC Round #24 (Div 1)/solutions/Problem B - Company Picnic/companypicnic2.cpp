#include <bits/stdc++.h>
using namespace std;

// Company Picnic

const int maxn = 1003;
int n;
double sp[maxn];
map<string, int> mp;
int k = 0;
vector<int> children[maxn];
pair<double, int> dp[maxn][2 + 3];

pair<double, int> cdp(int i, bool b){
    if(dp[i][b].first != -1)
        return dp[i][b];
    pair<double, int> ans;
    double sum = 0;
    int cnt = 0;
    for(int v : children[i]){
        auto tmp = cdp(v, 1);
        sum += tmp.first, cnt += tmp.second;
    }
    ans = {sum, cnt};
    if(b){
        for(int v : children[i]){
            auto tmp = cdp(v, 1);
            double sum2 = sum - tmp.first;
            int cnt2 = cnt - tmp.second;
            auto tmp2 = cdp(v, 0);
            sum2 += tmp2.first, cnt2 += tmp2.second;
            if(ans.second < cnt2 + 1)
                ans = {sum2 + min(sp[i], sp[v]), cnt2 + 1};
            else if(ans.second == cnt2 + 1){
                double avg = ((ans.second != 0) ? ans.first / ans.second : 0);
                if(avg < (sum2 + min(sp[i], sp[v])) / (cnt2 + 1))
                    ans = {sum2 + min(sp[i], sp[v]), (cnt2 + 1)};
            }
        }
    }
    return dp[i][b] = ans;
}

int main(){
    cin >> n;
    mp["CEO"] = n;
    for(int i = 0; i < n; i++){
        string x, y;
        double z;
        cin >> x >> z >> y;
        if(mp.find(x) == mp.end())
            mp[x] = k++;
        if(mp.find(y) == mp.end())
            mp[y] = k++;
        children[mp[y]].push_back(mp[x]);
        sp[mp[x]] = z;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 2; j++)
            dp[i][j] = {-1, -1};
    pair<double, int> ans = {0, 0};
    for(int v : children[n]){
        auto tmp = cdp(v, 1);
        ans.first += tmp.first, ans.second += tmp.second;
    }
    cout << ans.second << " " << fixed << setprecision(5) << ans.first / ans.second << endl;
}