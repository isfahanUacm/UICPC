import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            long n = sc.nextLong();
            if (n % 2 == 0) {
                System.out.println((n / 2) + " " + (n / 2));
            } else {
                long minDiv = -1;
                for (long d = 2; d * d <= n; d++) {
                    if (n % d == 0) {
                        minDiv = d;
                        break;
                    }
                }
                if (minDiv == -1) {
                    System.out.println("1 " + (n - 1));
                } else {
                    long a = n / minDiv;
                    long b = n - a;
                    System.out.println(a + " " + b);
                }
            }
        }
    }
}