import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class dinner_jm {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
				
		int n = in.nextInt(), m = in.nextInt();
		int[][] met = new int[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				met[i][j] = 2008;
		for (int i = 0; i < m; i++)
		{			
			int a = in.nextInt() - 1, b = in.nextInt() - 1, y = in.nextInt();
			met[a][b] = met[b][a] = y;
		}

		int found = 0;
		for (int y = 1928; y <= 2008 && found == 0; y++)
		{
			boolean[] notA = new boolean[n], notB = new boolean[n];
			for (int i = 0; i < n; i++)
			{
				int degree = 0;
				for (int j = 0; j < n; j++)
				{
					if (i != j && met[i][j] < y)
						degree++;
				}
				if (degree < n/2 - 1)
					notA[i] = true;
				else if (degree > n/2)
					notB[i] = true;
				else if (degree == n/2 - 1)
				{
					for (int j = 0; j < n; j++)
						if (i != j && met[i][j] < y)
							notB[j] = true;
				}
				else
				{
					for (int j = 0; j < n; j++)
						if (i != j && met[i][j] >= y)
							notA[j] = true;
				}
			}
			boolean[] inA = new boolean[n];
			if (Test(notA, notB, met, inA, y, 0, 0))
				found = y;
		}
		if (found > 0)
			System.out.println(found);
		else
			System.out.println("Impossible");
	}
	
	private static boolean Test(boolean[] notA, boolean[] notB, int[][] met, boolean[] inA, int year, int current, int aCount)
	{
		int n = notA.length;
		if (aCount > n/2 || current-aCount > n/2)
			return false;

		if (current < n)
		{
			if (!notA[current])
			{
				inA[current] = true;
				if (Test(notA, notB, met, inA, year, current + 1, aCount+1))
					return true;
			}
			if (!notB[current])
			{
				inA[current] = false;
				if (Test(notA, notB, met, inA, year, current + 1, aCount))
					return true;
			}
			return false;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (inA[i] && inA[j] && met[i][j] >= year)
					return false;
				if (!inA[i] && !inA[j] && met[i][j] < year)
					return false;
			}
		}
		return true;
	}
}
