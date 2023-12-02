import java.util.*;
import java.io.*;

public class AnttiWithKattio {
	public static void main(String[] args) {
        Kattio io = new Kattio(System.in);
		int n = io.getInt();
		int m = io.getInt();
		if (m < n) {
			System.out.println("impossible");
			return;
		}
		int b = io.getInt()+1;
		int r = io.getInt();
		int[][] start = new int[n][n];
		int[][] first = new int[n][n];
		int[][] total = new int[n][n];
		int[][] pref = new int[n][n];
		int[] pos = new int[n];
		int[] cur = new int[n];
		while (r-- > 0) {
			int s = io.getInt()+1;
			int k = io.getInt()-1;
			int t = io.getInt()-1;
			if (start[k][cur[k]] != 0) {
				total[k][cur[k]] += s-start[k][cur[k]];
				start[k][cur[k]] = 0;
			}
			if (t == -1 || t >= n) continue;
			cur[k] = t;
			start[k][t] = s;
			if (first[k][t] == 0) {
				first[k][t] = s;
				pref[k][pos[k]++] = t;
			}
		}
		for (int k = 0; k < n; k++) {
			for (int t = 0; t < n; t++) {
				if (first[k][t] == 0) {
					pref[k][pos[k]++] = t;
				}
				if (start[k][t] != 0) {
					total[k][t] += b-start[k][t];
				}
			}
		}
		int[] toy = new int[n];
		int[] who = new int[n];
		for (int i = 0; i < n; i++) {
			who[i] = -1;
			pos[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			int x = i;
			while (x != -1) {
				int p = pref[x][pos[x]];
				if (who[p] == -1 || total[x][p] < total[who[p]][p]) {
					int old = who[p];
					who[p] = x;
					toy[x] = p;
					x = old;
				} else {
					pos[x]++;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			io.print((toy[i]+1)+" ");
		}
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
