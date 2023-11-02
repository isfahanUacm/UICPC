public class Statisticians_jmv_rand_wa {
	static final int L = 10000000;
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		int h = in.nextInt(), w = in.nextInt(), a = in.nextInt(), b = in.nextInt();
		int[][] D = new int[h][w], C = new int[h + 1][w + 1];
		float[] ls = new float[40000000];
		int max = 0, min = Integer.MAX_VALUE, c = 0, e = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				D[i][j] = in.nextInt();
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				C[i + 1][j + 1] = D[i][j] + C[i + 1][j] + C[i][j + 1] - C[i][j];
				for (int k = 0; k <= i; k++) {
					for (int l = 0; l <= j; l++) {
						if ((i - k + 1) * (j - l + 1) >= a && (i - k + 1) * (j - l + 1) <= b) {
							float d = C[i + 1][j + 1] - C[k][j + 1] - C[i + 1][l] + C[k][l];
							d /= ((i - k + 1) * (j - l + 1));
							if (h*w*(b-a) < 100000000 || Math.random() < 0.5) ls[c++] = d;
							e++;
						}
					}
				}
			}
		}
		System.err.println(e + " " + c);
		java.util.Arrays.sort(ls, 0, c);
		System.out.println(ls.length % 2 == 1 ? ls[c/2] : (ls[c/2] + ls[c/2-1])/2);
	}
}
