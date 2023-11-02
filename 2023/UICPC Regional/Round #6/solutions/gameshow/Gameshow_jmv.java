public class Gameshow_jmv {
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in); 
		int n = in.nextInt(), k = in.nextInt();
		double[] P = new double[k];
		java.util.Arrays.fill(P, 1);
		double sum = k;
		for (int i = k + 1; i <= n; i++) 
			sum += -P[i % k] + (P[i % k] = sum / i);
		System.out.println(P[n % k]);
	}
}

