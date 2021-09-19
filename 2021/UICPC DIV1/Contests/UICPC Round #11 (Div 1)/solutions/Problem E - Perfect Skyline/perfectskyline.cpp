#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int n, s;
const ll masksize = (1 << 15) + 3;
ll buildings[20], blockes[20];
ll trace[20][masksize];
bool dp[20][masksize];
ll msum[masksize];

int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; ++i)
        cin >> blockes[i];
    for (int i = 0; i < s; ++i)
        cin >> buildings[i];
    
    for (ll mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)){
                msum[mask] += blockes[i] + msum[mask - (1 << i)];
                break;
            }
        }
    }
    fill_n(dp[s], 1 << n, true);
    for (int b_i = s-1; b_i >= 0; --b_i) {
        for (ll mask = 1; mask < (1 << n); ++mask) {
            ll prevy = mask;
            while(prevy){
                if (msum[prevy] == buildings[b_i] && dp[b_i+1][mask - prevy]){
                    dp[b_i][mask] = true;
                    trace[b_i][mask] = prevy;
                    break;
                }
                prevy = (prevy - 1) & mask;
            }
        }
    }
    if (dp[0][(1 << n) - 1]){
        ll mask = (1 << n) - 1, prevy;
        for (int b = 0; b < s; ++b) {
            prevy = trace[b][mask];
            vector<int> v;
            for (int i = 0; i < n; ++i) {
                if (prevy & (1 << i)){
                    v.push_back(i+1);
                }
            }
            cout << v.size();
            for(auto i : v){
                cout << " " << i;
            }
            cout << endl;
            mask = mask - prevy;
        }
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}

