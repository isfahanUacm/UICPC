#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("dice.in", "r", stdin);
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

       
        for (int i = 1; i <= 6; i++) {
            cout << i;
            if (i < 6) cout << " ";
            else cout << endl;
        }

    
        int start = max(1, minSum - 1);
        for (int i = 0; i < 6; i++) {
            cout << (start + i);
            if (i < 5) cout << " ";
            else cout << endl;
        }
    }
}
