import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

// Howard's C++ solution
public class slidecount_da {

    private void work() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int N = sc.nextInt();
        int C = sc.nextInt();
        int[] w = new int[100000];
        for (int i = 0; i < N; i++) w[i] = sc.nextInt();

        int s = 0, e = 0;
        int[] enter = new int[100000];
        int t = 0;
        int total = w[0];

        StringBuilder out = new StringBuilder();
        while (s < N) {
            t++;
            if (e + 1 >= N || total + w[e + 1] > C) {
                if (out.length() > 0) out.append('\n');
                out.append(t - enter[s]);
                total -= w[s++];
            } else {
                total += w[++e];
                enter[e] = t;
            }
        }

        System.out.println(out);
    }

    public static void main(String[] args) {
        new slidecount_da().work();
    }
}
