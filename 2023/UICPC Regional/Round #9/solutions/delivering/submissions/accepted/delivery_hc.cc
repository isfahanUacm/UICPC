#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Graph layout
//  -- Each problem has its own Edge structure.
// If you see "typedef int Edge;" at the top of an algorithm, change
//    vector<vector<Edge> > nbr; --->  vector<vector<int> > nbr;

// Dijkstra's Algorithm [Sparse Graphs] (Directed and Undirected) -- O((n+m)*log(n+m))
//  -- Edge weight >= 0.  May use get_path to obtain the path.

struct Edge{ ll to,weight; }; // weight can be double or other numeric type
typedef vector<Edge>::const_iterator EdgeIter;

struct Graph {
  vector<vector<Edge> > nbr;
  int num_nodes;
  Graph(int n) : nbr(n), num_nodes(n) { }
  
  void add_edge(int u, int v, ll weight) {
    Edge e = {v,weight};    nbr[u].push_back(e);
  }
};

void dijkstra(const Graph &G, int src, vector<ll> &D) {
  typedef pair<ll,ll> pii;
  int n = G.num_nodes;
  vector<bool> used(n, false);
  priority_queue<pii, vector<pii>,  greater<pii> > fringe;

  D.resize(n);  fill(D.begin(), D.end(), -1);  

  D[src] = 0;
  fringe.push(make_pair(0, src));

  while (!fringe.empty()) {
    pii next = fringe.top();    fringe.pop();
    int u = next.second;
    if (used[u]) continue;
    used[u] = true;

    for (EdgeIter it = G.nbr[u].begin(); it != G.nbr[u].end(); ++it) {
      int v = it->to;
      ll weight = it->weight + next.first;
      if (used[v]) continue;
      if (D[v] == -1 || weight < D[v]) {
	D[v] = weight;   fringe.push(make_pair(D[v], v));
      }
    }
  }
}

// Unweighted Bipartite Matching (Undirected Only) -- O(m*sqrt(n))
//  -- Your match is stored in "mate". (mate == -1 if there is no match)
//  -- adj is an adjacency list that indexes the other set
//         Ex: U[0].adj[0] == x means there is an edge from U[0] to V[x]

struct Node{ vector<int> adj; int mate,pred; }; // Ignore "pred" -- For internal use.

void add_edge(Node U[],int u_node,Node V[],int v_node){
  U[u_node].adj.push_back(v_node);
  V[v_node].adj.push_back(u_node);  
}

// u is the number of elements in U
// v is the number of elements in V
int match(Node U[],int u,Node V[],int v){
  for(int i=0;i<u;i++) U[i].mate = -1;
  for(int i=0;i<v;i++) V[i].mate = -1;
  
  int numMatches = 0;
  while(true){
    queue<int> q1,q2;
    for(int i=0;i<u;i++) if(U[i].mate == -1) q1.push(i);
    for(int i=0;i<u;i++) U[i].pred = -1;
    for(int i=0;i<v;i++) V[i].pred = -1;
    
    while(!q1.empty()){
      int x = q1.front(); q1.pop();
      for(int i=0;i<U[x].adj.size();i++){ int w = U[x].adj[i];
	if(V[w].pred != -1) continue;
	if(V[w].mate == -1) V[w].pred = x , q2.push(w);
	else if(V[w].mate != x && U[V[w].mate].pred == -1)
	  V[w].pred = x , U[V[w].mate].pred = w , q1.push(V[w].mate); 
      }
    }

    if(q2.empty()) break;
    while(!q2.empty()){
      Node* W = V; int i,x = q2.front(); q2.pop();
      for(i = x;i >= 0;W=(W == U ? V : U)) i = W[i].pred;
      if(i == -2) continue; numMatches++;
      for(i = x;i >= 0;){
	int p = V[i].pred;  V[i].pred = -2;  V[i].mate = p;
	U[p].mate = i;      i = U[p].pred;   U[p].pred = -2;
      }
    }
  }
  return numMatches;
}

int main()
{
  int n, m, c;
  cin >> n >> m >> c;

  int client[300];
  for (int i = 0; i < c; i++) {
    cin >> client[i];
  }

  Graph G(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    ll l;
    cin >> u >> v >> l;
    G.add_edge(u, v, l);
  }

  vector<ll> Droot;
  dijkstra(G, 0, Droot);

  Node U[301], V[301];
  for (int i = 0; i < c; i++) {
    vector<ll> Dc;
    dijkstra(G, client[i], Dc);
    for (int j = 0; j < c; j++) {
      if (i == j) continue;
      if (Dc[client[j]] >= 0 &&
	  Droot[client[i]] + Dc[client[j]] == Droot[client[j]]) {
	add_edge(U, i, V, j);
      }
    }
  }

  cout << c - match(U, c, V, c) << endl;

  return 0;
}
