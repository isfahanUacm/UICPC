import java.util.Scanner;

public class trees_da {
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

        if (curx == x) return "Yes";

        if (curx < xa || curx > xb || cury < ya || cury > yb) {
            return String.format("No\n%d %d\n", curx, cury);
        }

        // we are inside the rectangle, but not there yet
        long m = 1 + Math.min(xb / curx, yb / cury);
        curx *= m;
        cury *= m;

        System.err.println(curx + " " + cury);

        if (curx >= x)
            return "Yes";

        return String.format("No\n%d %d\n", curx, cury);
    }

    private long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static void main(String[] args) {
        System.out.println(new trees_da().work());
    }
}
