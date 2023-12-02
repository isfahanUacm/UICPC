import java.util.Scanner;

/**
 * @author Torstein Strømme
 */
public class TorsteinNSquared {
    private final static long MOD = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), K = sc.nextInt();

        long[][] dp = new long[N+1][N+1];
        dp[1][1] = 1;
        for (int i = 2; i <= N; i++) {
            dp[i][i] = (dp[i-1][i-1] * i) % MOD;
            dp[2][i] = 2;
        }

        for (int k = 3; k <= K; k++) {
            for (int n = k+1; n <= N; n++) {
                dp[k][n] = (k * dp[k-1][n-1] + (k-1) * dp[k][n-1]) % MOD;
            }
        }

        System.out.println(dp[K][N]);

    }

}
