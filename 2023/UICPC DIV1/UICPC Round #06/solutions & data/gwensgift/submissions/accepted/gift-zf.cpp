#include <iostream>

using namespace std;

typedef unsigned long long ull;

bool marked[1000];

int main() {
    ull fact[30];
    fact[0] = 1;
    for (int i = 1; i < 30; ++i) fact[i] = fact[i-1]*i;

    ull n, k;
    cin >> n >> k;

    ull digs[1000], out[1000];
    for (int i = 0; i < n-1; ++i) {
        for (digs[i] = 0; n-2-i < 30 && (digs[i]+1) < (k+fact[n-2-i]-1)/fact[n-2-i]; ++digs[i]);
        if (digs[i]) k -= digs[i]*fact[n-2-i];
    }

    marked[0] = true;
    ull sum = 0;
    for (int i = 0; i < n-1; ++i)
        for (out[i] = 1; ; ++out[i])
            if (!marked[(sum+out[i])%n]) {
                if (digs[i]) --digs[i];
                else {
                    marked[(sum+out[i])%n] = true;
                    sum += out[i];
                    break;
                };
            }

    for (int i = 0; i < n-1; ++i) cout << out[i] << (i==n-2?'\n':' ');

    return 0;
}
