/*
 * Reference solution to Manhattan Positioning System
 *
 *
 * To compile:
 *   gcc -std=c11 -Wall -O2 mps_solution_simple.c
 *
 *
 * This program picks the first beacon and enumerates all grid points
 * at distance exactly D from the beacon. For each such points, it checks
 * whether the point is at proper distance from all other beacons.
 *
 * When implemented naively, this strategy has time complexity
 *   O( max_distance * nr_of_beacons )
 *
 * However this program uses two optimizations:
 *  - Stop as soon as two solutions have been found.
 *  - When a grid point is found to be rejected by a beacon B_i, the next
 *    grid point is tested first against that same beacon B_i. In most cases
 *    the same beacon will also reject the next couple of points.
 *
 * With these two optimizations, the time complexity is believed to be
 *   O( max_distance + nr_of_beacons^2 )
 *
 * This program is easily fast enough on the given test input.
 */

// @EXPECTED_RESULTS@: CORRECT

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


#define MAX_BEACONS 1000

int nbeacon;
int beacon_x[MAX_BEACONS];
int beacon_y[MAX_BEACONS];
int beacon_d[MAX_BEACONS];


int check_point(int x, int y, int *blocking_beacon)
{
    int b = *blocking_beacon;
    for (int i = 0; i < nbeacon; i++) {
        if (abs(beacon_x[b] - x) + abs(beacon_y[b] - y) != beacon_d[b]) {
            *blocking_beacon = b;
            return 0;
        }
        b = (b + 1) % nbeacon;
    }
    return 1;
}


int main(void)
{
    scanf("%d", &nbeacon);
    assert(nbeacon >= 1 && nbeacon <= MAX_BEACONS);

    for (int i = 0; i < nbeacon; i++) {
        int r = scanf("%d %d %d", beacon_x+i, beacon_y+i, beacon_d+i);
        assert(r == 3);
        assert(beacon_x[i] >= -1000000 && beacon_x[i] <= 1000000);
        assert(beacon_y[i] >= -1000000 && beacon_y[i] <= 1000000);
        assert(beacon_d[i] >= 0 && beacon_d[i] <= 4000000);
    }

    int answer_x, answer_y, have_answer = 0;

    int x0 = beacon_x[0], y0 = beacon_y[0], d0 = beacon_d[0];
    int blocking_beacon = 0;

    if ((d0 == 0) && check_point(x0, y0, &blocking_beacon)) {
        answer_x = x0;
        answer_y = y0;
        have_answer++;
    }

    for (int i = 0; i < d0 && have_answer <= 1; i++) {
        int x = x0 - d0 + i, y = y0 - i;
        if (check_point(x, y, &blocking_beacon)) {
            answer_x = x;
            answer_y = y;
            have_answer++;
        }
    }

    for (int i = 0; i < d0 && have_answer <= 1; i++) {
        int x = x0 + i, y = y0 - d0 + i;
        if (check_point(x, y, &blocking_beacon)) {
            answer_x = x;
            answer_y = y;
            have_answer++;
        }
    }

    for (int i = 0; i < d0 && have_answer <= 1; i++) {
        int x = x0 + d0 - i, y = y0 + i;
        if (check_point(x, y, &blocking_beacon)) {
            answer_x = x;
            answer_y = y;
            have_answer++;
        }
    }

    for (int i = 0; i < d0 && have_answer <= 1; i++) {
        int x = x0 - i, y = y0 + d0 - i;
        if (check_point(x, y, &blocking_beacon)) {
            answer_x = x;
            answer_y = y;
            have_answer++;
        }
    }

    if (have_answer == 0) {
        printf("impossible\n");
    } else if (have_answer > 1) {
        printf("uncertain\n");
    } else {
        printf("%d %d\n", answer_x, answer_y);
    }

    return 0;
}

// end
