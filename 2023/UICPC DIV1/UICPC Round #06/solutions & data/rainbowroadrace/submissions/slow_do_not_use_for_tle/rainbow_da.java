import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class rainbow_da {
    class Edge {
        int v, d, c;

        Edge(int v, int d, int c) {
            this.v = v;
            this.d = d;
            this.c = c;
        }
    }

    private static final int oo = Integer.MAX_VALUE / 4;

    private void work() {
        String rainbow = "ROYGBIV";
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = sc.nextInt();
        int m = sc.nextInt();
        Map<Integer, List<Edge>> g = new HashMap<>();
        for (int i = 0; i < n; i++) g.put(i, new ArrayList<>());

        while (m-- > 0) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            int d = sc.nextInt();
            int c = 1 << rainbow.indexOf(sc.next().charAt(0));
            g.get(u).add(new Edge(v, d, c));
            g.get(v).add(new Edge(u, d, c));
        }

        int[][] d = new int[n][128];
        for (int i = 0; i < n; i++) Arrays.fill(d[i], oo);
        d[0][0] = 0;
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        q.add(0);
        while (!q.isEmpty()) {
            int u = q.poll();
            int curColor = q.poll();
            if (u == 0 && curColor == 127) continue;
            for (Edge e : g.get(u)) {
                int v = e.v;
                int nc = curColor | e.c;
                int nd = d[u][curColor] + e.d;
                if (d[v][nc] > nd) {
                    q.add(v);
                    q.add(nc);
                    d[v][nc] = nd;
                }
            }
        }

        System.out.println(d[0][127]);
    }

    public static void main(String[] args) {
        new rainbow_da().work();
    }
}
