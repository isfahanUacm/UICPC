import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int locks = binomial(n, m) - 1;
            System.out.println(locks);
        }
    }

    static int binomial(int n, int k) {
        if (k > n - k) {
            k = n - k;
        }
        int b = 1;
        for (int i = 1, m = n; i <= k; i++, m--) {
            b = b * m / i;
        }
        return b;
    }
}
