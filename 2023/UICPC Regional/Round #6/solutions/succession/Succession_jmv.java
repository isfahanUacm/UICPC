public class Succession_jmv {
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		int n = in.nextInt(), m = in.nextInt();
		java.util.HashMap<String, Long> D = new java.util.HashMap<String, Long>();
		D.put(in.next(), 1L << 62);
		java.util.HashMap<String, String[]> M = new java.util.HashMap<String, String[]>();
		for (int i = 0; i < n; i++)
			M.put(in.next(), new String[]{in.next(), in.next()});
		long max = -1;
		String maxs = "";
		for (int i = 0; i < m; i++) {
			String s = in.next();
			long d = dfs(s, M, D);
			if (d > max) {
				max = d;
				maxs = s;
			}
		}
		System.out.println(maxs);
	}
	
	static long dfs(String s, java.util.HashMap<String, String[]> M, java.util.HashMap<String, Long> D) {
		if (D.containsKey(s)) return D.get(s);
		if (!M.containsKey(s)) return 0L;
		String[] ps = M.get(s);
		long d = (dfs(ps[0], M, D) + dfs(ps[1], M, D)) / 2;
		D.put(s, d);
		return d;
	}
}