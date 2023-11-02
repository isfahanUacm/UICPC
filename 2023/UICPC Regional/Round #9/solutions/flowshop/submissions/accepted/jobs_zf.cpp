#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll c[1000][1000];

int main() {
    int n, m, x;
    cin >> n >> m;
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            cin >> x;
            c[i][j] = max((j==0?0:c[i][j-1]), (i==0?0:c[i-1][j])) + x;
        }
        cout << c[m-1][j] << (j+1==n?'\n':' ');
    }
    return 0;
}
