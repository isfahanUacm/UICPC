/* Sample solution to Aspen Avenue (version with all trees on one side) 
 * by Mikael Goldmann
 */

import java.util.*;
public class avenue_mg{
    public static void main(String[] s) {
	Scanner in = new Scanner(System.in);
	int n = in.nextInt()/2; // n positions on each side
	double L = in.nextInt();
	double W = in.nextInt();
	double dx = ((double) L)/(n-1); // distance between trees on one side
	double[] pos = new double[2*n];
	for (int i = 0; i < 2*n; ++i)
	    pos[i] = in.nextInt();
	Arrays.sort(pos);
	
	/* cost[i][j] = optimal cast when using first i+j trees
	 * for first i positions on same side and first j positions
	 * on other side.
	 */
	double[][] cost = new double[n+1][n+1];
	for (int i=1; i <= n; ++i) {
	    cost[i][0] = cost[i-1][0] + dist(pos[i-1], i, dx, W, true);
	    cost[0][i] = cost[0][i-1] + dist(pos[i-1], i, dx, W, false);
	}
	for (int i=1; i <= n; ++i) {
	    for (int j=1; j <= n; ++j)
		cost[i][j] =
		    Math.min(cost[i-1][j] + dist(pos[i+j-1], i, dx, W, true),
			     cost[i][j-1] + dist(pos[i+j-1], j, dx, W, false));
		;
	}
	System.out.println(cost[n][n]);
    }

    static double dist(double p, int i, double step, double W, boolean samside) {
	/* Distance from tree at (p,0) to i:th position 
	 * on same or other side.
	 */
	double x1 = p;
	double x2 = (i-1)*step;
	double dx = x2 - x1;
	double dy = samside ? 0 : W;
	return Math.sqrt(dx*dx + dy*dy);
    }
}
