import java.util.*;

public class Antti {
	static ArrayList<Integer>[] v;
	static long[] d;
	static long[] b;
	static int[] e;

	static void error() {
		System.out.println("impossible");
		System.exit(0);
	}

	static void dfs1(int x) {
		boolean ok = true;
		long s = 0;
		int c = 0;
		for (Integer u : v[x]) {
			if (u == e[x]) continue;
			c++;
			dfs1(u);
			if (d[u] == 0) ok = false;
			s += d[u];
			b[x] += b[u];
		}
		if (ok && c != 0) {
			if (d[x] != 0 && d[x] != s) error();
			d[x] = s;
		}
		if (c == 0) b[x] = d[x] == 0 ? 1 : d[x];
		b[x] = Math.max(d[x],b[x]);
	}

	static void dfs2(int x) {
		if (d[x] <= 0) error();
		int c = 0, k = 0, z = 0;
		long s = 0;
		int g = 0;
		for (Integer u : v[x]) {
			if (u == e[x]) continue;
			c++;
			if (d[u] == 0) {z++; k = u; g += b[u];}
			s += d[u];
		}
		if (z == 0 && d[x] != s && c != 0) error();
		if (z == 1) d[k] = d[x]-s;
		if (z > 1 && g == d[x]-s) {
			for (Integer u : v[x]) {
				if (u == e[x]) continue;
				if (d[u] == 0) d[u] = b[u];
			}
		}
		for (Integer u : v[x]) {
			if (u == e[x]) continue;
			dfs2(u);
		}
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		v = new ArrayList[n+1];
		d = new long[n+1];
		b = new long[n+1];
		e = new int[n+1];
		for (int i = 1; i <= n; i++) v[i] = new ArrayList<>();
		for (int i = 2; i <= n; i++) {
			int a = input.nextInt();
			v[a].add(i);
			e[i] = a;
		}
		for (int i = 1; i <= n; i++) d[i] = input.nextLong();
		dfs1(1);
		dfs2(1);
		for (int i = 1; i <= n; i++) System.out.print(d[i]+" ");
		System.out.println();
	}
}
