/* Sample solution to NCPC 2008: Dinner
 * by Mikael Goldmann
 *
 * Modelling. For a given year, we can view the relations as
 * a complete graph with red (met before year)  and blue (met after year) edges.
 * We need to color the verices red or blue so that both the red and blue vertices
 * induce complete red and blue subgraphs, respectively.
 *
 * The key observation is that if we color u red, then all vertices v
 * such that (u,v) is blue, must be blue. Thus, fixing the color of a single vertex
 * will immediatly propagate to a coloring of many, or even all, vertices. This allows
 * us to try to color the graph using backtracking.
 *
 * If at any point we find a blue edge between two red vertices (or vice versa), this
 * coloring is illegal. If all vertices have been legally colored, then just count the
 * number of each color to make sure the coloring is balanced enough.
 */

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

import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.OutputStream;

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



public class dinner_mg {

    static final int WHITE = 0;
    static final int RED   = 1;
    static final int BLUE  = 2;

    static Kattio io = new Kattio(System.in);

    int[][] adj;
    int[] col;

    public static void main(String[] s) {
	new dinner_mg();
    }

    boolean solve(int u, int t, int c) {
	col[u] = c;
	//	System.err.println("Setting " + u + " to " + c);
	boolean ok = true;
	int N = col.length;
	int next = -1;
	for (int v = 0; ok && v < N; ++v) {
	    if (v == u) continue;
	    if(col[v] == WHITE)
		if (next == -1 || col(u, v, t) != col[u])
		    next = v;
	    if (col[u] == col[v] && col[u] != col(u,v,t))
		ok = false;
	}
	if (ok) {
	    if (next == -1) {
		int nblue = 0;
		for (int i = 0; i < N; ++i)
		    if (col[i] == BLUE) nblue += 3;
		ok = nblue >= N && nblue <= 2*N;
	    }
	    else
		if ( col(u, next, t) == col[u] )
		    ok = solve(next, t, BLUE) || solve(next, t, RED);
		else
		    ok = solve(next, t, col(u, next, t));
	}
	col[u] = WHITE;
	return ok;
    }


    int col(int x, int y, int t) { return adj[x][y] >= t ? BLUE : RED; }

    dinner_mg() {
	int N = io.getInt();
	int M = io.getInt();
	int MAX = 2009;
	int MIN = MAX;
	adj = new int[N][N];
	for (int i = 0; i < N; ++i)
	    Arrays.fill(adj[i], MAX);
	for (int i = 0; i < M; ++i) {
	    int a = io.getInt()-1;
	    int b = io.getInt()-1;
	    int y = io.getInt();
	    adj[a][b] = adj[b][a] = y;
	    MIN = Math.min(MIN, y);
	}
	col = new int[N];
	Arrays.fill(col, WHITE);
	boolean ok = false;
	int Y = -1;
	for (int t = MIN; !ok && t <= MAX; ++t) {
	    Y = t;
	    ok = solve(0, t, RED) || solve(0, t, BLUE);
	}
	if (ok) io.println(Y);
	else io.println("Impossible");
	io.close();
	
    }
}

