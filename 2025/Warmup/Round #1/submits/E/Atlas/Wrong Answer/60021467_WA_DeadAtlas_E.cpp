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

    sort(arrDif, arrDif+n);

    int ans = -1;
    int tmpAns = 0;
    for (int i = n - 2; i >= 0; i--) {
        tmpAns = arrDif[i] - 1;
        int count = 0;
        for (int j = n - 2; j >= 0; j--) {
            if (arrDif[j] > tmpAns)
                count++;
            else {
                break;
            }
        }
        if (count + 1 == m) {
            ans = tmpAns;
            break;
        }
    }

    cout << ans << endl;




    return 0;
}
