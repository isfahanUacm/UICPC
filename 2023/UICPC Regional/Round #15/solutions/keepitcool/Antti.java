import java.util.*;

public class Antti {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int m = input.nextInt();
		int s = input.nextInt();
		int d = input.nextInt();
		int[] c = new int[s];
		for (int i = 0; i < s; i++) c[i] = input.nextInt();
		int[] r = new int[s];
		while (n > 0) {
			int ui = -1, uc = d;
			for (int i = 0; i < s; i++) {
				if (c[i] < uc) {
					ui = i;
					uc = c[i];
				}
			}
			int z = Math.min(d-c[ui],n);
			c[ui] += z;
			r[ui] = z;
			n -= z;
		}
		int t = 0;
		for (int i = 0; i < s; i++) {
			if (r[i] == 0) t += c[i];
		}
		if (t >= m) {
			for (int i = 0; i < s; i++) System.out.print(r[i]+" ");
			System.out.println();
		} else {
			System.out.println("impossible");
		}
	}
}
