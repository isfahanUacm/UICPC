#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

double dp[200];

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<pair<int, int>> prob;
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            prob.emplace_back(a, b);
        }

        for (auto&x: dp) x = -1;
        sort(prob.begin(), prob.end(), comp);

        dp[0] = 1;
        for (auto x: prob) {
            for (int i = 160; i > 0; --i) {
                if (i >= x.first && dp[i - x.first] > -0.01) {
                    dp[i] = max(dp[i], dp[i - x.first] * x.second / 100);
                }
            }
        }

        double mx = -1;
        for (int i = 76; i <= 150; ++i) {
            mx = max(mx, dp[i]);
        }

        printf("%.6f", mx);
    }
}
