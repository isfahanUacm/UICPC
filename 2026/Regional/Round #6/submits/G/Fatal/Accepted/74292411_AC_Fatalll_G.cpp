#include <iostream>
using namespace std;
int main() {
    int n , b;
    bool pos = false;
    int ans = 0;
    int bigNeg = -1001;
    cin >> n >> b;
    ans += b;
    int arr[n-1];
    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];
        if (arr[i] > 0) {
            pos = true;
            ans += arr[i];
        }else if (arr[i] > bigNeg) {
            bigNeg = arr[i];
        }
    }
    if (!pos) {
        if (ans >= abs(bigNeg)) {
            ans += bigNeg;
            cout << ans << endl;
        }
        else {
            cout << -1 << endl;
        }
    }else {
        cout << ans << endl;
    }
    return 0;
}