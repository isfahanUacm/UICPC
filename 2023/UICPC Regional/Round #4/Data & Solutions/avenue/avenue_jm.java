import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.*;

public class avenue_jm {	
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
				
		int n = in.nextInt();
		int roadLength = in.nextInt();
		int roadWidth = in.nextInt();
		int trees[] = new int[n];		
		for (int i = 0; i < n; i++)
			trees[i] = in.nextInt();	

		Arrays.sort(trees);

		int intervals = (n/2) - 1;
		
		double[] dp = new double[n/2 + 1];
		for (int i = n - 1; i >= 0; i--)
		{
			double[] old = dp;
			dp = new double[n/2 + 1];
			for (int leftPlaced = 0, rightPlaced = i - leftPlaced; leftPlaced <= i; leftPlaced++, rightPlaced--)
			{
				if (leftPlaced > n/2 || rightPlaced > n/2)
					continue;
				double best = Double.MAX_VALUE;

				if (leftPlaced + 1 <= n/2)
				{
					double ly = (double) leftPlaced/intervals*roadLength;
					double ldist = Math.abs(trees[i] - ly);
					best = Math.min(best, ldist + old[leftPlaced + 1]);
				}
				if (rightPlaced + 1 <= n/2)
				{
					double ry = (double) rightPlaced/intervals*roadLength;
					double rdist = Math.sqrt(Math.pow(roadWidth, 2) + Math.pow(trees[i] - ry, 2));
					best = Math.min(best, rdist + old[leftPlaced]);
				}

				dp[leftPlaced] = best;
			}
		}

		NumberFormat format = new DecimalFormat("0.000000");
		System.out.println(format.format(dp[0]).replace(",", "."));
	}	
}
