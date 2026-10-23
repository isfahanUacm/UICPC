#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t; 
        vector<int> queries(t);
        int max_n = 2;

        for (int i = 0; i < t; i++) {
            cin >> queries[i];
            if (queries[i] > max_n) {
                max_n = queries[i];
            }
        }
        vector<int> omega(max_n + 1, 0);
        vector<long long> ans(max_n + 1, 0);

        for (int i = 2; i <= max_n; i++) {
            if (omega[i] == 0) {
                for (int j = i; j <= max_n; j += i) {
                    omega[j]++;
                }
            }
        }
        for (int m = 2; m <= max_n; m++) {
            long long ways = 1 << (omega[m] - 1);
            for (int b = m; b <= max_n; b += m) {
                ans[b] += ways;
            }
        }
        for (int i = 2; i <= max_n; i++) {
            ans[i] += ans[i - 1];
        }
        for (int i = 0; i < t; i++) {
            cout << ans[queries[i]] << endl;
        }
    return 0;
}