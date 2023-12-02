import java.util.*;

public class Antti {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		long n = input.nextLong();
		long m = input.nextLong();
		long a = input.nextLong();
		long b = n*m-a;
		if (a == 0 || a == n*m) {
			System.out.println(0);
		} else if (a%n == 0 || a%m == 0) {
			System.out.println(1);
		} else {
			if (n > m) {long t = n; n = m; m = t;}
			int r = 3;
			for (long x = 1; x*x <= a; x++) {
				if (a%x == 0 && x <= n && a/x <= m) {
					r = 2;
				}
			}
			for (long x = 1; x*x <= b; x++) {
				if (b%x == 0 && x <= n && b/x <= m) {
					r = 2;
				}
			}
			System.out.println(r);
		}
	}
}
