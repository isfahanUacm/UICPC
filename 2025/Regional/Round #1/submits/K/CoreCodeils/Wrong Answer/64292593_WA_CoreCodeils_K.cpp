#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#define fin cin

int main() {
    freopen("cubes.in", "r", stdin);
    int t;
    fin >> t;

    for (int x = 1; x <= t; x++) {
        int n;
        fin >> n;
        int* a = new int[n];
        for (int i = 0; i < n; i++) fin >> a[i];

        sort(a, a + n, greater<int>());

        int* b = new int[n];
        int index = 0;
        for (int i = 0; i < n - 1; i += 2) {
            b[n - index - 1] = a[i];
            b[index] = a[i + 1];
            index++;
        }
        if (n % 2 == 1)
            b[n / 2] = a[n - 1];

        cout << "Case " << x << ":\n";
        for (int i = 0; i < n; i++) cout << b[i] << " ";
        cout << "\n";

        delete[] a;
        delete[] b;
    }
    return 0;
}