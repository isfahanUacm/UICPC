import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long c = in.nextLong(); 
        long n = in.nextLong(); 

        long bet;
        if (c > n) {
            bet = 0;
        } else if (c == n) {
            bet = n;
        } else { 
            bet = c + 1;
        }

        System.out.println(bet);
    }
}
