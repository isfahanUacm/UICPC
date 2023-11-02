#include <iostream>

#define MAXN 50

using namespace std;

typedef long long ll;

ll binom[MAXN+1][MAXN+1];

int main() {

    for (int i = 0; i <= MAXN; ++i) binom[i][i] = binom[i][0] = 1;
    for (int i = 1; i <= MAXN; ++i)
        for (int j = 1; j < i; ++j)
            binom[i][j] = binom[i-1][j-1] + binom[i-1][j];

    int t;
    cin >> t;
    while (t--) {
        ll n, v1, v2, w;
        cin >> n >> v1 >> v2 >> w;

        ll unc = n-v1-v2;
        ll pr = 0;
        v2 += unc;
        for (int i = 0; i <= unc; ++i, --v2, ++v1)
            if (v2 < v1) pr += binom[unc][i];
//        cout << pr << endl;
        if (100*pr > w*(1ll << unc)) cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
        else if (pr == 0) cout << "RECOUNT!" << endl;
        else cout << "PATIENCE, EVERYONE!" << endl;
    }

    return 0;
}
