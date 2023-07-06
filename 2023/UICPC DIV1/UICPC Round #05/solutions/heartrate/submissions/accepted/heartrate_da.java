import java.util.Scanner;

public class heartrate_da {

	private void work() {
		Scanner sc = new Scanner(System.in);
		int nc = sc.nextInt();
		while (nc-- > 0) {
			int b = sc.nextInt();
			double p = sc.nextDouble();
			System.out.printf("%.4f %.4f %.4f\n", 60 * (b - 1) / p, 60 * b / p, 60 * (b + 1) / p);
		}
		sc.close();
	}

	public static void main(String[] args) {
		new heartrate_da().work();
	}

}
