// @EXPECTED_RESULTS@: CORRECT
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

#define FOR(i,a,b) for (int i = int(a); i < int(b); ++i)
#define REP(i,n) FOR(i,0,n)

static bool can_win(int N, const vector<string> &grid, int P)
{
    vector<vector<int> > value(N, vector<int>(N));
    vector<vector<char> > fixed(N, vector<char>(N));
    vector<int> score(N);
    REP(i, N) REP(j, N) {
        switch (grid[i][j]) {
            case '.': value[i][j] = i == P ? 2 : j == P ? 0 : 1; break;
            case '0': value[i][j] = 0; break;
            case 'd': value[i][j] = 1; break;
            case '1': value[i][j] = 2; break;
        }
        fixed[i][j] = grid[i][j] != '.';
        score[i] += value[i][j];
    }
    vector<int> visited, queue;
    REP(i, N) {
        while (score[i] > score[P]) {
            visited.assign(N, -1);
            visited[i] = i;
            queue.assign(1, i);
            for (size_t pos = 0; ; ++pos)
            {
                if (pos == queue.size()) return false;
                int j = queue[pos];
                if (score[j] < score[P])
                {
                    ++score[j];
                    while (j != visited[j])
                    {
                        int k = visited[j];
                        ++value[j][k];
                        --value[k][j];
                        j = k;
                    }
                    --score[j];
                    break;
                }
                REP(k, N) if (!fixed[j][k] && value[j][k] > 0 && visited[k] < 0) {
                    queue.push_back(k);
                    visited[k] = j;
                }
            }
        }
    }
    return true;
}

int main()
{
    int cases = 0;
    std::cin >> cases;
    REP(c, cases) {
        int N = 0;
        std::cin >> N;
        vector<string> grid(N);
        REP(i, N) std::cin >> grid[i];
        const char *sep = "";
        REP(P, N) if (can_win(N, grid, P)) {
            std::cout << sep << P + 1;  // output 1-based player index
            sep = " ";
        }
        std::cout << std::endl;
    }
}
