import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class multiplicationgame_da {

	class Info {
		int min, max, total;

		Info(int min, int max, int total) {
			this.min = min;
			this.max = max;
			this.total = total;
		}
	}

	List<Integer> primes;
	String[] ans = { "Alice", "Bob", "tie" };

	private void init() {
		boolean[] s = new boolean[1 << 16];
		Arrays.fill(s, true);
		for (int i = 2; i * i < s.length; i++)
			if (s[i])
				for (int j = i * i; j < s.length; j += i)
					s[j] = false;

		primes = new ArrayList<>();
		for (int i = 2; i < s.length; i++)
			if (s[i])
				primes.add(i);
	}

	private Info getInfo(int n) {
		int min = 10000;
		int max = 0;
		int tot = 0;
		for (int p : primes) {
			if (p * p > n)
				break;
			if (n % p == 0) {
				int k = 0;
				while (n % p == 0) {
					k++;
					n /= p;
				}
				tot += k;
				if (k < min)
					min = k;
				if (k > max)
					max = k;
			}
		}

		if (n > 1) {
			min = 1;
			if (max == 0)
				max = 1;
			tot++;
		}

		return new Info(min, max, tot);
	}

	private void work() {
		init();
		Scanner sc = new Scanner(System.in);
		int nc = sc.nextInt();
		while (nc-- > 0) {
			int n = sc.nextInt();
			int res = 0;
			if (sc.next().charAt(0) == 'B')
				res = 1;
			Info info = getInfo(n);

			if ((info.total & 1) != 0) {
				if (1 + info.total / 2 > info.max || info.total / 2 > info.min)
					res = 2;

			} else {
				res = 1 - res;
				if (info.total / 2 > info.min)
					res = 2;
			}

			System.out.println(ans[res]);
		}
		sc.close();
	}

	public static void main(String[] args) {
		new multiplicationgame_da().work();
	}

}
