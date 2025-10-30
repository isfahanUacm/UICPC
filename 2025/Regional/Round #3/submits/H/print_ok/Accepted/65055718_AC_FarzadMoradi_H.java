import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String a = in.next();
        String b = in.next();
        String c = in.next();

        StringBuilder result = new StringBuilder();

        while (!a.isEmpty() || !b.isEmpty() || !c.isEmpty()) {
            char x;
            if (a.isEmpty()) {
                x = '0';
            } else {
                x = a.charAt(a.length() - 1);
            }

            char y;
            if (b.isEmpty()) {
                y = '0';
            } else {
                y = b.charAt(b.length() - 1);
            }

            char z;
            if (c.isEmpty()) {
                z = '0';
            } else {
                z = c.charAt(c.length() - 1);
            }

            char winner;
            if (x == y) {
                winner = '3';
            } else if (x == z ) {
                winner = '2';
            } else if (y == z) {
                winner = '1';
            } else {
                winner = '0';
            }

            result.append(winner);

            if (winner != '1' && !a.isEmpty() && a.charAt(a.length() - 1) == winner)
                a = a.substring(0, a.length() - 1);
            if (winner != '2' && !b.isEmpty() && b.charAt(b.length() - 1) == winner)
                b = b.substring(0, b.length() - 1);
            if (winner != '3' && !c.isEmpty() && c.charAt(c.length() - 1) == winner)
                c = c.substring(0, c.length() - 1);
        }

        System.out.println(result.reverse().toString());
    }
}


