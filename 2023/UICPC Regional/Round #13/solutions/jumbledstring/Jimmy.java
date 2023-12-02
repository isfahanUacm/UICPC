import java.util.*;

public class Jimmy {

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt(), b = scanner.nextInt(), c = scanner.nextInt(), d = scanner.nextInt();

        double xq = Math.sqrt(1.0/4 + 2 * a);
        double yq = Math.sqrt(1.0/4 + 2 * d);
        int[] xp = new int[] { (int) Math.round(1.0/2 + xq), (int) Math.round(1.0/2 - xq) };
        int[] yp = new int[] { (int) Math.round(1.0/2 + yq), (int) Math.round(1.0/2 - yq) };

        int xs = -1, ys = -1;
        for(int x : xp) {
            for(int y : yp) {
                if (x >= 0 && y >= 0 && x+y > 0 && x*(x-1) == 2*a && y*(y-1) == 2*d && x*y == b+c) {
                    xs = x;
                    ys = y;
                }
            }
        }
        if (xs < 0) {
            System.out.println("impossible");
        } else {
            while (xs + ys > 0) {
                if (xs > 0 && b >= ys) {
                    System.out.print("0");
                    b -= ys;
                    xs--;
                } else {
                    System.out.print("1");
                    ys--;
                }
            }
            System.out.println();
        }
    }
}
