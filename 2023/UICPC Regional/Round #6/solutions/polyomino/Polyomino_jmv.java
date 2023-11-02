public class Polyomino_jmv {
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		int h = in.nextInt(), w = in.nextInt(), c = 0; in.nextLine();
		char[][] G = new char[h][w];
		for (int i = 0; i < h; i++) {
			String l = in.nextLine();
			for (int j = 0; j < w; j++) {
				G[i][j] = l.charAt(j);
				if (G[i][j] == 'X') c++;
			}
		}
		int[][] ps = new int[5][2];
		for (int i = 0; i < G.length; i++) {
			for (int j = 0; j < G[0].length; j++) {
				if (G[i][j] == 'X') {
					ps[0][0] = i;
					ps[0][1] = j;
					i = G.length;
					break;
				}
			}
		}
		for (int p = 5; p >= 2; p--) {
			if (c % p != 0) continue;
			if (oRec(G, ps, 1, p, c / p)) {
				for (int i = 0; i < h; i++) {
					for (int j = 0; j < w; j++) {
						System.out.print(G[i][j]);
					}
					System.out.println();
				}
				return;
			}
		}
		System.out.println("No solution");
	}

	static boolean oRec(char[][] G, int[][] ps, int k, int p, int r) {
		if (k == p) {
			boolean ok = iRec(G, ps, p, new int[]{r});
			if (!ok) {
				for (int i = 0; i < G.length; i++) {
					for (int j = 0; j < G[0].length; j++) {
						if (G[i][j] != '.') {
							G[i][j] = 'X';
						}
					}
				}
			}
			return ok;
		}
		for (int i = ps[k - 1][0]; i < G.length; i++) {
			ps[k][0] = i;
			for (int j = 0 ; j < G[0].length; j++) {	
				if (((k > 0 && i == ps[k - 1][0] && j <= ps[k - 1][1])) || G[i][j] != 'X') continue;
				ps[k][1] = j;
				if (oRec(G, ps, k + 1, p, r)) {
					return true;
				}
			}
		}
		return false;
	}

	static int[][] dxy = {{1, 0}, {-1, 1}, {-1, -1}, {1, -1}, {0, 1}};

	static boolean iRec(char[][] G, int[][] ps, int p, int[] r) {
		if (r[0] == 0) return true;
		for (int k = 0; k < p; k++) {
			if (ps[k][0] < 0 || ps[k][0] >= G.length || ps[k][1] < 0 || ps[k][1] >= G[0].length || G[ps[k][0]][ps[k][1]] != 'X') return false;
		}
		for (int k = 0; k < p; k++) {
			G[ps[k][0]][ps[k][1]] = (char) (k + '1');
		}

		r[0]--;
		for (int i = 0; i < 5; i++) {
			for (int k = 0; k < p; k++) {
				ps[k][0] += dxy[i][0];
				ps[k][1] += dxy[i][1];
			}
			if (iRec(G, ps, p, r)) return true;
		}
		return false;
	}
}















