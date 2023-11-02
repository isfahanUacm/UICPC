import java.util.Scanner;

import static java.lang.Math.sqrt;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int R = scanner.nextInt();
            double S = scanner.nextDouble();
            double V = sqrt((R * (S + 0.16)) / 0.067);
            System.out.println(Math.round(V));
        }
    }
}
