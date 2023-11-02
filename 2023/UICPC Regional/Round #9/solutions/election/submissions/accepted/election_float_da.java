import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class election_float_da {

    private static final String LOSS = "RECOUNT!";
    private static final String TIE = "PATIENCE, EVERYONE!";
    private static final String WIN = "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!";

    private double c[][];

    private double choose(int n, int k) {
        if (c[n][k] >= 0) return c[n][k];
        return c[n][k] = choose(n - 1, k - 1) + choose(n - 1, k);
    }

    private void work() {

        c = new double[60][60];
        for (int i = 0; i < 60; i++) {
            c[i][0] = c[i][i] = 1;
            for (int j = 1; j < i; j++) c[i][j] = -1;
        }
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int nc = sc.nextInt();
        for (int tc = 1; tc <= nc; tc++) {
            int n = sc.nextInt();
            int a = sc.nextInt();
            int b = sc.nextInt();
            double w = 0.01 * sc.nextInt();

            if (b >= (n + 1) / 2) {
                System.out.println(LOSS);
            } else if (a > n / 2) {
                System.out.println(WIN);
            } else {
                double win = 0;
                for (int i = n / 2 + 1 - a; i + a + b <= n; i++) {
                    win += choose(n - a - b, i) / Math.pow(2, n - a - b);
                }

                if (win > w) {
                    System.out.println(WIN);
                } else {
                    System.out.println(TIE);
                }
            }
        }

        sc.close();
    }

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();
        new election_float_da().work();
        long t = System.currentTimeMillis() - startTime;
        System.err.println(String.format("Elapsed time: %d:%02d.%03d\n", t / 60000, (t / 1000) % 60, t % 1000));
    }
}
