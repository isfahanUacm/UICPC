#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
     freopen("cubes.in", "r",stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<long long int> arr(n);
        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
        }
        sort(arr.begin(), arr.end());
        vector<long long int> even;
        vector<long long int> odd;
        for (int j = 0; j < n; ++j) {
            if (arr[j] % 2 == 0) {
                even.push_back(arr[j]);
            } else {
                odd.push_back(arr[j]);
            }
        }
        cout << "Case " << i + 1 << ":" << endl;
        for (int j = even.size() - 1; j >= 0; j--) {
            cout << even[j] << " ";
        }
        for (int j = 0; j < odd.size(); j++) {
            cout << odd[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
