// This is a java copy of harry.cpp. That solution has comments.

import java.util.Scanner;

public class harry {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] boats = new int[n];
		for(int i = 0; i < n; ++i)
			boats[i] = sc.nextInt();
		int[][] times = new int[n][n];
		
		for(int i = 0; i < n; ++i)
			for(int j = i; j < n; ++j)
				times[i][j] = 120 + Math.max(20*(j - i + 1), (boats[j] + 20) - (boats[i] + 1800));
		
		int[] dp = new int[n];
		for(int i = 0; i < n; ++i)
		{
			int low = times[0][i]; 
			for(int k = 1; k <= i; ++k)
				low = Math.min(low, times[k][i] + dp[k - 1]);
			dp[i] = low; 
		}
		
		System.out.println(dp[n - 1]);
	}

}
