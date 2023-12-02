import java.util.*;
import java.io.*;

public class AnttiWithKattio {
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
		Kattio io = new Kattio(System.in);
		int n = io.getInt();
		v = new ArrayList[n+1];
		d = new long[n+1];
		b = new long[n+1];
		e = new int[n+1];
		for (int i = 1; i <= n; i++) v[i] = new ArrayList<>();
		for (int i = 2; i <= n; i++) {
			int a = io.getInt();
			v[a].add(i);
			e[i] = a;
		}
		for (int i = 1; i <= n; i++) d[i] = io.getLong();
		dfs1(1);
		dfs2(1);
		for (int i = 1; i <= n; i++) io.print(d[i]+" ");
		io.println();
        io.flush();
	}
}
/** Simple yet moderately fast I/O routines.
 *
 * Example usage:
 *
 * Kattio io = new Kattio(System.in, System.out);
 *
 * while (io.hasMoreTokens()) {
 *    int n = io.getInt();
 *    double d = io.getDouble();
 *    double ans = d*n;
 *
 *    io.println("Answer: " + ans);
 * }
 *
 * io.close();
 *
 *
 * Some notes:
 *
 * - When done, you should always do io.close() or io.flush() on the
 *   Kattio-instance, otherwise, you may lose output.
 *
 * - The getInt(), getDouble(), and getLong() methods will throw an
 *   exception if there is no more data in the input, so it is generally
 *   a good idea to use hasMoreTokens() to check for end-of-file.
 *
 * @author: Kattis
 */

class Kattio extends PrintWriter {
    public Kattio(InputStream i) {
        super(new BufferedOutputStream(System.out));
        r = new BufferedReader(new InputStreamReader(i));
    }
    public Kattio(InputStream i, OutputStream o) {
        super(new BufferedOutputStream(o));
        r = new BufferedReader(new InputStreamReader(i));
    }

    public boolean hasMoreTokens() {
        return peekToken() != null;
    }

    public int getInt() {
        return Integer.parseInt(nextToken());
    }

    public double getDouble() {
        return Double.parseDouble(nextToken());
    }

    public long getLong() {
        return Long.parseLong(nextToken());
    }

    public String getWord() {
        return nextToken();
    }



    private BufferedReader r;
    private String line;
    private StringTokenizer st;
    private String token;

    private String peekToken() {
        if (token == null)
            try {
                while (st == null || !st.hasMoreTokens()) {
                    line = r.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                }
                token = st.nextToken();
            } catch (IOException e) { }
        return token;
    }

    private String nextToken() {
        String ans = peekToken();
        token = null;
        return ans;
    }
}
