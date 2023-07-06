#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <cassert>
#include <climits>

using namespace std;

typedef long long ll;

const ll inf = INT_MAX*1000000LL;

struct Edge;
typedef list<Edge>::iterator EdgeIter;

struct Edge {
  int to;
  ll cap;
  ll flow;
  bool is_real;
  EdgeIter partner;
  
  Edge(int t, ll c, bool real = true)
    : to(t), cap(c), flow(0), is_real(real)
  {};

  ll residual() const
  {
    return cap - flow;
  }
};

struct Graph {
  list<Edge> *nbr;
  int num_nodes;
  Graph(int n)
    : num_nodes(n)
  {
    nbr = new list<Edge>[num_nodes];
  }

  ~Graph()
  {
    delete[] nbr;
  }

  // note: this routine adds an edge to the graph with the specified capacity,
  // as well as a residual edge.  There is no check on duplicate edge, so it
  // is possible to add multiple edges (and residual edges) between two
  // vertices
  void add_edge(int u, int v, ll cap)
  {
    nbr[u].push_front(Edge(v, cap));
    nbr[v].push_front(Edge(u, 0, false));
    nbr[v].begin()->partner = nbr[u].begin();
    nbr[u].begin()->partner = nbr[v].begin();
  }
};

void push_path(Graph &G, int s, int t, const vector<EdgeIter> &path, ll flow)
{
  for (int i = 0; s != t; i++) {
    if (path[i]->is_real) {
      path[i]->flow += flow;
      path[i]->partner->cap += flow;
    } else {
      path[i]->cap -= flow;
      path[i]->partner->flow -= flow;
    }
    s = path[i]->to;
  }
}

// the path is stored in a peculiar way for efficiency: path[i] is the
// i-th edge taken in the path.
ll augmenting_path(const Graph &G, int s, int t, vector<EdgeIter> &path,
		    vector<bool> &visited, int step = 0)
{
  if (s == t) {
    return -1;
  }
  for (EdgeIter it = G.nbr[s].begin(); it != G.nbr[s].end(); ++it) {
    int v = it->to;
    if (it->residual() > 0 && !visited[v]) {
      path[step] = it;
      visited[v] = true;
      ll flow = augmenting_path(G, v, t, path, visited, step+1);
      if (flow == -1) {
	return it->residual();
      } else if (flow > 0) {
	return min(flow, it->residual());
      }
    }
  }
  return 0;
}

// note that the graph is modified
ll network_flow(Graph &G, int s, int t)
{
  vector<bool> visited(G.num_nodes);
  vector<EdgeIter> path(G.num_nodes);
  ll flow = 0, f;

  do {
    fill(visited.begin(), visited.end(), false);
    if ((f = augmenting_path(G, s, t, path, visited)) > 0) {
      push_path(G, s, t, path, f);
      flow += f;
    }
  } while (f > 0);
  
  return flow;
}

int main()
{
   int N;
   cin >> N;
   Graph G(N + 2);
   ll sum = 0;
   for(int i = 0; i < N; i++){
      ll v, c, m;
      cin >> v >> c >> m;
      ll w = v-c;
      if(w >= 0){
	sum += w;
	 G.add_edge(N, i, w);
      }
      else{
	 G.add_edge(i, N+1, -w);
      }
      for(int j = 0; j < m; j++){
	 int u;
	 cin >> u;
	 G.add_edge(u-1, i, inf);
      }
   }

   ll flow = network_flow(G, N, N+1);
   cout << sum - flow << endl;
   
   return 0;
}


