import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("ghanophobia.in"));
        int T = in.nextInt();
        for (int i = 1; i <= T; i++) {
            String s = in.next();
            String[] parts = s.split(":");
            int a = Integer.parseInt(parts[0]);
            int ss = Integer.parseInt(parts[1]);

            int b = 1 + a;
            int c = 6 + ss;
            int d = 1;
            int nn = ss;

            String result;
            if (b > c) result = "YES";
            else if (b < c) result = "NO";
            else {
                if (d > nn) result = "YES";
                else if (d < nn) result = "NO";
                else result = "PENALTIES";
            }

            System.out.println("Case " + i + ": " + result);
        }
        in.close();
    }
}
