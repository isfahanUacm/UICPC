/*
 * @EXPECTED_RESULTS@: CORRECT
 */
#include <assert.h>
#include <stdio.h>

/* Another reasonably fast solution.  Takes O(N*M) time where M is the maximum
   value in the array. This can be improved to O(N*N) by compressing the input
   values to a compact range, but that's not necessary under the given
   constraints. */
static long long solve(int N, int L[])
{
    int count[1001] = { 0 };
    long long res = 0;
    int i, v, max = 0;

    /* For each element... */
    for (i = 0; i < N; ++i)
    {
        /* Element out of place? */
        if (L[i] < max)
        {
            /* Calculate number of steps required to insert it: */
            long long steps = 1;
            for (v = 0; v < L[i]; ++v) steps *= count[v] + 1;
            res += steps;
        }
        else  /* L[i] >= max */
        {
            max = L[i];
        }
        ++count[L[i]];
    }
    return res;
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
