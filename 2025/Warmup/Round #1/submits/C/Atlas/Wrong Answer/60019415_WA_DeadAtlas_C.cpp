#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;

int main() {

    int n, k;
    cin >> n >> k;
    int arrk[k];
    int ans = n;

    for (int i = 0; i < k; i++) {
        cin >> arrk[i];
    }

    int tmpk = k;

    for (int i = 0; i < k; i++) {
        ans += tmpk * arrk[i];
        tmpk--;
    }

    cout << ans << endl;

    return 0;
}
