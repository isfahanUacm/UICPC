#include <bits/stdc++.h>
using namespace std;

// Perfect Skyline

#define num long long int

int n, s;
num h[15 + 3], b[15 + 3], mask_sum[(1 << 15) + 3];
bool dp[15 + 3][(1 << 15) + 3];
int trace[15 + 3][(1 << 15) + 3];
vector<int> ans;

int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> h[i];
    for(int i = 0; i < s; i++)
        cin >> b[i];
    for(int mask = 1; mask < (1 << n); mask++)
        for(int i = 0; i < n; i++)
            if(mask & (1 << i)){
                mask_sum[mask] += mask_sum[mask - (1 << i)] + h[i];
                break;
            }
    for(int i = s; i >= 0; i--)
        for(int mask = 0; mask < (1 << n); mask++){
            if(i == s){
                dp[i][mask] = 1;
                continue;
            }
            int prevy = mask;
            while(prevy){
                if(mask_sum[prevy] == b[i] && dp[i + 1][mask - prevy]){
                    dp[i][mask] = 1;
                    trace[i][mask] = prevy;
                    break;
                }
                prevy = (prevy - 1) & mask;
            }
        }
    if(!dp[0][(1 << n) - 1]){
        cout << -1 << endl;
        return 0;
    }
    int mask = (1 << n) - 1;
    for(int i = 0; i < s; i++){
        int submask = trace[i][mask];
        ans.clear();
        for(int j = 0; j < n; j++)
            if(submask & (1 << j))
                ans.push_back(j + 1);
        cout << ans.size() << " ";
        for(int a : ans)
            cout << a << " ";
        cout << endl;
        mask -= submask;
    }
}