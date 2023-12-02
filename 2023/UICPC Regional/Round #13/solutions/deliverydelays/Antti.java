import java.util.*;

public class Antti {
	public static int n, m, k;
	public static ArrayList<Integer>[] ge = new ArrayList[1001];
	public static ArrayList<Long>[] gw = new ArrayList[1001];
	public static long[] s = new long[1001];
	public static int[] u = new int[1001];
	public static long[] t = new long[1001];
	public static long[][] d = new long[1001][1001];
	public static final long INF = 999999999999999L;

	private static class Entry implements Comparable<Entry> {
		public long d;
		public int x;

		public Entry(long d, int x) {
			this.d = d;
			this.x = x;
		}

		public int compareTo(Entry e) {
			if (this.d < e.d) return -1;
			if (this.d > e.d) return 1;
			return 0;
		}
	}

	public static void dijkstra(int x) {
		for (int i = 1; i <= n; i++) {
			d[x][i] = INF;
		}
		d[x][x] = 0;
		PriorityQueue<Entry> q = new PriorityQueue<>();
		q.add(new Entry(0,x));
		boolean[] z = new boolean[n+1];
		while (q.size() > 0) {
			Entry e = q.poll();
			if (z[e.x]) continue;
			z[e.x] = true;
			for (int i = 0; i < ge[e.x].size(); i++) {
				int ux = ge[e.x].get(i);
				long ud = e.d+gw[e.x].get(i);
				if (d[x][ux] > ud) {
					d[x][ux] = ud;
					q.add(new Entry(ud,ux));
				}
			}
		}
	}

	public static boolean check(long x) {
		long[] dp = new long[k+2];
		dp[k+1] = INF;
		for (int i = k; i >= 1; i--) {
			long z = 0;
			long w = INF;
			dp[i] = -INF;
			for (int j = i; j <= k; j++) {
				z += (i == j) ? d[1][u[j]] : d[u[j-1]][u[j]];
				w = Math.min(w,s[j]+x-z);
				long r = j == n ? 0 : d[u[j]][1];
				if (dp[j+1] == -INF) continue;
				long g = Math.min(w,dp[j+1]-z-r);
				if (g >= t[j] && g >= dp[i]) dp[i] = g;
			}
		}
		return dp[1] >= 0;
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		n = input.nextInt();
		m = input.nextInt();
		for (int i = 1; i <= n; i++) {
			ge[i] = new ArrayList<Integer>();
			gw[i] = new ArrayList<Long>();
		}
		for (int i = 1; i <= m; i++) {
			int u = input.nextInt();
			int v = input.nextInt();
			int d = input.nextInt();
			ge[u].add(v);
			gw[u].add((long)d);
			ge[v].add(u);
			gw[v].add((long)d);
		}
		for (int i = 1; i <= n; i++) {
			dijkstra(i);
		}
		k = input.nextInt();
		for (int i = 1; i <= k; i++) {
			s[i] = input.nextInt();
			u[i] = input.nextInt();
			t[i] = input.nextInt();
		}
		long k = -1;
		for (long b = INF; b >= 1; b /= 2) {
			while (!check(k+b)) k += b;
		}
		System.out.println(k+1);
	}
}
