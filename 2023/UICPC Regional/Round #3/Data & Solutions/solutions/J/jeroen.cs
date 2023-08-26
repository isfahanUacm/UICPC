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
			int n = int.Parse(Console.ReadLine());
			string[] p = Console.ReadLine().Split();
			int[] a = new int[n];
			for(int i = 0; i < n; i++) a[i] = int.Parse(p[i]);
			long ret = 0;
			for(int i = 1; i < n; i++)
			{
				if(a[i] >= a[i-1]) continue;
				long nm = 1;
				long prev = 1;
				for(int j = 0; a[j] < a[i]; j++)
				{
					if(j == 0 || a[j] != a[j-1])
					{
						// To go one step down in the stack we must move all
						// books above it again so this takes twice as many moves
						prev = nm;
						nm *= 2;
					}
					else
					{
						// If we have a duplicate, we have to move it just above
						// the previous duplicate value, which saves a few moves
						nm += prev;
					}
				}
				ret += nm;

				Array.Sort(a, 0, i + 1);
			}
			Console.WriteLine(ret);
		}
	}
}
