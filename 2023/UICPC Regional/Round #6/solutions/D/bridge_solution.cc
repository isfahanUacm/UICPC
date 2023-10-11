/*
 * Reference solution to Bridge Automation
 *
 * To compile:
 *   g++ -std=c++11 -Wall -O2 bridge_solution.cc
 *
 * Algorithm: dynamic programming.
 *
 * Time complexity O( nr_of_boats**2 ).
 */

// @EXPECTED_RESULTS@: CORRECT

#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <vector>

using namespace std;


static constexpr int INF_COST = 1000000;


/* 
 * Solve the problem.
 */
int solve(const vector<int>& boats)
{
    // Construct a table where tbl[k] is the minimum cost required
    // to pass the first k boats.
    // Initially only tbl[0] is valid.

    const int n = boats.size();
    vector<int> tbl(n + 1, INF_COST);
    tbl[0] = 0;

    for (int i = 0; i < n; i++) {

        // Assume the first i boats have already passed the bridge
        // at total cost tbl[i] and the bridge is now closed.
        //
        // Open the bridge such that boat (i) can pass after waiting
        // exactly 1800 seconds. Then consider the effects of keeping
        // the bridge open to pass any possible number of additional boats.

        int t = boats[i] + 1800;
        int c = tbl[i] + 120;

        for (int k = i; k < n; k++) {

            // Close the bridge immediately after boat K.
            if (boats[k] <= t) {
                c += 20;
                t += 20;
            } else {
                c += boats[k] - t + 20;
                t = boats[k] + 20;
            }

            // Update the cost for passing boats up to and including boat K.
            tbl[k+1] = min(tbl[k+1], c);
        }
    }

    // Return total cost to pass all boats.
    return tbl[n];
}


/* Main program. */
int main(void)
{
    // Read input.
    int nboat;
    scanf("%d", &nboat);
    assert(nboat >= 1 && nboat <= 4000);

    vector<int> boats;

    for (int i = 0; i < nboat; i++) {
        int t;
        int r = scanf("%d", &t);
        assert(r == 1);
        assert(t >= 60 && t <= 100000);
        assert(boats.size() == 0 || boats[i-1] + 20 <= t);
        boats.push_back(t);
    }

    // Solve problem.
    int ans = solve(boats);

    // Write output.
    printf("%d\n", ans);

    return 0;
}

// end
