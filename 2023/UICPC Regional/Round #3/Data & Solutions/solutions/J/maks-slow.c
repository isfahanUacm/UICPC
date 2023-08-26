/*
 * @EXPECTED_RESULTS@: TIMELIMIT
 */
#include <assert.h>
#include <stdio.h>

/* Brute-force simulation of the algorithm.  Returns the correct answer, but
   runs in O(res) time, or O(2**N) in the worst case.  That's too slow. */
static long long solve(int N, int L[])
{
    long long res = 0;

    for (;;)
    {
        int i, elem;

        /* Search for out-of-order element at index i: */
        for (i = 1; i < N; ++i) if (L[i] < L[i - 1]) break;

        /* All sorted? */
        if (i == N) return res;

        /* Rotate elements L[0..i] so that L[i] is now in front: */
        elem = L[i];
        for (; i > 0; --i) L[i] = L[i - 1];
        L[0] = elem;

        /* One step performed; count it. */
        ++res;
    }
}

int main(int argc, char *argv[])
{
    int cases = 0, res = scanf("%d", &cases);
    assert(res == 1);
    assert(0 < cases && cases <= 100);
    while (cases-- > 0)
    {
        int N = 0, L[50] = { 0 }, n;
        long long answer;
        res = scanf("%d", &N);
        assert(res == 1);
        assert(1 <= N && N <= 50);
        for (n = 0; n < N; ++n)
        {
            res = scanf("%d", &L[n]);
            assert(res == 1);
            assert(1 <= L[n] && L[n] <= 1000);
        }
        answer = solve(N, L);
        assert(answer >= 0);
        printf("%lld\n", answer);
    }
    return 0;
}
