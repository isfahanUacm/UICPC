// Solution to Chess Competition
// Author: Thomas Beuman

// Time complexity: O(n^5)
// Memory: O(n^2)

// @EXPECTED_RESULTS@: CORRECT

/*
Solution outline:

Multiply all points by 2 in order to get integers (win = 2, draw = 1)

For every player: assume that he/she wins everything
Determine how many points the other players can maximally gain without passing this player

Build a network with a source, a sink, a node for every player and one for every unfinished game
Edges:
- From the source to every player with capacity = max points allowed to get
- From every player to every game he/she is involved in (with capacity >= 2)
- From every game to the sink with capacity 2

See if the maximum flow through this network equals the number of points that are left
  (2 for every unfinished game)
*/

// This solution builds an adjacency matrix first, and then makes adjaceny lists later (inefficient)

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/*** Maximum flow ***/

const int Nmax = 30;
const int M = 1 + Nmax + Nmax*(Nmax-1)/2 + 1; // Source + players + games + sink

int adj[M][M], deg[M]; // Adjacency lists, degree of nodes
int cap[M][M], rsd[M][M]; // Capacity, residual capacity
int q[M], prev[M]; // BFS queue, previous node in path

// Finds shortest path, returns if there is a path
bool bfs (int source, int sink)
{ memset(prev, -1, sizeof(prev));
  int cur, last = 1, from, i, next;
  q[0] = source;
  prev[source] = source;
  for (cur = 0; cur < last; cur++)
  { from = q[cur];
    for (i = deg[from] - 1; i >= 0; i--)
      if (prev[next = adj[from][i]] < 0 && rsd[from][next])
      { prev[next] = from;
        q[last++] = next;
        if (next == sink)
          return true;
      }
  }
  return false;
}

// Returns maximum flow from source to sink
int maxflow (int source, int sink, int n)
{ int bot, node, flow = 0, i, j;
  memcpy(rsd, cap, sizeof(rsd));
  // Build adjacency lists
  memset(deg, 0, sizeof(deg));
  for (i = 0; i < n; i++)
    for (j = i; j < n; j++)
      if (rsd[i][j] > 0 || rsd[j][i] > 0)
      { adj[i][deg[i]++] = j;
        adj[j][deg[j]++] = i;
      }
  while (bfs(source, sink)) // Look for augmenting path
  { // Determine bottleneck capacity
    bot = 0x7fffffff;
    for (node = sink; node != source; node = prev[node])
      bot = min(bot, rsd[prev[node]][node]);
    // Push flow through network, update capacities
    for (node = sink; node != source; node = prev[node])
    { rsd[prev[node]][node] -= bot;
      rsd[node][prev[node]] += bot;
    }
    flow += bot;
  }
  return flow;
}

int main()
{ int cases, casenr, n, i, j, m, finalscore, gamesleft, pointsleft;
  int Points[Nmax];
  char Table[Nmax][Nmax+1];
  bool Pos[Nmax], first;
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    /*** Read input ***/
    scanf("%d\n", &n);
    for (i = 0; i < n; i++)
      scanf("%s\n", Table[i]);

    /*** Build capacity matrix ***/
    memset(cap, 0, sizeof(cap));
    // Node 0 = source, nodes 1-n = players
    m = n+1; // Number of nodes
    pointsleft = 0; // Total points left to be distributed
    for (i = 1; i < n; i++)
      for (j = 0; j < i; j++)
        if (Table[i][j] == '.') // Look for games yet to be played
        { cap[i+1][m] = cap[j+1][m] = 2; // Add new node (m), edge with capacity >= 2
          m++;
          pointsleft += 2;
        }
    m++; // Add sink
    // Set capacity from every game to the sink to 2
    for (i = n+1; i < m-1; i++)
      cap[i][m-1] = 2;
    
    /*** Compute scores ***/
    memset(Points, 0, n*sizeof(int));
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        Points[i] += (Table[i][j] == '1' ? 2 : Table[i][j] == 'd' ? 1 : 0);
    
    /*** Determine for every player if he/she can win ***/
    for (i = 0; i < n; i++)
    { Pos[i] = true;
      // Count number of games left to play
      gamesleft = 0;
      for (j = 0; j < n; j++)
        if (Table[i][j] == '.')
          gamesleft++;
      // Final score of player i if he/she wins everything
      finalscore = Points[i] + 2 * gamesleft;
      // Determine how many points everyone is allowed to get
      // Put this as capacity from source to each player
      for (j = 0; j < n; j++)
        if ((cap[0][j+1] = finalscore - Points[j]) < 0)
          Pos[i] = false;
      // If someone already has more points, continue with next player
      if (!Pos[i])
        continue;
      // Check whether all remaining points can be distributed
      Pos[i] = (maxflow(0, m-1, m) == pointsleft);
    }
    
    /*** Output ***/
    first = true;
    for (i = 0; i < n; i++)
      if (Pos[i])
      { if (!first)
          printf(" ");
        first = false;
        printf("%d", i+1);
      }
    printf("\n");
  }
  return 0;
}

