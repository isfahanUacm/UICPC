import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine();

        for (int t=1; t<=T; t++) {
            String s = sc.nextLine().trim();
            String[] parts = s.split(":");

            int egypt=Integer.parseInt(parts[0]);
            int ghana=Integer.parseInt(parts[1]);

            int egyptTotal =1+egypt;
            int ghanaTotal =6+ghana;

            System.out.print("Case " + t + ": ");

            if (egyptTotal > ghanaTotal) {
                System.out.println("YES");
            } else if (egyptTotal < ghanaTotal) {
                System.out.println("NO");
            } else {
                int egyptAway = 1;
                int ghanaAway = ghana;

                if (egyptAway > ghanaAway) {
                    System.out.println("YES");
                } else if (egyptAway < ghanaAway) {
                    System.out.println("NO");
                } else {
                    System.out.println("PENALTIES");
                }
            }
        }
    }
}