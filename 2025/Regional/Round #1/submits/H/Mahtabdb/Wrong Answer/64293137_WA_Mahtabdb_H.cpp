#include <iostream>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int test = 1; test <= t; test++) {
        int n;
        cin >> n;
        set<int> sums;
        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            sums.insert(value);
        }

        set<int> tas1;
        set<int> tas2;
        for (int i = 1; i <= 1000; i++) {
            for (int j = 1; j <= 1000; j++) {
                int sum = i + j;
                if (sums.find(sum) != sums.end()) {
                    tas1.insert(i);
                    tas2.insert(j);
                }
            }
        }
        cout << "Case " << test << ":\n";

        for (auto it = tas1.begin(); it != tas1.end(); ++it) {
            if (it != tas1.begin()) cout << " ";
            cout << *it;
        }
        cout << endl;
        for (auto it = tas2.begin(); it != tas2.end(); ++it) {
            if (it != tas2.begin()) cout << " ";
            cout << *it;
        }
        cout << endl;
    }

    return 0;
}
