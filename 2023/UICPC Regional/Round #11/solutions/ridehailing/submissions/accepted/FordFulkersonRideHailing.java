/**
 * Solution to the ride hailing problem using the Ford Fulkerson 
 * algorithm for maximum bipartite matching.
 * The idea is that you want to re-use the drivers as much as possible.
 * We have two vertices for each request--one set of starting requests, 
 * one set of next requests. We add an edge from starting request i to
 * next request j if it is possible for a single driver to serve request
 * j after serving request i. Choosing an edge to be in the matching
 * corresponds to re-using a driver for consecutive requests.
 * The answer is then the number of requests minus the number of edges
 * in the matching.
 *
 * @author Finn Lidbetter
 */
import java.util.*;
import java.io.*;

public class FordFulkersonRideHailing {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();

    String[] s = br.readLine().split(" ");
    int n = Integer.parseInt(s[0]);
    int m = Integer.parseInt(s[1]);
    int k = Integer.parseInt(s[2]);
    
    Integer[][] apsp = new Integer[n][n];
    for (int i=0; i<m; i++) {
      s = br.readLine().split(" ");
      int u = Integer.parseInt(s[0]) - 1;
      int v = Integer.parseInt(s[1]) - 1;
      int w = Integer.parseInt(s[2]);
      apsp[u][v] = w;
    }
    for (int i=0; i<n; i++) {
      apsp[i][i] = 0;
    }
    // Use Floyd-Warshall to get the distances between all pairs.
    for (int l=0; l<n; l++) {
      for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
          if (apsp[i][l]!=null && apsp[l][j]!=null && (apsp[i][j]==null || apsp[i][l]+apsp[l][j]<apsp[i][j])) {
            apsp[i][j] = apsp[i][l]+apsp[l][j];
          }
        }
      }
    }

    int[] origin = new int[k];
    int[] destination = new int[k];
    int[] startTime = new int[k];
    for (int i=0; i<k; i++) {
      s = br.readLine().split(" ");
      origin[i] = Integer.parseInt(s[0])-1;
      destination[i] = Integer.parseInt(s[1])-1;
      startTime[i] = Integer.parseInt(s[2]);
    }
    boolean[][] adj = new boolean[k][k];
    for (int i=0; i<k; i++) {
      for (int j=0; j<k; j++) {
        // The problem guarantees that every location is accessible from every other location.
        // So null pointer exceptions here are either invalid input, or a bug
        // in parsing and computing All-Pairs-Shortest-Paths.
        if (startTime[i] + apsp[origin[i]][destination[i]] + apsp[destination[i]][origin[j]]<=startTime[j]) {
          adj[i][j] = true;
        }
      }
    }
    List<Edge>[] graph = createGraph(2*k+2);
    for (int i=0; i<k; i++) {
      addEdge(graph, 2*k, i, 1);
      addEdge(graph, k+i, 2*k+1, 1);
    }
    for (int i=0; i<k; i++) {
      for (int j=0; j<k; j++) {
        if (adj[i][j]) {
          addEdge(graph, i, k+j, 1);
        }
      }
    }
    int flow = (int)maxFlow(graph, 2*k, 2*k+1);

    System.out.println(k-flow);   
  }

  static List<Edge>[] createGraph(int nodes) {
    List<Edge>[] graph = new List[nodes];
    for (int i = 0; i < nodes; i++) graph[i] = new ArrayList<>();
    return graph; }
  static void addEdge(List<Edge>[] graph, int u, int v, int cap) {
    graph[u].add(new Edge(v, graph[v].size(), cap));
    graph[v].add(new Edge(u, graph[u].size() - 1, 0)); }
  static int maxFlow(List<Edge>[] graph, int s, int t) {
    boolean[] mincut = new boolean[graph.length];
    for (int flow = 0;;) {
      int df = findPath(graph, mincut, s, t, Integer.MAX_VALUE);
      if (df == 0) return flow;
      Arrays.fill(mincut, false);
      flow += df; } }
  static int findPath(List<Edge>[] gr, boolean[] vis, int u, int t, int f) {
    if (u == t) return f;
    vis[u] = true;
    for (Edge e : gr[u])
      if (!vis[e.v] && e.f < e.cap) {
        int df = findPath(gr, vis, e.v, t, Math.min(f, e.cap - e.f));
        if (df > 0) { e.f += df; gr[e.v].get(e.rev).f -= df; return df; } }
    return 0; }
  static class Edge {
    int v, rev; int cap, f;
    public Edge(int v, int rev, int cap) {
      this.v = v; this.rev = rev; this.cap = cap; } }

}
