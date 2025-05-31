import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();

        for(long i = 0; i < n; i++) {
            long c = sc.nextLong();
            long d;
            long a;
            if (c % 2 == 1) {
                d = c / 2;
                a = c / 2 + 1;
            } else {
                d = c / 2;
                a = c / 2;
            }

            long min = Long.MAX_VALUE;
            long nmax1 = 0;
            long nmax2 = 0;
            for (; d > 0; d--, a++) {
                if (lcm(d, a) < min) {
                    min = lcm(d, a);
                    nmax1 = d;
                    nmax2 = a;
                }
            }
            System.out.println(nmax1 + " " + nmax2);
        }
    }
    public static long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }
    public static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}