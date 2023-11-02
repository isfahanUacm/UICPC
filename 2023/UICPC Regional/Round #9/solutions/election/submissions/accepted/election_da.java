import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class election_da {

    private static final String LOSS = "RECOUNT!";
    private static final String TIE = "PATIENCE, EVERYONE!";
    private static final String WIN = "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!";

    private void work() {

        int lim = 60;
        long[][] s = new long[lim + 1][lim + 1];
        for (int i = 0; i <= lim; i++) {
            s[i][0] = s[i][i] = 1L;
            for (int j = 1; j < i; j++) {
                s[i][j] = s[i - 1][j - 1] + s[i - 1][j];
            }
        }
        for (int i = 0; i <= lim; i++) {
            for (int j = i - 1; j >= 0; j--) {
                s[i][j] += s[i][j + 1];
            }
        }

        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int nc = sc.nextInt();
        for (int tc = 1; tc <= nc; tc++) {
            int n = sc.nextInt();
            int a = sc.nextInt();
            int b = sc.nextInt();
            int w = sc.nextInt();

            if (b >= (n + 1) / 2) {
                System.out.println(LOSS);
            } else if (a > n / 2 || w * (1L << (n - a - b)) < 100 * s[n - a - b][n / 2 + 1 - a]) {
                System.out.println(WIN);
            } else {
                System.out.println(TIE);
            }
        }

        sc.close();
    }

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();
        new election_da().work();
        long t = System.currentTimeMillis() - startTime;
        System.err.println(String.format("Elapsed time: %d:%02d.%03d\n", t / 60000, (t / 1000) % 60, t % 1000));
    }
}
