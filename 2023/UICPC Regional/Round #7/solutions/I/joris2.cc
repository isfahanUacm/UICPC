/*
 * Clumsy but correct solution to Older Brother.
 */

#include <stdio.h>
#include <assert.h>

using namespace std;


int prime_factor(int q)
{
    for (int p = 2; p * p <= q; p++) {
        if (q % p == 0) {
            return p;
        }
    }

    return q;
}


int main(void)
{
    int q = -1;
    scanf("%d", &q);
    assert(q >= 1 && q <= 1000000000);

    int p = prime_factor(q);

    if (p > 1) {
        while (q > 1) {
            if (prime_factor(q) != p) {
                break;
            }
            q /= p;
        }
    }

    bool ans = (p > 1 && q == 1);

    fputs(ans ? "YES\n" : "NO\n", stdout);
    return 0;
}

// end
