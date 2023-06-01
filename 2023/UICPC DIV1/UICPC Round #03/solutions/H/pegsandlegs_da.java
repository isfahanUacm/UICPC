import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class pegsandlegs_da {

    private void work() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int L = sc.nextInt();
        int P = sc.nextInt();
        int n = L + P;
        double[] e = new double[n];
        double[] p = new double[n];
        boolean[] hit = new boolean[n];
        for (int i = 0; i < L + P; ++i) {
            if (i < L) {
                e[i] = sc.nextDouble();
            } else {
                double pl = sc.nextDouble();
                double pr = sc.nextDouble();
                int il = sc.nextInt() - 1;
                int ir = sc.nextInt() - 1;
                e[i] = pl * e[il] + pr * e[ir];
                p[i] = 1.0 - pl - pr + pl * p[il] + pr * p[ir];
                hit[il] = hit[ir] = true;
            }
        }

        double best = 0.0;
        for (int i = 0; i < n; ++i) if (!hit[i]) best = Math.max(best, e[i] / (1 - p[i]));

        System.out.printf("%.10f\n", best);
    }

    public static void main(String[] args) {
        new pegsandlegs_da().work();
    }
}
