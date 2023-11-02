import java.io.*;
import java.util.*;

public class Curve {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        while (scan.hasNext()) {
            double R = scan.nextDouble();
            double S = scan.nextDouble();

            double V = Math.sqrt(R * (S + 0.16) / 0.067);

            long ans = Math.round(V);

            System.out.println(ans);
        }
    }
}
