import java.util.*;

public class phone_og {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for (int t=in.nextInt(); t>0; --t) {
			int n = in.nextInt();
			long[] a = new long[n];
			for (int i=0; i<n; ++i) {
				a[i] = Long.parseLong("1"+in.next());
			}
			System.out.println(solve(a)?"YES":"NO");
		}
	}

	static boolean solve(long[] nums) {
		Set<Long> all = new HashSet<Long>();
		for (long i : nums) all.add(i);
		for (long i : nums) {
			while (i > 9) {
				i /= 10;
				if (all.contains(i)) {
					return false;
				}
			}
		}
		return true;
	}

}