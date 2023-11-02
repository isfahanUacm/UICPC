public class Statisticians_jmv {
	static final int L = 10000000;
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		int h = in.nextInt(), w = in.nextInt(), a = in.nextInt(), b = in.nextInt();
		int[][] D = new int[h][w], C = new int[h + 1][w + 1];
		int[] ls = new int[L + 1];
		int max = 0, min = Integer.MAX_VALUE, c = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				D[i][j] = in.nextInt();
				max = Math.max(max, D[i][j]);
				min = Math.min(min, D[i][j]);
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				C[i + 1][j + 1] = D[i][j] + C[i + 1][j] + C[i][j + 1] - C[i][j];
				for (int k = 0; k <= i; k++) {
					for (int l = 0; l <= j; l++) {
						if ((i - k + 1) * (j - l + 1) >= a && (i - k + 1) * (j - l + 1) <= b) {
							double d = C[i + 1][j + 1] - C[k][j + 1] - C[i + 1][l] + C[k][l];
							d /= ((i - k + 1) * (j - l + 1));
							ls[(int) ((d - min) / (max - min) * L)]++;
							c++;
						}
					}
				}
			}
		}
		for (int i = 0, t = 0; i < L + 1; i++) {
			t += ls[i];
			if (t >= (c + 1) / 2) {
				if (c % 2 == 1) {
					System.out.println(((double) i + 0.5) / L * (max - min) + min);
				}
				else {
					if (t == c / 2) {
						int j = i + 1;
						while (ls[j] == 0) j++;
						System.out.println(((double) i + j + 1.0) / L / 2 * (max - min) + min);
					}
					else {
						System.out.println(((double) i + 0.5) / L * (max - min) + min);
					}
				}	
				break;
			}
		}
	}
}
