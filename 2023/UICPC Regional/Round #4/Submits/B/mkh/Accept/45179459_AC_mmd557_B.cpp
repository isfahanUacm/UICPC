#include <bits/stdc++.h>
using namespace std;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;



int main() {
    long a, b;
    cin >>a>>b;
    vl dp(b+1);
    dp[0] = 1;
    for (int i = 1; i < dp.size(); ++i) {
        dp[i] = dp[i-1] + (pow(2, i));
    }
    if (dp[b] >= a) {
        cout << "yes";
    }else {
        cout << "no";
    }
    return 0;
}

