import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long c = sc.nextLong();
        int x = sc.nextInt();
        ArrayList<Long> xx = new ArrayList();
        ArrayList<Long> yy = new ArrayList<>();

        for (int i = 0; i < x; i++) {
            long p = sc.nextLong();
            xx.add(p);
            yy.add(p);
        }

        for (long p : yy) {
            if (c % p != 0) continue;

            long q = c / p;
            if (q != p && xx.contains(q)) {
                long a = Math.min(p, q);
                long b = Math.max(p, q);
                System.out.println(a + " " + b);
                return;
            }
        }
    }
}
