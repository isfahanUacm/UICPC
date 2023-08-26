/*
 * @EXPECTED_RESULTS@: CORRECT
 */
using System;

public class jeroen
{
	public static void Main(string[] args)
	{
		System.Threading.Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;
		int tests = int.Parse(Console.ReadLine());
		while(tests-- > 0)
		{
			int N = int.Parse(Console.ReadLine());
			int[] S = new int[N];
			int[] P = new int[N];
			int sum = 0;
			for(int i = 0; i < N; i++)
			{
				string[] p = Console.ReadLine().Split();
				S[i] = int.Parse(p[0]);
				P[i] = int.Parse(p[1]);
				sum += S[i];
			}
			if(sum != 150) throw new Exception("Sum != 150");
			double[] dp = new double[151];
			dp[0] = 1;
			for(int i = 0; i < N; i++)
				for(int j = 150 - S[i]; j >= 0; j--)
					dp[j+S[i]] = Math.Max(dp[j+S[i]], dp[j] * P[i] / 100d);
			double ans = 0;
			for(int i = 76; i <= 150; i++)
				ans = Math.Max(ans, dp[i]);
			Console.WriteLine(ans * 100.0);
		}
	}
}
