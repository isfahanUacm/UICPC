/*
 * @EXPECTED_RESULTS@: CORRECT
 */
using System;
using System.Text;

public class jeroen
{
	public static void Main(string[] args)
	{
		int tests = int.Parse(Console.ReadLine());
		while (tests-- > 0)
		{
			string p = Console.ReadLine();
			int n = int.Parse(Console.ReadLine());
			string lst = Console.ReadLine();
			string[] sx = lst.Substring(1, lst.Length - 2).Split(",".ToCharArray());
			int[] x = new int[n];
			for (int i = 0; i < n; i++) x[i] = int.Parse(sx[i]);
			bool rev = false;
			int start = 0;
			int end = n;
			for (int i = 0; i < p.Length; i++)
			{
				if (p[i] == 'R') rev ^= true;
				else if (rev) end--;
				else start++;
			}
			if (start > end) Console.WriteLine("error");
			else
			{
				bool fst = true;
				Console.Write('[');
				for (int i = rev ? end - 1 : start; start <= i && i < end; i += rev ? -1 : 1)
				{
					if (!fst) Console.Write(',');
					fst = false;
					Console.Write(x[i]);
				}
				Console.WriteLine(']');
			}
		}
	}
}