#include <iostream>
using namespace std;
const int MAXN = 2000000;
int omega[MAXN + 1];
long long ans[MAXN + 1];
void precompute() {
    for (int i = 2; i <= MAXN; i++) {
        if (omega[i] == 0) {
            for (int j = i; j <= MAXN; j += i) {
                omega[j]++;
            }
        }
    }

    for (int m = 2; m <= MAXN; m++) {
        long long ways = 1 << (omega[m] - 1);
        for (int b = m; b <= MAXN; b += m) {
            ans[b] += ways;
        }
    }
    for (int i = 2; i <= MAXN; i++) {
        ans[i] += ans[i - 1];
    }
}

int main() {
    precompute();
    int t;
    cin >> t;
        for (int i = 0; i < t;i++) {
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}