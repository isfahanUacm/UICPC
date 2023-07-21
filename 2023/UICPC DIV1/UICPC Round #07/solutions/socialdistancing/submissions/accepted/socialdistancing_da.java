import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class socialdistancing_da {

    private void work() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int s = sc.nextInt();
        int n = sc.nextInt();
        int[] a = new int[n + 1];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        a[n] = a[0] + s;

        int answer = 0;
        for (int i = 0; i < n; i++) {
            int gap = a[i + 1] - a[i] - 1;
            if (gap > 2) answer += (gap - 1) / 2;
        }

        System.out.println(answer);
    }

    public static void main(String[] args) {
        new socialdistancing_da().work();
    }
}
