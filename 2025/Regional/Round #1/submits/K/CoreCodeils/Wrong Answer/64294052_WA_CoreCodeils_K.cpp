#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    freopen("cubes.in", "r", stdin);
    int t;
    cin >> t;

    for (int x = 1; x <= t; x++) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a, a + n);
        reverse(a, a + n);

        int b[n];
        int index = 0;
        for (int i = 0; i < n - 1; i+=2) {
            b[n - index - 1] = a[i];
            b[index] = a[i + 1];
            index++;
        }
        if (n % 2 == 1)
            b[n / 2] = a[n - 1];


        cout << "Case " << x << ":" << endl;
        for (int i = 0; i < n; i++) cout << b[i] << " ";
        cout << endl;
    }
    return 0;
}
