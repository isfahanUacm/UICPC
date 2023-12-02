// @EXPECTED_RESULTS@: CORRECT

import java.util.Scanner;
public class jakob {
	public static void matmult(double[][] a, double[][] b, double[][] res) {
		for(int i = 0; i < a.length; i++) {
			for(int j = 0; j < a.length; j++) {
				res[i][j] = 0;
				for(int k = 0; k < a.length; k++) {
					res[i][j] += a[i][k] * b[k][j];
				}
			}
		}
	}

	public static class foo implements Comparable<foo> {
		int idx;
		double val;
		public int compareTo(foo f) {
			int c1 = Double.valueOf(val).compareTo(f.val);
			if(c1 != 0) return c1;
			return Integer.valueOf(idx).compareTo(f.idx); 
		}
	}

	public static void main(String args[] ) {
		Scanner s = new Scanner(System.in);
		s.useLocale(java.util.Locale.US);
		int ntc = s.nextInt();
		for(int tc = 0; tc < ntc; tc++) {
			int N = s.nextInt();
			int l = s.nextInt();
			int t = s.nextInt();
			double[][] mat = new double[N][N];
			double[][] tmp = new double[N][N];
			double[][] tmp2;
			double[][] acc = new double[N][N];
			double[] init = new double[N];
			double[] res = new double[N];
			foo[] res2 = new foo[N];
			boolean[][] conn = new boolean[N][N];
			for(int i = 0; i < N; i++) {
				double st = s.nextDouble();
				init[i] = st;
				mat[i][i] = 1;
				acc[i][i] = 1;
				conn[i][i] = true;
			}
			for(int i = 0; i < l; i++) {
				int source = s.nextInt();
				int dest = s.nextInt();
				double perc = s.nextDouble();
				conn[source][dest] = conn[dest][source] = true;
				mat[dest][source] = perc;
				mat[source][source] -= perc;
			}
			// wanted: mat ^ t * init 
			while(t != 0) {
				if(t % 2 == 1) {
					matmult(mat, acc, tmp);
					tmp2 = acc;
					acc = tmp;
					tmp = tmp2;
				}
				matmult(mat, mat, tmp);
				tmp2 = mat;
				mat = tmp;
				tmp = tmp2;
				t /= 2;
			}
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					res[i] += acc[i][j] * init[j];
				}
			}
			for(int i = 0; i < N; i++) {
				res2[i] = new foo();
				res2[i].idx = i;
				double tmpd = 0;
				for(int j = 0; j < N; j++) {
					if(conn[i][j]) {
						tmpd += (res[j]);
					}
				}
				res2[i].val = tmpd;
			}
			java.util.Arrays.sort(res2);
			System.out.print(res2[0].val);
			System.out.println();
		}
	}
}
