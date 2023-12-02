import java.util.*;

public class Antti {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int k = input.nextLine().split(" ").length;
		int n = input.nextInt();
		String[] w = new String[n];
		for (int i = 0; i < n; i++) w[i] = input.next();
		int[] s = new int[n];
		int p = 0;
		ArrayList<String> a = new ArrayList<>();
		ArrayList<String> b = new ArrayList<>();
		for (int h = 0; h < n; h++) {
			int c = 0;
			while (c < k) {
				if (s[p] == 0) {
					c++;
				}
				if (c == k) {
					s[p] = 1;
					if (h%2 == 0) a.add(w[p]);
					else b.add(w[p]);
				}
				p++;
				if (p == n) p = 0;
			}
		}
		System.out.println(a.size());
		for (String x : a) System.out.println(x);
		System.out.println(b.size());
		for (String x : b) System.out.println(x);
	}
}
