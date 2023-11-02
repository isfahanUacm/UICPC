import java.util.Scanner;

public class fizzbuzz_da {

	private void work() {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		int y = sc.nextInt();
		int n = sc.nextInt();
		sc.close();

		for (int i = 1; i <= n; i++) {
			String out = "";
			if (i % x == 0)
				out = "Fizz";
			if (i % y == 0)
				out += "Buzz";
			if (out.length() == 0)
				out += i;
			System.out.println(out);
		}
	}

	public static final void main(String[] args) {
		long startTime = System.currentTimeMillis();
		new fizzbuzz_da().work();
		long t = System.currentTimeMillis() - startTime;
		System.err.println(String.format("Elapsed time: %d:%02d.%03d\n", t / 60000, (t / 1000) % 60, t % 1000));

	}
}
