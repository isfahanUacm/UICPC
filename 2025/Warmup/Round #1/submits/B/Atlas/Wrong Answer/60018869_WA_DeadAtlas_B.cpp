#include <iostream>
#include <math.h>
#include <valarray>

using namespace std;

typedef long long ll;

int main() {

    int n;
    cin >> n;

    int min = 0;
    int ans = 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        ans += arr[i];
        if (ans <= min)
            min = ans;
    }

    cout << abs(min) << endl;


    return 0;
}
