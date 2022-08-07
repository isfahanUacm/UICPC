import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Boundary {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int tests = sc.nextInt();

        for (int i = 0; i < tests; i++) {

            long a = sc.nextLong();
            long b = sc.nextLong();

            Set<Long> set = new HashSet<>();
            set.add(1L);
            set.add(2L);

            if (a > b) {
                long t = a;
                a = b;
                b = t;
            }

            // 1
            if ((b - 1d) % (a - 1d) == 0.0)
                set.add(a - 1);

            // 2
            if ((b - 2d) % (a) == 0.0)
                set.add(a);

            // 3
            for (long j = 3; j <= a; j++) {
                if ((b) % j == 0.0 && (a - 1d) % j == 0.0)
                    set.add(j);
            }

            Object[] arr = set.toArray();
            Arrays.sort(arr);
            System.out.printf(set.size() + " ");
            for (Object x : arr)
                System.out.printf(x + " ");
            System.out.println();
        }
    }
}
