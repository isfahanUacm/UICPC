import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int test = 1; test <= t; test++) {
            int n = sc.nextInt();
            Set<Integer> sums = new HashSet<>();

            for (int i = 0; i < n; i++) {
                int value = sc.nextInt();
                sums.add(value);
            }
            Set<Integer> tas1 = new HashSet<>();
            Set<Integer> tas2 = new HashSet<>();
            for (int i = 1; i <= 1000; i++) {
                for (int j = 1; j <= 1000; j++) {
                    int sum = i + j;
                    if (sums.contains(sum)) {
                        tas1.add(i);
                        tas2.add(j);
                    }
                }
            }


            System.out.println("Case " + test + ":");

            for (int x : tas1) System.out.print(x + " ");
            System.out.println();

            for (int y : tas2) System.out.print(y + " ");
            System.out.println();
        }


    }
}
