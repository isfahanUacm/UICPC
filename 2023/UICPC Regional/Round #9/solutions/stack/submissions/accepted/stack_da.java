import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class stack_da {

	private void work() {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int nc = sc.nextInt();
		sc.nextLine();
		while (nc-- > 0) {
			s = sc.nextLine().trim().toCharArray();
			m = new int[s.length][s.length];
			System.out.println(s.length + go(0, s.length - 1));
		}
		sc.close();
	}

	private char[] s;
	private int[][] m;

	private int go(int i, int j) {
		if (i > j)
			return 0;
		if (i == j)
			return 2;
		if (m[i][j] > 0)
			return m[i][j];
		int ret = 2 + go(i + 1, j);
		for (int k = i + 1; k <= j; k++) {
			if (s[i] == s[k]) {
				int t = go(i + 1, k - 1) + go(k, j);
				if (t < ret)
					ret = t;
			}
		}
		return m[i][j] = ret;
	}

	public static void main(String[] args) {
		long startTime = System.currentTimeMillis();
		new stack_da().work();
		long t = System.currentTimeMillis() - startTime;
		System.err.println(String.format("Elapsed time: %d:%02d.%03d\n", t / 60000, (t / 1000) % 60, t % 1000));
	}

}
