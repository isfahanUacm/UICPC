#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int test = 1; test <= t; test++) {
        int n;
        cin >> n; 
        vector<int> sums(n);

        for (int i = 0; i < n; i++) {
            cin >> sums[i];
        }

        sort(sums.begin(), sums.end()); 
        int minSum = sums[0];

        cout << "Case " << test << ":\n";
        for (int i = 1; i <= 6; i++) {
            cout << i;
            if (i < 6) {
                cout << " ";
            }
            else {
                cout << endl;
            }
        }
        for (int i = 0; i < 6; i++) {
            int value = (minSum - 1) + i;
            cout << value;
            if (i < 5) {
                cout << " ";
            }
            else {
                cout << endl;
            }
        }
    }

    return 0;
}
