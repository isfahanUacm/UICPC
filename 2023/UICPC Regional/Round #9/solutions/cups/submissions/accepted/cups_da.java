import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class cups_da {

	class Cup implements Comparable<Cup> {
		int d;
		String color;

		Cup(String line) {
			String[] spl = line.split("\\s+");
			if (Character.isDigit(spl[0].charAt(0))) {
				d = Integer.parseInt(spl[0]);
				color = spl[1];
			} else {
				d = 2 * Integer.parseInt(spl[1]);
				color = spl[0];
			}
		}

		@Override
		public int compareTo(Cup o) {
			return d - o.d;
		}
	}

	private void work() throws IOException {

		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int n = sc.nextInt();
		sc.nextLine();

		Cup[] cups = new Cup[n];
		for (int i = 0; i < n; i++) {
			cups[i] = new Cup(sc.nextLine());
		}
		sc.close();

		Arrays.sort(cups);
		for (Cup cup : cups) {
			System.out.println(cup.color);
		}
	}

	public static void main(String[] args) throws IOException {
		long startTime = System.currentTimeMillis();
		new cups_da().work();
		long t = System.currentTimeMillis() - startTime;
		System.err.println(String.format("Elapsed time: %d:%02d.%03d\n", t / 60000, (t / 1000) % 60, t % 1000));
	}
}
