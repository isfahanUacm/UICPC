import java.util.Scanner;

public class RoundTable {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int nt = scanner.nextInt();
        for (int it = 0; it < nt; ++it) {
            int n = scanner.nextInt();
            int[] p = new int[n];
            for (int i = 0; i < n; ++i) {
                p[i] = scanner.nextInt() - 1;
            }
            int[] w = new int[n];
            for (int i = 0; i < n; ++i) w[p[i]] = i;
            long res = 0;
            for (int i = 0; i + 1 < n; ++i) {
                if (w[i] > w[i + 1]) {
                    res += (i + 1) * (long) (n - i - 1);
                }
            }
            int[] fenwick = new int[n];
            for (int i = n - 1; i >= 0; --i) {
                int at = p[i];
                while (at >= 0) {
                    res -= fenwick[at];
                    at = (at & (at + 1)) - 1;
                }
                at = p[i];
                while (at < n) {
                    fenwick[at] += 1;
                    at |= at + 1;
                }
            }
            System.out.println(res);
        }
    }
}
