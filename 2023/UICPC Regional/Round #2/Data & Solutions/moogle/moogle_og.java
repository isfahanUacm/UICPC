import java.util.*;

public class moogle_og {

	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		for (int t=in.nextInt(); t>0; --t) {
			int h = in.nextInt();
			int c = in.nextInt();
			int[] a = new int[h];
			for (int i=0; i<h; ++i) {
				a[i] = in.nextInt();
			}
			System.out.printf(Locale.UK, "%.4f\n", solve(h, c, a));
		}
	}

	static double solve(int h, int c, int[] a) {
		double[][] cost = new double[h][h];
		for (int i=0; i<h; ++i) {
			for (int j=i+2; j<h; ++j) {
				for (int k=i+1; k<j; ++k) {
					cost[i][j] += Math.abs(a[k]-a[i]-(a[j]-a[i])*(double)(k-i)/(j-i));
				}
			}
		}
		double[] dp = new double[h];
		for (int i=0; i<h; ++i) {
			dp[i] = cost[0][i];
		}
		for (; c>2; --c) {
			double[] ny = new double[h];
			for (int i=0; i<h; ++i) {
				ny[i] = dp[i];
				for (int j=1; j<i; ++j) {
					double alt = dp[j] + cost[j][i];
					if (alt < ny[i]) ny[i] = alt;
				}
			}
			dp = ny;
		}
		return dp[h-1]/h;
	}

}
