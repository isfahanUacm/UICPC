/*
 * Clumsy but correct solution to Older Brother.
 */

#include <stdio.h>
#include <assert.h>

using namespace std;


int main(void)
{
    int q = -1;
    scanf("%d", &q);
    assert(q >= 1 && q <= 1000000000);

    if (q == 1) {
        goto no;
    }

    for (int p = 2; p * p <= q; p++) {
        if (q % p == 0) {
            for (int k = 1; ; k++) {
                int t = 1;
                for (int i = 0; i < k; i++) {
                    t *= p;
                }
                if (t == q) {
                    goto yes;
                }
                if (t > q / p) {
                    goto no;
                }
            }
        }
    }

yes:
    fputs("YES\n", stdout);
    return 0;

no:
    fputs("NO\n", stdout);
    return 0;
}

// end
