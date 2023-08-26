/*  Combination of greedy approach (which works well for large cases) and
    brute-force approach (which works well for small cases).  Not sure if
    contestants are going to put this much effort into an incorrect solution,
    but ideally this shouldn't pass.

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

static double solve_greedy(int N, int R[][2])
{
    int seats = 0, i;
    double answer = 100.0;

    /* Sort heuristically. */
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
    return answer;
}

static double max(double x, double y) { return x < y ? y : x; }

static double dfs(int N, int R[][2], int seats, double prob)
{
    if (seats > 75) return prob;
    if (N == 0) return 0.0;
    return max(dfs(N - 1, R + 1, seats, prob),
               dfs(N - 1, R + 1, seats + R[0][0], prob*(R[0][1]/100.0)));
}

static double solve_bruteforce(int N, int R[][2])
{
    return dfs(N, R,  0, 100.0);
}

int main()
{
    int cases = 0;
    scanf("%d", &cases);
    while (cases--)
    {
        int N = 0, R[150][2], seats = 0, i;

        scanf("%d", &N);
        for (i = 0; i < N; ++i) scanf("%d %d\n", &R[i][0], &R[i][1]);
        printf("%lf\n", (N <= 25) ? solve_bruteforce(N, R) : solve_greedy(N, R));
    }
    return 0;
}
