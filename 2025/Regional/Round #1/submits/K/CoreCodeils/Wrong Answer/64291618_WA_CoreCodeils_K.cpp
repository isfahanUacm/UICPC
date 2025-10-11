#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define endl "\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int x = 1;

    while (x <= t) {
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

        x++;
    }

    return 0;
}
