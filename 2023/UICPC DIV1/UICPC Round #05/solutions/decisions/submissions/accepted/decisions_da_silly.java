public class decisions_da_silly {

	private byte[] input = new byte[1 << 21];
	private int idx;

	private int readInt() {
		while (input[idx] < '0')
			idx++;
		int ret = 0;
		while (input[idx] >= '0')
			ret = 10 * ret + input[idx++] - '0';
		return ret;
	}

	private int nextDigit() {
		while (input[idx] < '0')
			idx++;
		return input[idx++] - '0';
	}

	private void work() {

		try {
			System.in.read(input, 0, input.length);
		} catch (Exception e) {
			// blah
		}

		int n = readInt();
		int[] p = getP(n);
		int[] a = read(n, p);
		System.out.println(solve(n, a));
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

	private int[] read(int n, int[] p) {
		int[] a = new int[1 << n];
		for (int i = 0; i < 1 << n; i++) {
			a[p[i]] = nextDigit();
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
		new decisions_da_silly().work();
	}

}
