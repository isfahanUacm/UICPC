

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long t = sc.nextLong();


        while (t-- > 0) {
            long n = sc.nextLong();
            Set<Long> set = new HashSet<>();
            for (long i = 1; i <= n; i++) {
                set.add(d(i));
            }
            System.out.println(set.size());
        }

    }

    public static long d(long x) {
        long ans = 1;
        while (x > 0) {
            ans *= (x%10);
            x /= 10;
        }
        return ans;
    }

}
