import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0 ; i < n; i++) {
            int total = sc.nextInt();
            int first = sc.nextInt();
            int second = 0;
            second = (total - first)/2;
            first = second + first;
            System.out.println(first + " " + second);
        }
    }
}