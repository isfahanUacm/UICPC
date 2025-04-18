#include <algorithm>
#include <iostream>
#include <math.h>
#include <bits/ranges_algo.h>

using namespace std;

typedef long long ll;

int main() {


    int n, m;
    cin >> n >> m;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int arrDif[n-1];
    for (int i = 0; i < n-1; i++) {
        arrDif[i] = abs(arr[i+1] - arr[i]);
    }

    sort(arrDif, arrDif+n-1);

    int ans = -1;
    for (int i = 0; i <= arrDif[n - 1]; i++) {
        int count = 0;
        for (int j = 0; j < n - 1; j++) {
            if (arrDif[j] > i) {
                count++;
            }
            if (count == m) break;
        }
        if (count + 1 == m) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;




    return 0;
}
