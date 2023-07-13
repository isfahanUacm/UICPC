import java.util.Scanner;

public class qaly_da {

	private void work() {
		Scanner sc = new Scanner(System.in);
		int nc = sc.nextInt();
		long res = 0;
		while (nc-- > 0) {
			res += parse(sc.next()) * parse(sc.next());
		}
		sc.close();
		System.out.printf("%d.%02d0\n", res / 100, res % 100);
	}

	private long parse(String s) {
		long ret = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '.')
				continue;
			ret = 10 * ret + s.charAt(i) - '0';
		}
		return ret;
	}

	public static void main(String[] args) {
		new qaly_da().work();
	}

}
