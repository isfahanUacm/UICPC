#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int sum = 0;
        int arr[101];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        if(sum % 2 == 0)
            cout << n << "\n";
        else
            cout << 0 << "\n";
    }

    return 0;
}
