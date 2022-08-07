import java.util.Scanner;

public class r10_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int ri_max = Integer.MIN_VALUE;
            int wi_max = Integer.MIN_VALUE;
            String ans = "";
            for (int j = 0; j < m; j++) {
                int ri = sc.nextInt();
                int wi = sc.nextInt();
                if (ri > ri_max) {
                    ri_max = ri;
                }
                if (wi > wi_max) {
                    wi_max = wi;
                }
            }
            if (ri_max + wi_max > n) {
                System.out.println("IMPOSSIBLE");
            } else {
                for (int j = 0; j < ri_max; j++) {
                    ans += "R";
                }
                for (int j = 0; j < n - ri_max; j++) {
                    ans += "W";
                }
                System.out.println(ans);
            }
        }
    }
}