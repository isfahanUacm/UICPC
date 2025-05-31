import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i = 0; i < n; i++) {
            int c= sc.nextInt();
            int d ;
            int a ;
            if (c % 2 == 1) {
                d = c/2;
                a = c/2+1;
            }else {
                d = c/2;
                a = c/2;
            }

            int min = Integer.MAX_VALUE;
            int nmax1 = 0;
            int nmax2 = 0;
            for (;d > 0; d--, a++) {
                if (lcm(d, a) < min) {
                    min = lcm(d, a);
                    nmax1 = d;
                    nmax2 = a;
                }
            }
            System.out.println(nmax1 + " " + nmax2);

        }

    }
    public static int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}