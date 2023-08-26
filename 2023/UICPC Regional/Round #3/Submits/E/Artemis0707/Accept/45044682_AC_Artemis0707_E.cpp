#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        string a;
        cin >> a;
        int n = sqrt(a.length());
        char arr[n][n];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                arr[i][j] = a[i * n + j];
            }
        }

        for (int j = n - 1; j >= 0; --j) {
            for (int i = 0; i < n; ++i) {
                cout << arr[i][j];
            }
        }
        if (tc)
        cout << endl;
    }
}
