#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n);
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            cin >> A[i];
            sum += A[i];
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            int newSum = sum - 2 * A[i];
            if (newSum % 2 == 0)
                count++;
        }

        cout << count << endl;
    }

    return 0;
}
