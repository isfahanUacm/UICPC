#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

double dp[200];
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
        sort(prob.begin(), prob.end());

        dp[0] = 1;
        for (auto x: prob) {
            for (int i = 160; i > 0; --i) {
                if (i >= x.first && dp[i - x.first] != -1) {
                    dp[i] = max(dp[i], dp[i - x.first] * x.second / 100);
                }
            }
        }

        double mx = -1;
        for (int i = 76; i <= 150; ++i) {
            mx = max(mx, dp[i]);
        }

        printf("%.10f", mx);
    }
}
