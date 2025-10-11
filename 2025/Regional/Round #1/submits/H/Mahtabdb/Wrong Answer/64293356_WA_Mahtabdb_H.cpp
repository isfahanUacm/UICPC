#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int test = 1; test <= t; test++) {
        int n;
        cin >> n;
        vector<int> sums(n);
        for (int i = 0; i < n; i++) cin >> sums[i];

        sort(sums.begin(), sums.end());
        int minSum = sums[0];

        cout << "Case " << test << ":\n";

        int count1 = 0;
        for (int i = 1; i <= 1000 && count1 < 6; i++) {
            cout << i;
            count1++;
            if (count1 < 6) cout << " ";
            else cout << endl;
        }

        int start2 = max(1, minSum - 1);
        int count2 = 0;
        for (int i = start2; i <= 1000 + start2 && count2 < 6; i++) {
            cout << i;
            count2++;
            if (count2 < 6) cout << " ";
            else cout << endl;
        }
    }

    return 0;
}
