import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

// Zac's solution
public class conquest2_da {

    int[] s, t;
    Map<Integer, List<Integer>> g;

    int[][][] memo;
    int[][] eid;

    int solve(int v, int p, int i, int b, int used) {
        if (i >= g.get(v).size()) return 0;
        int w = g.get(v).get(i);
        if (w == p) return solve(v, p, i + 1, b, used);
        if (memo[eid[v][i]][b][used] >= 0) return memo[eid[v][i]][b][used];
        int x = memo[eid[v][i]][b][used];
        for (int bb = 0; bb <= b; ++bb) {
            int nxt = solve(v, p, i + 1, b - bb, used);
            x = Math.max(x, solve(w, v, 0, bb, 0) + nxt);
            if (used == 0 && s[w] <= bb) x = Math.max(x, solve(w, v, 0, bb - s[w], 1) + t[w] + nxt);
        }
        return memo[eid[v][i]][b][used] = x;
    }

    private void work() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = sc.nextInt(), S = sc.nextInt();
        s = new int[n + 1];
        t = new int[n + 1];
        g = new HashMap<>();
        g.put(0, new ArrayList<>());
        for (int i = 1; i <= n; ++i) {
            s[i] = sc.nextInt();
            t[i] = sc.nextInt();
            g.put(i, new ArrayList<>());
        }
        eid = new int[n + 1][n + 1];
        for (int i = 0, u = 0, v = 1; i < n; ++i) {
            if (i > 0) {
                u = sc.nextInt();
                v = sc.nextInt();
            }
            eid[u][g.get(u).size()] = eid[v][g.get(v).size()] = i;
            g.get(u).add(v);
            g.get(v).add(u);
        }

        memo = new int[n + 1][S + 1][2];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= S; j++) {
                memo[i][j][0] = memo[i][j][1] = -1;
            }
        }
        System.out.println(solve(0, -1, 0, S, 0));
    }

    public static void main(String[] args) {
        new conquest2_da().work();
    }
}
