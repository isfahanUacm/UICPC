import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class smallschedule_da {
    private void work() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int q = sc.nextInt();
        int m = sc.nextInt();
        int s = sc.nextInt();
        int l = sc.nextInt();
        sc.close();

        int k = l / m;
        int res = k * q;
        l %= m;
        if (l > 0) {
            res += q;
            s -= (m - l) * q;
            if (s < 0) s = 0;
        }

        res += (s + m - 1) / m;

        System.out.println(res);
    }

    public static void main(String[] args) {
        new smallschedule_da().work();
    }
}
