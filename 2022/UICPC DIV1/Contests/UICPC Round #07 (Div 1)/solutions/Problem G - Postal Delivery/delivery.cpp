#include <bits/stdc++.h>
using namespace std;

// Postal Delivery

int n, k;
vector<pair<int, int>> pos, neg;

int solve(vector<pair<int, int>> & pos){
    int ans = 0;
    while(!pos.empty()){
        ans += 2 * pos.back().first;
        int sum = 0;
        while(sum <= k && !pos.empty()){
            sum += pos.back().second;
            if(sum <= k)
                pos.pop_back();
            else
                pos.back().second = sum - k;
        }
    }
    return ans;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x, t;
        cin >> x >> t;
        if(x > 0)
            pos.push_back({x, t});
        else
            neg.push_back({-x, t});
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    cout << solve(pos) + solve(neg) << endl;
}