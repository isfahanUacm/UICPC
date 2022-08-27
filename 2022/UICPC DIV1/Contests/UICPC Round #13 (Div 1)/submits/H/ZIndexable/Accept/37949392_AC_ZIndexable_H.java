import java.util.ArrayList;
import java.util.Scanner;

public class R13_2 {

    public static long fastpow(long two, long n) {
        long ans = 1;
        while (n > 0) {
            if ((n & 1) == 0) {
                two *= two;
                n >>>= 1;
            } else {
                ans *= two;
                n--;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<String> c = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            c.add(sc.nextLine());
        }

        long ans = 0;
        int size = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (c.get(i).equals("O")) {
                ans += fastpow(2, size - i);
            }
        }
        System.out.println(ans);
    }
}