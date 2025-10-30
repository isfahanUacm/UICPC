import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        int m1 = in.nextInt();
        int k1 = in.nextInt();
        int m2 = n*m1;
        int k2 = n*k1;
        double m3 = m - m2;
        double k3 = k - k2;
        double res = m3 / (m3 + k3);
        System.out.println(res*100);
    }
}