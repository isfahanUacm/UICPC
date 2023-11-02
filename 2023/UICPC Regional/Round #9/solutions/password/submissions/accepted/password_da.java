import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class password_da {

    class P implements Comparable<P> {
        String w;
        int p;

        P(String[] wp) {
            this.w = wp[0];
            this.p = 10000 * (wp[1].charAt(0) - '0') + Integer.parseInt(wp[1].substring(2));
        }

        @Override
        public int compareTo(P o) {
            return o.p - p;
        }
    }

    private void work() {

        String alphabet = "";
        for (int i = 0; i < 26; i++) {
            if (i < 10)
                alphabet += (char) (i + '0');
            alphabet += (char) (i + 'a');
            alphabet += (char) (i + 'A');
        }

        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = sc.nextInt();
        sc.nextLine();

        P[] a = new P[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = new P(sc.nextLine().split("\\s+"));
            sum += a[i].p;
        }
        sc.close();

        Arrays.sort(a);
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += (1 + i) * a[i].p;
        }

        System.out.printf("%d.%04d\n", res / 10000, res % 10000);
    }

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();
        new password_da().work();
        long t = System.currentTimeMillis() - startTime;
        System.err.println(String.format("Elapsed time: %d:%02d.%03d\n", t / 60000, (t / 1000) % 60, t % 1000));
    }
}
