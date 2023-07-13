import java.util.Scanner;

public class trees_da_bf {
    private String work() {

        Scanner sc = new Scanner(System.in);
        long x = sc.nextLong();
        long y = sc.nextLong();
        long xa = sc.nextLong();
        long ya = sc.nextLong();
        long xb = sc.nextLong();
        long yb = sc.nextLong();
        sc.close();

        long g = gcd(x, y);
        long curx = x / g;
        long cury = y / g;

        String res = "Yes";
        while (curx < x) {
            if (curx < xa || curx > xb || cury < ya || cury > yb) {
                res = String.format("No\n%d %d\n", curx, cury);
                break;
            }

            curx += x / g;
            cury += y / g;
        }

        return res;
    }

    private long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static void main(String[] args) {
        System.out.println(new trees_da_bf().work());
    }
}
