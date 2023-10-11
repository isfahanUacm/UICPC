/*
 * Reference solution to Manhattan Positioning System
 *
 *
 * To compile:
 *   g++ -std=c++11 -Wall -O2 mps_solution_fast.cc
 *
 *
 * Strategy:
 * Pick the first beacon and describe the set of points at distance D from
 * the beacon as a set of 4 straight line segments. These line segments
 * become the working set. Then consider all other beacons one-by-one and
 * intersect the working set with those beacon's point sets. After processing
 * all beacons, the working set describes exactly the set of possible
 * receiver locations.
 *
 * Time complexity O( nr_of_beacons ).
 */

// @EXPECTED_RESULTS@: CORRECT

#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;


typedef pair<int,int> Point;
struct Beacon { int x, y, d; };
struct Answer { Point recvpos; bool impossible; bool uncertain; };


/*
 * Check whether a given point is a possible receiver location.
 *
 * Return true if the point matches all beacon distance data;
 * return false otherwise.
 */
bool possible_location(const vector<Beacon>& beacons, const Point& point)
{
    for (const Beacon& beacon : beacons) {
        if (abs(beacon.x - point.first) +
            abs(beacon.y - point.second) != beacon.d) {
            return false;
        }
    }
    return true;
}


/*
 * Find possible receiver locations on a given straight line segment.
 *
 * Consider the straight line segment with equation
 *   X + ysign * Y == rhs
 * and X constrained to xstart <= X <= xend.
 *
 * Find receiver locations on this straight line that are consistent
 * with all beacon distance data.
 *
 * Return an empty set if there are no solutions.
 * Return a single solution if there is exactly one solution.
 * If there are more than two solutions, return any two solutions.
 */
set<Point> find_solutions(const vector<Beacon>& beacons,
                          int xstart, int xend, int ysign, int rhs)
{
    set<Point> points;

    // Consider each beacon.
    for (const Beacon& beacon : beacons) {
        int x = beacon.x, y = beacon.y, d = beacon.d;

        if (x + d + ysign * y == rhs) {
            // The specified line segment is colinear with (X+D,Y) .. (X,Y+-D).
            // Restrict X to the intersection of the two segments.
            xstart = max(xstart, x);
            xend   = min(xend, x + d);
        } else if (x - d + ysign * y == rhs) {
            // The specified line segment is colinear with (X-D,Y) .. (X,Y-+D).
            // Restrict X to the intersection of the two segments.
            xstart = max(xstart, x - d);
            xend   = min(xend, x);
        } else {
            // Find the two intersections between the specified line segment
            // and the two lines of this beacon's perimeter that are
            // orthogonal to the specified line segment.
            // These intersections may not exist (due to odd/even constraint).
            // Otherwise the intersections may not fall outside the selected
            // line segments, but we don't care about that.
            // Just take the two points and check whether they are solutions
            // with respect to all beacons.
            int rhs2 = x - d - ysign * y;
            if ((rhs - rhs2) % 2 == 0) {
                Point p((rhs + rhs2) / 2, ysign * (rhs - rhs2) / 2);
                if (possible_location(beacons, p)) {
                    points.insert(p);
                }
            }
            rhs2 = x + d - ysign * y;
            if ((rhs - rhs2) % 2 == 0) {
                Point p((rhs + rhs2) / 2, ysign * (rhs - rhs2) / 2);
                if (possible_location(beacons, p)) {
                    points.insert(p);
                }
            }
            return points;
        }

        if (xstart > xend) {
            // Our specified line segment has become constrained to an
            // empty segment. Return an empty set of solutions.
            return points;
        }
    }

    // The intersection of all beacon perimiters is still a non-empty
    // line segment. All points on this segment are possible receiver
    // locations. If the segment contains exactly one point, return it,
    // otherwise return the beginning and end.
    points.insert(make_pair(xstart, (rhs - xstart) * ysign));
    points.insert(make_pair(xend,   (rhs - xend) * ysign));

    return points;
}


/* 
 * Solve the problem.
 */
Answer solve(const vector<Beacon>& beacons)
{
    set<Point> points;

    assert(beacons.size() > 0);
    int x = beacons[0].x, y = beacons[0].y, d = beacons[0].d;

    // Check line segment from (X-D,Y) .. (X,Y+D).
    set<Point> tp;
    tp = find_solutions(beacons, x - d, x, -1, x - d - y);
    points.insert(tp.begin(), tp.end());

    // Check line segment from (X-D,Y) .. (X,Y-D).
    tp = find_solutions(beacons, x - d, x, +1, x - d + y);
    points.insert(tp.begin(), tp.end());

    // Check line segment from (X,Y+D) .. (X+D,Y).
    tp = find_solutions(beacons, x, x + d, +1, x + d + y);
    points.insert(tp.begin(), tp.end());

    // Check line segment from (X,Y-D) .. (X+D,Y).
    tp = find_solutions(beacons, x, x + d, -1, x + d - y);
    points.insert(tp.begin(), tp.end());

    // Determine whether we have zero, one or more solutions.
    Answer ans;
    ans.impossible = points.empty();
    ans.uncertain  = points.size() > 1;
    for (const Point& p : points) {
        ans.recvpos = p;
        break;
    }

    return ans;
}


/* Main program. */
int main(void)
{
    // Read input.
    int nbeacon;
    scanf("%d", &nbeacon);
    assert(nbeacon >= 1 && nbeacon <= 1000);

    vector<Beacon> beacons;

    for (int i = 0; i < nbeacon; i++) {
        Beacon b;
        scanf("%d %d %d", &b.x, &b.y, &b.d);
        assert(b.x >= -1000000 && b.x <= 1000000);
        assert(b.y >= -1000000 && b.y <= 1000000);
        assert(b.d >= 0 && b.d <= 4000000);
        beacons.push_back(b);
    }

    // Solve problem.
    Answer ans = solve(beacons);

    // Write output.
    if (ans.impossible) {
        printf("impossible\n");
    } else if (ans.uncertain) {
        printf("uncertain\n");
    } else {
        printf("%d %d\n", ans.recvpos.first, ans.recvpos.second);
    }

    return 0;
}

// end
