import java.util.*;

public class Antti {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int m = input.nextInt();
		if (m < n) {
			System.out.println("impossible");
			return;
		}
		int b = input.nextInt()+1;
		int r = input.nextInt();
		int[][] start = new int[n][n];
		int[][] first = new int[n][n];
		int[][] total = new int[n][n];
		int[][] pref = new int[n][n];
		int[] pos = new int[n];
		int[] cur = new int[n];
		while (r-- > 0) {
			int s = input.nextInt()+1;
			int k = input.nextInt()-1;
			int t = input.nextInt()-1;
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
			System.out.print((toy[i]+1)+" ");
		}
		System.out.println();
	}
}
