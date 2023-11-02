#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

#define MAXN 200

using namespace std;

int best[MAXN][MAXN+1];
string str;

int solve(int i, int j) {
    if (i > j) return 0;
    if (best[i][j] == -1) {
        best[i][j] = 1+solve(i, j-1);

        for (int k = i; k < j; ++k)
            if (str[k] == str[j])
                best[i][j] = min(best[i][j], solve(i,k) + solve(k+1,j-1));
    }
    return best[i][j];
}

int main() {
    int t;
    cin >> t >> ws;
    while (t--) {
        memset(best, -1, sizeof(best));
        getline(cin, str);
        int n = str.length();
        cout << n + 2*solve(0, n-1) << endl;
    }
    return 0;
}
