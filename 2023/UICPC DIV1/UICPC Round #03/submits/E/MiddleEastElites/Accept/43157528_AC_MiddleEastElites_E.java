import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        long n;
        long p;
        long s;
        Scanner cin = new Scanner(System.in);
        n = cin.nextLong();
        p = cin.nextLong();
        s = cin.nextLong();
        long i;
        boolean u = false;
        for (i = 0; i < s; i++) {
            long add = cin.nextLong();
            for (int j = 0; j < add; j++) {
                long x = cin.nextLong();
                if (x == p)
                    u = true;
            }
            if (u)
                System.out.println("KEEP");
            else System.out.println("REMOVE");
            u = false;
        }

    }
}