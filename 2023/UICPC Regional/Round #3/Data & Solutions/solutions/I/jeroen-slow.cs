/*
 * @EXPECTED_RESULTS@: TIMELIMIT
 */
using System;
using System.Text;
using System.Collections.Generic;

public class jeroen_too_slow
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

			List<int> l = new List<int>(x);
			bool ok = true;
			for (int i = 0; ok && i < p.Length; i++)
			{
				if (p[i] == 'D')
				{
					if (l.Count == 0) ok = false;
					else l.RemoveAt(0);
				}
				else
				{
					if (i + 1 < p.Length && p[i + 1] == 'R') i++;
					else l.Reverse();
				}
			}

			if (!ok) Console.WriteLine("error");
			else
			{
				StringBuilder sb = new StringBuilder();
				bool fst = true;
				sb.Append('[');
				foreach(int i in l)
				{
					if (!fst) sb.Append(',');
					fst = false;
					sb.Append(i);
				}
				sb.Append(']');
				Console.WriteLine(sb.ToString());
			}
		}
	}
}