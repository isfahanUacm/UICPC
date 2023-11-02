public class Doodle_jmv {
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		for (int n = in.nextInt(); n-- > 0; ) {
			in.nextLine();
			int a = in.nextInt() - 1, b = in.nextInt() - 1;
			int t = (a * b) / gcd(a, b), c1 = t / a, c2 = t / b;
			System.out.println(t - ((c1 - 1) * (c2 - 1)) / 2 + 1);
		}
		if (in.hasNext()) System.out.println("Wrong input format!");
	}
	
	static int gcd(int a, int b) {
		if (a > b) return gcd(b, a);
		if (a == 0) return b;
		return gcd(b % a, a);
	}
}