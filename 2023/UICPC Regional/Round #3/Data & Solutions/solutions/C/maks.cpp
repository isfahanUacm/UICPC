/* @EXPECTED_RESULTS@: CORRECT
Approach:

Solve the problem for each player independently.

Start by assuming that the player under consideration wins all his remaining
matches.  Then the question remains whether we can distribute the available
half-points (two per game left) over the remaining players so that no player
beats the score of our potential winner.

This subproblem can be viewed as a network flow problem.  Each game and each
player is a vertex in the flow graph.  There is an edge with capacity 2 from the
source to each unplayed game, from each game to each of the two players in that
game, and from each player to the sink, where the capacity to the sink equals
the point difference with the potential winner.  The goal is to saturate the
edges leading to the games (i.e. assign all remaining points to players).

Since the network has O(N**2) vertices and O(N**2) edges, the worst-case time
complexity is O(N**5).  */

#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,a,b) for (int i = int(a); i < int(b); ++i)
#define REP(i,n) FOR(i,0,n)

static void check_testdata(int N, const vector<string> &grid)
{
    assert(N >= 2 && N <= 30);
    assert((int)grid.size() == N);
    REP(i, N) assert((int)grid[i].size() == N);
    REP(i, N) REP(j, N) {
        switch (grid[i][j]) {
        case '.': assert(i != j && grid[j][i] == '.'); break;
        case '0': assert(i != j && grid[j][i] == '1'); break;
        case '1': assert(i != j && grid[j][i] == '0'); break;
        case 'd': assert(i != j && grid[j][i] == 'd'); break;
        case 'x': assert(i == j); break;
        default: assert(false);  // invalid character in input
        }
    }
}

static void check_certificate( int N, const vector<string> &grid,
                               const vector<string> &cert, int n )
{
    // Verify that the certificate is a valid grid:
    check_testdata(N, cert);

    // Verify that the certificate is filled in to match the input grid:
    REP(i, N) REP(j, N) {
        assert(cert[i][j] != '.');
        assert(grid[i][j] == '.' || cert[i][j] == grid[i][j]);
    }

    // Check that the n-th player has maximum score:
    vector<int> score(N);
    REP(i, N) REP(j, N) {
        if (cert[i][j] == '1') score[i] += 2;
        if (cert[i][j] == 'd') score[i] += 1;
    }
    REP(i, N) assert(score[i] <= score[n]);
}

// Solution proper starts here  ----------------------------------------------

struct Edge { int dst, cap; };
typedef vector<Edge> AdjList;

static const int source = 0, sink = 1;
static vector<AdjList> adj;   // adjacency list for flow network graph
static vector<char> vis;      // vis[v] <=> vertex v was visited in augment()

static bool augment(int i)
{
    vis[i] = true;
    REP(n, adj[i].size()) if (adj[i][n].cap > 0) {
        int j = adj[i][n].dst;
        if (!vis[j] && (j == sink || augment(j))) {
            --adj[i][n].cap;
            REP(m, adj[j].size()) if (adj[j][m].dst == i) {
                ++adj[j][m].cap;
                break;
            }
            return true;
        }
    }
    return false;
}

static void add_edge(int src, int dst, int cap)
{
    Edge e = { dst, cap }, f = { src, 0 };
    adj[src].push_back(e);
    adj[dst].push_back(f);
}

// Fills in the grid such that the n-th player may win, or returns an empty
// grid to indicate no solution is possible.
static bool can_win(int N, vector<string> grid, int n)
{
    // Assume player n wins all his remaining matches:
    REP(m, N) if (grid[n][m] == '.') {
        grid[n][m] = '1';
        grid[m][n] = '0';
    }

    // Calculcate scores of all players so far:
    vector<int> scores(N);
    REP(i, N) REP(j, N) {
        if (grid[i][j] == '1') scores[i] += 2;  // two half-points for winning
        if (grid[i][j] == 'd') scores[i] += 1;  // one half-point for drawing
    }

    // Check if any competitors already beat player n:
    REP(m, N) if (scores[m] > scores[n]) return false;

    // Create flow network for remaining games:
    int points_left = 0;
    adj = vector<AdjList>(2 + N + N*N);
    const int player_base = 2, game_base = 2 + N;
    REP(m, N) if (scores[m] < scores[n]) {
        add_edge(player_base + m, sink, scores[n] - scores[m]);
    }
    REP(j, N) REP(i, j) if (grid[i][j] == '.') {
        int game = game_base + N*i + j;
        add_edge(source, game, 2);
        add_edge(game, player_base + i, 2);
        add_edge(game, player_base + j, 2);
        points_left += 2;
    }

    // Assign remaining points to games without exceeding player n's score:
    REP(_, points_left) {
        vis.assign(adj.size(), 0);
        if (!augment(source)) return false;
    }

    // Verify solution:
    vector<string> cert = grid;
    REP(j, N) REP(i, j) if (cert[i][j] == '.') {
        int game = game_base + N*i + j;
        for ( AdjList::const_iterator it = adj[game].begin();
              it != adj[game].end(); ++it )
        {
            assert(it->cap >= 0 && it->cap <= 2);
            if (it->dst == player_base + i) cert[i][j] = "1d0"[it->cap];
            if (it->dst == player_base + j) cert[j][i] = "1d0"[it->cap];
        }
    }
    check_certificate(N, grid, cert, n);
    return true;
}

static int next_int()
{
    int res = 0;
    cin >> res;
    assert(cin.good());
    return res;
}

int main()
{
    int cases = next_int();
    REP(c, cases) {
        int N = next_int();
        vector<string> grid(N);
        REP(n, N) cin >> grid[n];
        assert(cin.good());
        check_testdata(N, grid);
        const char *sep = "";
        REP(n, N) if (can_win(N, grid, n)) {
            cout << sep << n + 1;  // output 1-based player index
            sep = " ";
        }
        cout << endl;
    }
}
