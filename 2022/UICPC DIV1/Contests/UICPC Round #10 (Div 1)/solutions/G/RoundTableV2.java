import java.util.Scanner;

public class RoundTableV2 {
    static class Fenwick {
        int[] fenwick;

        public Fenwick(int n) {
            fenwick = new int[n];
        }

        int get(int upto) {
            int res = 0;
            while (upto >= 0) {
                res += fenwick[upto];
                upto = (upto & (upto + 1)) - 1;
            }
            return res;
        }

        void upd(int at, int by) {
            while (at < fenwick.length) {
                fenwick[at] += by;
                at |= at + 1;
            }
        }
    }

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
            Fenwick fenwick = new Fenwick(n);
            fenwick.upd(w[0], 1);
            for (int i = 1; i < n; ++i) {
                int prev = w[i - 1];
                int cur = w[i];
                int skip;
                if (cur > prev) {
                    skip = fenwick.get(cur) - fenwick.get(prev);
                } else {
                    skip = fenwick.get(n - 1) - fenwick.get(prev) + fenwick.get(cur);
                }
                res += skip * (long) (n - i);
                fenwick.upd(cur, 1);
            }
            System.out.println(res);
        }
    }
}
