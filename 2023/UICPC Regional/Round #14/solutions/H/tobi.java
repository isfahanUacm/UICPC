// @EXPECTED_RESULTS@: CORRECT
import java.io.*;
import java.util.*;

public class tobi {
	public static final int[][] grid = new int[305][305];
	public static final int dx[] = new int[]{-1, 0, 0, +1};
	public static final int dy[] = new int[]{0, +1, -1, 0};
	public static final int MAXN = 2*(305 * 305) + 50;
	public static int N, S, T, r, c, castleR, castleC, flow;
	public static final int previous[] = new int[MAXN];
	public static ArrayList<Integer> adj[] = new ArrayList[MAXN];
	public static HashMap<Integer,Integer> residual[] = new HashMap[MAXN];
	public static final int oo = (1 << 29);

	public static void add_edge(int a, int b, int c) {
		adj[a].add(b);
		adj[b].add(a);
		if (residual[a] == null) {
			residual[a] = new HashMap<>();
		}
		if (residual[b] == null) {
			residual[b] = new HashMap<>();
		}
		if (residual[a].get(b) == null) {
			residual[a].put(b,0);
		}
		if (residual[b].get(a) == null) {
			residual[b].put(a,0);
		}
		residual[a].put(b,residual[a].get(b) + c);
	}
 
	public static boolean find_path() {
		for (int i = 0; i < MAXN; i++) previous[i] = -1;
		previous[S] = S;
		ArrayDeque<Integer> q = new ArrayDeque<>();
		q.add(S);
		while (!q.isEmpty()) {
			int n = q.poll();
			for (int i = 0; i < adj[n].size(); i++) {
				int m = adj[n].get(i);
				if (previous[m] == -1 && residual[n].get(m) > 0) {
					previous[m] = n;
					q.add(m);
					if (m == T) return true;
				}
			}
		}
		return false;
	}

	public static int augment(int n, int cap) {
		if (previous[n] == n) return cap;
		cap = augment(previous[n], Math.min(cap, residual[previous[n]].get(n)));
		residual[previous[n]].put(n, residual[previous[n]].get(n) - cap);
		residual[n].put(previous[n], residual[n].get(previous[n]) + cap);
		return cap;
	}

	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		r = sc.nextInt();
		c = sc.nextInt();


		for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) grid[i][j] = sc.nextInt();
		castleR = sc.nextInt();
		castleC = sc.nextInt();
		S = 2*r*c; T = S + 1; N = T + 1;
		residual = new HashMap[MAXN];
		for (int i = 0; i <= N; i++) {
			adj[i] = new ArrayList<>();
		}
		for(int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
			for (int k = 0; k < 4; k++) {
				if (i+dy[k] < 0 || j+dx[k] < 0 || i+dy[k] >= r || j+dx[k] >= c) continue;
				add_edge(r*c+i*c + j, (i+dy[k])*c + j+dx[k], oo);
			}
			add_edge(i*c + j, r*c + i*c + j, grid[i][j]);
		}
		add_edge(S, castleR*c + castleC, oo);
		for (int i = 0; i < r; i++) {
			add_edge(r*c+i*c + 0, T, oo);
			add_edge(r*c+i*c + c-1, T, oo);
		}
		for (int i = 0; i < c; i++) {
			add_edge(r*c+0*c + i, T, oo);
			add_edge(r*c+(r-1)*c + i, T, oo);
		}
		while (find_path()) flow += augment(T, oo);
		System.out.println(flow);
	}
}
