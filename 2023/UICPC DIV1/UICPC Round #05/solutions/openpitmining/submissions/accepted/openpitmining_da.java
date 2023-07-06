import java.util.Scanner;

public class openpitmining_da {

	private void work() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		init(n + 2);

		int totalValue = 0;
		for (int i = 0; i < n; i++) {
			int v = sc.nextInt();
			int c = sc.nextInt();
			totalValue += v;
			addEdge(n, i, v);
			addEdge(i, n + 1, c);

			int m = sc.nextInt();
			while (m-- > 0) {
				int j = sc.nextInt() - 1;
				addEdge(j, i, oo);
			}
		}
		sc.close();

		System.out.println(totalValue - fordFulkerson(n + 2, n, n + 1));
	}

	public static void main(String[] args) {
		new openpitmining_da().work();
	}

	private final static int oo = Integer.MAX_VALUE;
	private int[][] cap, fnet;
	private int[] q, prev;
	private int qs, qe;

	private void init(int n) {
		cap = new int[n][n];
		fnet = new int[n][n];
		q = new int[n];
		prev = new int[n];
	}

	private int fordFulkerson(int n, int s, int t) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				fnet[i][j] = 0;
			}
		}
		int flow = 0;
		while (true) {
			// find an augmenting path
			for (int i = 0; i < n; i++) {
				prev[i] = -1;
			}
			qs = qe = 0;
			prev[s] = -2;
			q[qe++] = s;

			while (qe > qs && prev[t] == -1) {
				int u = q[qs++];
				int v = 0;
				while (v < n) {
					if (prev[v] == -1 && fnet[u][v] - fnet[v][u] < cap[u][v]) {
						prev[v] = u;
						q[qe++] = v;
					}
					v++;
				}
			}
			// see if we are done
			if (prev[t] == -1) {
				break;
			}
			// get the bottleneck capacity
			int bot = oo;
			int v = t;
			int u = prev[v];
			while (u >= 0) {
				bot = Math.min(bot, cap[u][v] - fnet[u][v] + fnet[v][u]);
				v = u;
				u = prev[v];
			}
			// update the flow network
			v = t;
			u = prev[v];
			while (u >= 0) {
				fnet[u][v] += bot;
				v = u;
				u = prev[v];
			}
			flow += bot;
		}
		return flow;
	}

	private void addEdge(int u, int v, int cp) {
		cap[u][v] += cp;
	}
}
