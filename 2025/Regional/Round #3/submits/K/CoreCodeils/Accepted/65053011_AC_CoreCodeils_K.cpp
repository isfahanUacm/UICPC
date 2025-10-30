#include <iostream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define endl "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    if (m < n)
        cout << 0 << endl;

    if (m == n)
        cout << n << endl;

    if (m > n)
        cout << n + 1 << endl;

    return 0;
}