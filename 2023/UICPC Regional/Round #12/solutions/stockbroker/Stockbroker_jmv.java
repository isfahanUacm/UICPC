public class Stockbroker_jmv {

	public static void main(String args[]) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		
		long m = 100, s = 0;
		int n = 0;
		boolean up = false;
		for (int d = in.nextInt() - 1, c = in.nextInt(); --d >= 0; c = n) {
			n = in.nextInt();
			if (up && n < c) {
				m += s * c;
				s = 0;
				up = false;
			}
			if (!up && n > c) {
				s = Math.min(m / c, 100000L);
				m -= s * c;
				up = true;
			}
		}
		System.out.println(m + s * n);
		
		in.close();
	}
}
