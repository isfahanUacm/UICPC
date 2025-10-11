import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int T=sc.nextInt();
        for (int i=1; i<=T;i++) {
            long N = sc.nextLong();
            String winner;
            if (N % 4==0||N%4 == 1)
                winner="Wahdan";
            else
                winner="Bakkar";
            System.out.println("Case " + i+ ": " + winner);
        }
    }
}