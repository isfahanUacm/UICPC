import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            long L = sc.nextLong();
            long R = sc.nextLong();
            long count = countPerfectSquares(L, R);
            System.out.println(count);
        }
    }
    static long countPerfectSquares(long L, long R) {
        long sqrtL = (long) Math.ceil(Math.sqrt(L));
        long sqrtR = (long) Math.floor(Math.sqrt(R));
        if (sqrtL > sqrtR) return 0;
        return sqrtR - sqrtL + 1;
    }
}