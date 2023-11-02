import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class delivery_da {

    class BipartiteMatching {
        private boolean[][] graph;
        private boolean[] seen;
        private int[] matchL;
        private int[] matchR;
        private int n, m;

        public BipartiteMatching(int m, int n) {
            this.m = m;
            this.n = n;
            graph = new boolean[m][n];
            seen = new boolean[n];
            matchL = new int[m];
            matchR = new int[n];
            Arrays.fill(matchL, -1);
            Arrays.fill(matchR, -1);
        }

        private boolean bpm(int u) {
            for (int v = 0; v < n; v++) {
                if (graph[u][v]) {
                    if (seen[v]) {
                        continue;
                    }
                    seen[v] = true;
                    if (matchR[v] < 0 || bpm(matchR[v])) {
                        matchL[u] = v;
                        matchR[v] = u;
                        return true;
                    }
                }
            }
            return false;
        }

        public void addEdge(int u, int v) {
            graph[u][v] = true;
        }

        public int getMaxMatchingCardinality() {
            int count = 0;
            for (int i = 0; i < m; i++) {
                Arrays.fill(seen, false);
                if (bpm(i)) {
                    count++;
                }
            }
            return count;
        }
    }

    private final static long oo = Long.MAX_VALUE / 4;
    private long[][] graph, d;
    private int[][] adj;
    private int[] deg, par, q, inq;
    private int qs;

    private void init(int n) {
        graph = new long[n][n];
        d = new long[n][n];
        adj = new int[n][n];
        deg = new int[n];
        par = new int[n];
        inq = new int[n];
        q = new int[n];
    }

    private void bubl(int i, int j) {
        int t = q[i];
        q[i] = q[j];
        q[j] = t;
        t = inq[q[i]];
        inq[q[i]] = inq[q[j]];
        inq[q[j]] = t;
    }

    public void dijkstra(int n, int s) {
        for (int i = 0; i < n; i++) {
            d[s][i] = oo;
            inq[i] = -1;
            par[i] = -1;
        }
        d[s][s] = qs = 0;
        inq[q[qs++] = s] = 0;
        par[s] = -2;

        while (qs > 0) {
            // get the minimum from the q
            int u = q[0];
            inq[u] = -1;

            // bubble down
            q[0] = q[--qs];
            if (qs > 0) {
                inq[q[0]] = 0;
            }
            for (int i = 0, j = 2 * i + 1; j < qs; i = j, j = 2 * i + 1) {
                if (j + 1 < qs && d[s][q[j + 1]] < d[s][q[j]]) {
                    j++;
                }
                if (d[s][q[j]] >= d[s][q[i]]) {
                    break;
                }
                bubl(i, j);
            }

            // relax neighbours
            for (int k = 0, v = adj[u][k]; k < deg[u]; v = adj[u][++k]) {
                long newd = d[s][u] + graph[u][v];
                if (newd < d[s][v]) {
                    d[s][v] = newd;
                    par[v] = u;
                    if (inq[v] < 0) {
                        inq[q[qs] = v] = qs;
                        qs++;
                    }

                    // bubble up
                    int i = inq[v];
                    int j = (i - 1) / 2;
                    while (j >= 0 && d[s][q[i]] < d[s][q[j]]) {
                        bubl(i, j);
                        i = j;
                        j = (i - 1) / 2;
                    }
                }
            }
        }
    }

    private void work() {

        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        int n = sc.nextInt();
        int m = sc.nextInt();
        int c = sc.nextInt();

        init(n);

        int[] cs = new int[c];
        for (int i = 0; i < c; i++) {
            cs[i] = sc.nextInt();
        }

        for (int i = 0; i < m; i++) {

            int u = sc.nextInt();
            int v = sc.nextInt();
            long w = sc.nextInt();

            adj[u][deg[u]++] = v;
            graph[u][v] = w;
        }

        sc.close();

        dijkstra(n, 0);
        for (int i = 0; i < c; i++) {
            dijkstra(n, cs[i]);
        }

        BipartiteMatching bpm = new BipartiteMatching(c + 1, c + 1);
        for (int i = 0; i < c; i++) {
            bpm.addEdge(0, i + 1);
            for (int j = 0; j < c; j++) {
                if (i != j && d[cs[i]][cs[j]] < oo && d[0][cs[i]] + d[cs[i]][cs[j]] == d[0][cs[j]])
                    bpm.addEdge(i + 1, j + 1);
            }
        }

        System.out.println(c + 1 - bpm.getMaxMatchingCardinality());
    }

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();
        new delivery_da().work();
        long t = System.currentTimeMillis() - startTime;
        System.err.println(String.format("Elapsed time: %d:%02d.%03d\n", t / 60000, (t / 1000) % 60, t % 1000));
    }
}
