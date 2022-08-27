import java.util.*;
import java.io.*;

class Fast {
    
    int find(int[] C, int x) { return (C[x] == x) ? x : (C[x] = find(C, C[x])); }
    void merge(int[] C, int x, int y) { C[find(C, x)] = find(C, y); }

    class Edge implements Comparable<Edge> {
        int u;
        int v;
        int c;

        public Edge(int u, int v, int c) {
            this.u = u;
            this.v = v;
            this.c = c;
        }

        public int compareTo(Edge other) {
            return this.c - other.c;
        }
    }
    
    void solve() throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        
        ArrayList<Edge> edges = new ArrayList<Edge>();
        for (int i = 0; i < n; ++i) {
            String tokens[] = in.readLine().split(" ");

            for (int j = 0; j < n; ++j) {
                int c = Integer.parseInt(tokens[j]);

                edges.add(new Edge(i, j, c));
            }
        }

        Collections.sort(edges);
        int[] UF = new int[n];
        for (int i = 0; i < n; ++i)
            UF[i] = i;

        for (Edge e : edges) {
            if (find(UF, e.u) != find(UF, e.v)) {
                merge(UF, e.u, e.v);

                System.out.println((e.u+1) + " " + (e.v+1));
            }
        }
    }
    
    public static void main(String[] args) throws Exception {
        (new Fast()).solve();
    }
}
