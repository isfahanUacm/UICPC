import java.util.*;

public class Antti {
	public static long code(int[] s, int z) {
		long c = 0;
		for (int i = 0; i < 10; i++) c = c*7+s[i];
		return c*101+z;
	}

	public static HashMap<Long,Double> dp = new HashMap<>();

	public static double calc(long c) {
		long d = c;
		if (dp.containsKey(d)) return dp.get(d);
		int z = (int)(c%101);
		c /= 101;
		int[] s = new int[10];
		int u = 0;
		for (int i = 9; i >= 0; i--) {
			s[i] = (int)(c%7);
			if (s[i] != 0) u++;
			c /= 7;
		}
		double p = 0;
		if (z == 0 || u == 0) {
			p = 1;
			for (int i = 5; i < 10; i++) if (s[i] > 0) p = 0;
		} else {
			for (int i = 1; i <= u; i++) {
				int[] f = new int[10];
				for (int j = 0; j < 10; j++) f[j] = s[j];
				int a = 0;
				for (int j = 0; j < 10; j++) {
					if (s[j] != 0) a++;
					if (a == i) {
						f[j]--;
						while (j%5 < 4 && f[j] < f[j+1]) {
							int t = f[j]; f[j] = f[j+1]; f[j+1] = t;
							j++;
						}
						break;
					}
				}
				p += calc(code(f,z-1))/u;
			}
		}
		dp.put(d,p);
		return p;
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int x = input.nextInt();
		int y = input.nextInt();
		int z = input.nextInt();
		int[] s = new int[10];
		for (int i = 0; i < x; i++) s[i] = input.nextInt();
		for (int i = 0; i < y; i++) s[5+i] = input.nextInt();
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 4; j++) {
				if (s[j] < s[j+1]) {int t = s[j]; s[j] = s[j+1]; s[j+1] = t;}
			}
			for (int j = 5; j < 9; j++) {
				if (s[j] < s[j+1]) {int t = s[j]; s[j] = s[j+1]; s[j+1] = t;}
			}
		}
		System.out.println(calc(code(s,z)));
	}
}
