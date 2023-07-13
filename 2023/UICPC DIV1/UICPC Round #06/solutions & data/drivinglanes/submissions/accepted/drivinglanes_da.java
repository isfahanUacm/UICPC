import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class drivinglanes_da {

    private static final long oo = Long.MAX_VALUE / 8;
    private int n, m, r, k;
    private long[] straight, stretch, curvature;
    private long[][] memo;

    private long go(int cur, int lane) {
        if (cur == n - 1) {
            int rem = lane - 1;
            if (rem * k > straight[n - 1]) return oo;
            return straight[n - 1] + rem * r;
        }

        if (memo[cur][lane] > 0) return memo[cur][lane];

        long min = lane * curvature[cur] + go(cur + 1, lane);

        int maxChange = Math.min((int) (straight[cur]) / k, m - lane);
        for (int i = 1; i <= maxChange; i++) {
            long t = r * i + (lane + i) * curvature[cur] + go(cur + 1, lane + i);
            if (t < min) min = t;
        }

        maxChange = Math.min((int) (straight[cur]) / k, lane - 1);
        for (int i = 1; i <= maxChange; i++) {
            long t = r * i + (lane - i) * curvature[cur] + go(cur + 1, lane - i);
            if (t < min) min = t;
        }

        return memo[cur][lane] = min + straight[cur] + stretch[cur];
    }

    private void work() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        n = sc.nextInt();
        m = sc.nextInt();
        k = sc.nextInt();
        r = sc.nextInt();

        straight = new long[n];
        stretch = new long[n - 1];
        curvature = new long[n - 1];

        for (int i = 0; i < n; i++) {
            straight[i] = sc.nextInt();
        }

        for (int i = 0; i < n - 1; i++) {
            stretch[i] = sc.nextInt();
            curvature[i] = sc.nextInt();
        }

        sc.close();

        memo = new long[n - 1][m + 1];

        System.out.println(go(0, 1));
    }

    public static void main(String[] args) {
        new drivinglanes_da().work();
    }
}
