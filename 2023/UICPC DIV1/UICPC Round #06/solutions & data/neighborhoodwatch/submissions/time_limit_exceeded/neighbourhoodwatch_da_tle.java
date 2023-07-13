import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class neighbourhoodwatch_da_tle {

    private void work() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = sc.nextInt();
        int k = sc.nextInt();
        boolean[] road = new boolean[n];
        while (k-- > 0) {
            road[sc.nextInt() - 1] = true;
        }

        sc.close();

        long res = 0;
        for (int i = 0; i < n; i++) {
            boolean safe = false;
            for (int j = i; j < n; j++) {
                safe |= road[j];
                if (safe) res++;
            }
        }

        System.out.println(res);
    }

    public static void main(String[] args) {
        new neighbourhoodwatch_da_tle().work();
    }
}
