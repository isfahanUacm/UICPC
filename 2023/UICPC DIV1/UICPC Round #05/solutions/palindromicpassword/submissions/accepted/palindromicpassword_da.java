import java.io.IOException;
import java.util.Scanner;

public class palindromicpassword_da {

	private void work() {
		Scanner sc = new Scanner(System.in);
		int nc = sc.nextInt();
		while (nc-- > 0) {
			System.out.println(solve(sc.nextInt()));
		}
		sc.close();
	}

	private int solve(int n) {
		int diff = 0;
		while (diff < 10000000) {
			if (100000 <= n - diff && isPali(n - diff))
				return n - diff;
			if (isPali(n + diff))
				return n + diff;
			diff++;
		}
		return 0;
	}

	private boolean isPali(int n) {
		String s = Integer.toString(n);
		for (int i = 0; i < 3; i++) {
			if (s.charAt(i) != s.charAt(5 - i))
				return false;
		}
		return true;
	}

	public static void main(String[] args) throws IOException {
		new palindromicpassword_da().work();
	}
}
