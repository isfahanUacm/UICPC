import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class stopwatch_da {

    private void work() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = sc.nextInt();
        if ((n & 1) != 0) {
            System.out.println("still running");
            System.exit(0);
        }
        int last = sc.nextInt();
        int ans = 0;
        boolean on = true;
        while (--n > 0) {
            int next = sc.nextInt();
            if (on) {
                ans += next - last;
            }

            last = next;
            on = !on;
        }

        System.out.println(ans);
    }

    public static void main(String[] args) {
        new stopwatch_da().work();
    }
}
