import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int x1 = input.nextInt();
        int y1 = input.nextInt();
        int x2 = input.nextInt();
        int y2 = input.nextInt();
        int result = 0;
        result += (x2 - x1) * (n+1);
        result -= (y1 - y2) ;
        System.out.println(result);
    }
}