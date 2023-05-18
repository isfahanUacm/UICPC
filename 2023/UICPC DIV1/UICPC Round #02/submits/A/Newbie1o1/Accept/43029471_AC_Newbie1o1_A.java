import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int T = scanner.nextInt();
        int sum = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            int rating = scanner.nextInt();
            sum += rating;
            if (sum > T) {
                break;
            }
            count++;
        }
        System.out.println(count);
    }
}
