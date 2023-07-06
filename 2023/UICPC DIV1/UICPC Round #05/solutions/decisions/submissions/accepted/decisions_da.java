import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class decisions_da {

	private void work() {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int n = sc.nextInt();
		int[] p = getP(n);
		int[] a = read(sc, n, p);
		System.out.println(solve(n, a));
		sc.close();
	}

	private int solve(int n, int[] a) {
		int len = 1 << n;
		int res = 1;
		while (len > 1) {
			for (int i = 0; i < len; i += 2) {
				if (a[i] >= 0 && a[i + 1] >= 0 && a[i] == a[i + 1]) {
					a[i / 2] = a[i];
				} else {
					res += 2;
					a[i / 2] = -1;
				}
			}
			len >>= 1;
		}
		return res;
	}

	private int[] read(Scanner sc, int n, int[] p) {
		int[] a = new int[1 << n];
		for (int i = 0; i < 1 << n; i++) {
			a[p[i]] = sc.nextInt();
		}
		return a;
	}

	private int[] getP(int n) {
		int[] p = new int[1 << n];
		for (int i = 0; i < n; i++) {
			int len = 1 << (n - 1 - i);
			int bit = 0;
			int cnt = 0;
			for (int j = 0; j < 1 << n; j++) {
				p[j] |= bit << i;
				if (++cnt == len) {
					cnt = 0;
					bit = 1 - bit;
				}
			}
		}
		return p;
	}

	public static void main(String[] args) {
		new decisions_da().work();
	}

}
