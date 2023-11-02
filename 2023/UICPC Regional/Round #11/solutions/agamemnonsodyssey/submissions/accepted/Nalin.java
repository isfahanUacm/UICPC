import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.InputStream;

public class Nalin {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Solver solver = new Solver();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class Solver {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            long total = 0;
 
            List<Integer>[] adj = new List[n];
            for (int i = 0; i < n; i++) {
                adj[i] = new ArrayList<>();
            }
            Graphs.Edge[] edges = new Graphs.Edge[n - 1];
            for (int i = 0; i < n - 1; i++) {
                edges[i] = new Graphs.Edge(in.nextInt() - 1, in.nextInt() - 1, in.nextInt());
                adj[edges[i].u].add(i);
                adj[edges[i].v].add(i);
                total += edges[i].cost;
            }
 
            long[] distances = new long[n];
            dfs(0, -1, 0L, edges, adj, distances);

            int farthest = 0;
            long farthestd = 0;
            for (int i = 0;i < n;i++)
            {
                if (distances[i] > farthestd)
                {
                    farthest = i;
                    farthestd = distances[i];
                }
            }

            dfs(farthest, -1, 0L, edges, adj, distances);

            for (int i = 0;i < n;i++)
            {
                if (distances[i] > farthestd)
                {
                    farthest = i;
                    farthestd = distances[i];
                }
            }

            if (k == 1) out.println(farthestd);
            else out.println(total);
        }
 
        private void dfs(int node, int par, long curdist, Graphs.Edge[] edges, List<Integer>[] adjLists, long[] distances) {
            distances[node] = curdist;
            for (int i : adjLists[node]) {
                if (i == par)
                    continue;
                int next = edges[i].u ^ edges[i].v ^ node;
                dfs(next, i, distances[node] + edges[i].cost, edges, adjLists, distances);
            }
        }
 
    }
 
    static class Graphs {
        public static class Edge {
            public final int u;
            public final int v;
            public final int cost;
 
            public Edge(int u, int v, int cost) {
                this.u = u;
                this.v = v;
                this.cost = cost;
            }
 
        }
 
    }
 
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
 
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }
 
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
 
        public int nextInt() {
            return Integer.parseInt(next());
        }
 
    }
 
    static class Util {
        public static String formatDouble(double x) {
            return String.format("%.15f", x);
        }
 
        public static long nc2(long n) {
            return n * (n - 1) / 2;
        }
 
    }
}
 