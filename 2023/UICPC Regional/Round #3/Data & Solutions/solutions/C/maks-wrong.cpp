/* @EXPECTED_RESULTS@: WRONG-ANSWER
Non-solution which uses a greeedy strategy to fix games in an opportunistic
   manner.  THIS SHOULD FAIL!  Never over-estimates the set of winning players,
   but may (should!) omit potential winners in some cases. */

#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

#define FOR(i,a,b) for (int i = int(a); i < int(b); ++i)
#define REP(i,n) FOR(i,0,n)

static int metric1(int score1, int score2)
{
    return min(score1, score2);
}

static int metric2(int score1, int score2)
{
    return max(score1, score2);
}

static int metric3(int score1, int score2)
{
    return score1 < score2 ? score1 + 2 :
           score1 > score2 ? score2 + 2 :
                             score1 + 1;
}

static int metric4(int score1, int score2)
{
    return score1 < score2 ? 1*score1 + 2*score2 :
           score1 > score2 ? 2*score1 + 1*score2 :
                             3*score1;
}

static int (*metrics[])(int,int) = { metric1, metric2, metric3, metric4, NULL };

static bool can_win(int n, int N, vector<string> grid, int (*metric)(int,int))
{
    // Assume player n wins all his remaining matches:
    REP(m, N) if (grid[n][m] == '.') {
        grid[n][m] = '1';
        grid[m][n] = '0';
    }

    // Calculcate scores of all players so far:
    vector<int> score(N);
    REP(i, N) REP(j, N) {
        if (grid[i][j] == '1') score[i] += 2;  // two half-points for winning
        if (grid[i][j] == 'd') score[i] += 1;  // one half-point for drawing
    }

    // Check if we haven't lost already:
    REP(m, N) if (score[m] > score[n]) return false;

    // See how much points are left in the game:
    int points_left = N*(N - 1);
    REP(i, N) points_left -= score[i];

    // Greedily assign remaining points:
    while (points_left > 0)
    {
        // Find the best match to fix, by minimizing
        int best_i = -1, best_j = -1, best_v = -1;
        REP(j, N) REP(i, j) if (grid[i][j] == '.') {
            if ( (score[i] < score[j] ? score[i] + 2 :
                  score[j] < score[i] ? score[j] + 2 : score[i] + 1)
                    >= score[n] ) continue;
            int v = metric(score[i], score[j]);
            if (best_i == -1 || v < best_v) best_i = i, best_j = j, best_v = v;
        }
        if (best_i == -1) return false;

        if (score[best_i] < score[best_j])
        {
            grid[best_i][best_j] = '1';
            grid[best_j][best_i] = '0';
            score[best_i] += 2;
        }
        else
        if (score[best_i] > score[best_j])
        {
            grid[best_i][best_j] = '0';
            grid[best_j][best_i] = '1';
            score[best_j] += 2;
        }
        else // score[best_i] == score[best_j]
        {
            grid[best_i][best_j] = 'd';
            grid[best_j][best_i] = 'd';
            score[best_i] += 1;
            score[best_j] += 1;
        }
        points_left -= 2;
    }
    return true;
}

static int mask = ~0;

static bool can_win(int n, int N, const vector<string> &grid)
{
    bool res = false;
    for (int m = 0; metrics[m] != NULL; ++m) {
        if (mask & (1<<m)) {
            bool v = can_win(n, N, grid, metrics[m]);
            //cerr << v;
            res = res || v;
        }
    }
    //if (n + 1 == N) cerr << endl; else cerr << ' ';
    return res;
}

int main(int argc, char *argv[])
{
    if (argc == 3 && strcmp(argv[1], "--metric") == 0) {
        assert(atoi(argv[2]) > 0);
        mask = 1 << (atoi(argv[2]) - 1);
    } else {
        assert(argc == 1);
    }

    int cases = 0, N;
    cin >> cases;
    while (cases-- > 0 && cin >> N)
    {
        vector<string> grid(N);
        REP(n, N) cin >> grid[n];
        const char *sep = "";
        REP(n, N) if (can_win(n, N, grid)) {
            cout << sep << n + 1;  // player indices are 1-based in the output
            sep = " ";
        }
        cout << endl;
    }
}
