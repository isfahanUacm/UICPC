import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class jobs_da {

    private void work() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        int n = sc.nextInt();
        int m = sc.nextInt();

        long[][] p = new long[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                p[i][j] = sc.nextInt();
            }
        }
        sc.close();

        long[][] a = new long[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                a[i][j] = p[i][j] + Math.max(a[i - 1][j], a[i][j - 1]);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (i > 1)
                System.out.print(" ");
            System.out.print(a[i][m]);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();
        new jobs_da().work();
        long t = System.currentTimeMillis() - startTime;
        System.err.println(String.format("Elapsed time: %d:%02d.%03d\n", t / 60000, (t / 1000) % 60, t % 1000));
    }
}
