/*  Approach: similar to maks2-wrong.c, but consider all possible prefixes of
    the party list (after sorting heuristically) and only remove "unnecessary"
    parties before the last.

    This follows the intuition that the last party we select doesn't necessarily
    need to have a good seats/probability ratio -- it's only important that it
    has just enough seats to pass the 75 mark.

    @EXPECTED_RESULTS@: WRONG-ANSWER
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double max(double x, double y) { return x > y ? x : y; }

static double result_value(const int result[2])
{
    return -log(result[1]/100.0)/result[0];
}

static int compare_results(const void *a, const void *b)
{
    double x = result_value(a),
           y = result_value(b);
    return (x > y) - (x < y);
}

int main()
{
    int cases = 0;
    scanf("%d", &cases);
    while (cases--)
    {
        double answer = 0.0, prob = 100.0;
        int seats = 0, N = 0, R[150][2], i, j;

        scanf("%d", &N);
        for (i = 0; i < N; ++i) scanf("%d %d\n", &R[i][0], &R[i][1]);
        qsort(R, N, 2*sizeof(int), compare_results);

        for (i = 0; i < N; ++i)
        {
            seats += R[i][0];
            prob  *= R[i][1]/100.0;
            if (seats > 75)
            {
                int s = seats;
                double p = prob;
                for (j = i - 1; j >= 0; --j)
                {
                    if (s - R[j][0] > 75)
                    {
                        s -= R[j][0];
                        p /= R[j][1]/100.0;
                    }
                }
                answer = max(answer, p);
            }
        }

        printf("%lf\n", answer);
    }
    return 0;
}
