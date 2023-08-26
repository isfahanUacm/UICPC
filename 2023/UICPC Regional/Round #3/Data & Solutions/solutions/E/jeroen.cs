/*
 * @EXPECTED_RESULTS@: CORRECT
 */
using System;

public class jeroen
{
	public static void Main(string[] args)
	{
		int tests = int.Parse(Console.ReadLine());
		while(tests-- > 0)
		{
			string line = Console.ReadLine();
			int n = 1;
			while(n * n != line.Length) n++;
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					Console.Write(line[n-i-1+j*n]);
			Console.WriteLine();
		}
	}
}
