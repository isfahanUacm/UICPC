import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long d = in.nextLong();
        double a = in.nextDouble();
        double o = in.nextDouble();
        double da = in.nextDouble();
        double doo = in.nextDouble();

        double aLeft = a - d * da;
        double oLeft = o - d * doo;

        double res;

        if (aLeft <= 0 && oLeft > 0) {
            res = 0.0;
        } else if (oLeft <= 0 && aLeft > 0) {
            res = 100.0;
        } else {
            res = (aLeft / (aLeft + oLeft)) * 100.0;
        }

        System.out.println(res);
    }
}
