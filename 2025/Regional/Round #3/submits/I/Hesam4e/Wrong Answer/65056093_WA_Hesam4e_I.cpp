#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    string re[n];

    for (int i = 0; i < n; ++i) {
        cin >> m;
        string arr[m];
        for (int j = 0; j < m; ++j) {
            cin >> arr[j];
        }
        sort(arr, arr + m);
        for (int j = 0; j < m; ++j) {
            if (i == 0)
                re[0] = arr[0];
            if (re[i - 1] <= arr[j])
                re[i] = arr[j];
        }

    }
    for (int i = 0; i < n; ++i) {
        if (re[i]=="") {
            cout << "impossible";
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << re[i]<<endl;
    }
    return 0;
}