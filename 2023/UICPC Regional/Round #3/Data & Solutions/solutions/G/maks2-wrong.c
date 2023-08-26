/*  Approach: order parties by absolute suitablity (defined as seats/log(prob))
    and then greedily take the most suitable parties until the desired number
    of seats has been acquired.

    @EXPECTED_RESULTS@: WRONG-ANSWER
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
        double answer = 100.0;
        int N = 0, R[150][2], seats = 0, i;

        scanf("%d", &N);
        for (i = 0; i < N; ++i) scanf("%d %d\n", &R[i][0], &R[i][1]);
        qsort(R, N, 2*sizeof(int), compare_results);

        /* Greedily add parties to the coalition until we have a majority: */
        for (i = 0; i < N; ++i)
        {
            seats  += R[i][0];
            answer *= R[i][1]/100.0;
            if (seats > 75) break;
        }

        /* Now throw out unnecessary parties; */
        for ( ; i >= 0; --i)
        {
            if (seats - R[i][0] > 75)
            {
                seats  -= R[i][0];
                answer /= R[i][1]/100.0;
            }
        }

        printf("%lf\n", answer);
    }
    return 0;
}
