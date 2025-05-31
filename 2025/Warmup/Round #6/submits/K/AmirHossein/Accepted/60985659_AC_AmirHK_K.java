import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        int k = sc.nextInt();
        int d = sc.nextInt();


        int batches = (n + k - 1) / k;
        int timeOneOven = batches * t;


        int cakes = 0;
        int time = 0;
        while (cakes < n) {
            time += t;
            if (time <= d) {
                cakes += k;
            } else {

                cakes += 2 * k;
            }
        }

        if (time < timeOneOven) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}