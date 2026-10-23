
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            Arrays.sort(a);

            int current = 1;
            int maxLen = 1;

            for (int i = 1; i < n; i++) {
                if (a[i] - a[i - 1] <= 1) {
                    current++;
                } else {
                    current = 1;
                }
                maxLen = Math.max(maxLen, current);
            }
            System.out.println(n - maxLen);
        }

        
    }
}
