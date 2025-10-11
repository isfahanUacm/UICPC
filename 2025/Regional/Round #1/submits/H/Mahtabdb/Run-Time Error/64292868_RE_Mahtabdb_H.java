import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int test = 1; test <= t; test++) {
            int n = sc.nextInt();
            int[] sums = new int[n];
            for (int i = 0; i < n; i++) {
                sums[i] = sc.nextInt();
            }
            Arrays.sort(sums);
            int minSum = sums[0];
            System.out.println("Case " + test + ":");
         
            for (int i = 1; i <= 6; i++) {
                System.out.print(i);
                if (i < 6) {
                    System.out.print(" ");
                } else {
                    System.out.println();
                }
            }


            for (int i = 0; i < 6; i++) {
                int value = (minSum - 1) + i; 
                System.out.print(value);
                if (i < 5) {
                    System.out.print(" ");
                } else {
                    System.out.println();
                }
            }



        }
}
    }