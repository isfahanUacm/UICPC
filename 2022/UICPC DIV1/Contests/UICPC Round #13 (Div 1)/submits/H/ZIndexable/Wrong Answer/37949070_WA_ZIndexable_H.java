import java.util.ArrayList;
import java.util.Scanner;

public class R13_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<String> c = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            c.add(sc.nextLine());
        }

        long ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (c.get(i).equals("O")) {
                ans += Math.pow(2, i);
            }
        }
        System.out.println(ans);
    }
}