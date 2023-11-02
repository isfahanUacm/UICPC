import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class studying_da {

	private void work() {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int n = sc.nextInt();
		int t = sc.nextInt();
		int blah = (int) Math.sqrt(2400000 / n / t);
		double r = 1.0 / blah;
		t *= blah;
		double[][] f = new double[n][t + 1];
		for (int i = 0; i < n; i++) {
			double a = sc.nextDouble();
			double b = sc.nextDouble();
			double c = sc.nextDouble();
			for (int j = 0; j <= t; j++) {
				double x = r * j;
				f[i][j] = (a * x + b) * x + c;
			}
		}
		sc.close();

		double[][] m = new double[n][t + 1];
		System.arraycopy(f[0], 0, m[0], 0, t + 1);
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < t; j++) {
				m[i][0] = Math.max(f[i][0], m[i-1][0]);
				for (int k = 1; k + j <= t; k++) {
					if (m[i - 1][j] + f[i][k] > m[i][k + j])
						m[i][k + j] = m[i - 1][j] + f[i][k];
				}
			}
		}

		System.out.println(m[n - 1][t] / n);
	}

	public static void main(String[] args) {
		long startTime = System.currentTimeMillis();
		new studying_da().work();
		long t = System.currentTimeMillis() - startTime;
		System.err.println(String.format("Elapsed time: %d:%02d.%03d\n", t / 60000, (t / 1000) % 60, t % 1000));
	}

}
