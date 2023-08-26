/* @EXPECTED_RESULTS@: CORRECT
Approach: binary search for the answer.

For each potential answer x, consider all grid points at least x units away from
the nearest occupied point.  To find a pair of points with maximum privacy, we
only need to consider the leftmost and rightmost available point on each grid
line, yielding an O(W*H) algorithm to determine whether a particular value of x
is feasible or not.

The overall runtime complexity then becomes O(H*W*log(H + W)) with an O(H*W)
preprocessing step to determine the distances from each gridpoint to the nearest
hotdog stand. */

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define REP(i, n)   for (int i = 0; i <  (n); ++i)

int main()
{
    int cases = 0;
    cin >> cases;
    REP(_, cases) {
        int N = 0, H = 0, W = 0;
        cin >> N >> H >> W;
        assert(H*W - N >= 2);

        /* Calculcate the privacy for all grid points by using breadth-first
           search starting from each of the N initially occupied points: */
        static const int inf = 999999999;
        vector<vector<int> > dist(H, vector<int>(W, inf));
        vector<pair<int, int> > queue;
        queue.reserve(H*W);
        REP(n, N) {
            int r = 0, c = 0;
            cin >> r >> c;
            assert(dist[r][c] == inf);
            dist[r][c] = 0;
            queue.push_back(make_pair(r, c));
        }
        for (size_t pos = 0; pos < queue.size(); ++pos)
        {
            int r = queue[pos].first, c = queue[pos].second;
            REP(dir, 4) {
                static const int DR[4] = { -1,  0,  0, +1 };
                static const int DC[4] = {  0, -1, +1,  0 };
                int nr = r + DR[dir],
                    nc = c + DC[dir];
                if ((unsigned)nr < H && (unsigned)nc < W && dist[nr][nc] == inf)
                {
                    dist[nr][nc] = dist[r][c] + 1;
                    queue.push_back(make_pair(nr, nc));
                }
            }
        }

        /* Binary search for the maximum possible privacy: */
        int lo = 0, hi = H + W - 2;
        while (lo < hi)
        {
            int mid = (lo + hi + 1)/2;
            vector<int> minc(H, inf), maxc(H, -inf);
            REP(r, H) REP(c, W) if (dist[r][c] >= mid) {
                if (c < minc[r]) minc[r] = c;
                if (c > maxc[r]) maxc[r] = c;
            }
            bool possible = false;
            REP(r1, H) if (maxc[r1] >= 0) REP(r2, H) if (maxc[r2] >= 0) {
                possible |= abs(r1 - r2) + maxc[r1] - minc[r2] >= mid;
            }
            if (possible) lo = mid; else hi = mid - 1;
        }
        cout << lo << endl;
    }
}
