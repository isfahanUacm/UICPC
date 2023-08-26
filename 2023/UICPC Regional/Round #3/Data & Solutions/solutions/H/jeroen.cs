/*
 * @EXPECTED_RESULTS@: CORRECT
 */
using System;
using System.Collections.Generic;

public class jeroen
{
	public static int[] dx = {0, 1, 0, -1};
	public static int[] dy = {1, 0, -1, 0};

	public static void Main(string[] args)
	{
		int tests = int.Parse(Console.ReadLine());
		while(tests-- > 0)
		{
			string[] p = Console.ReadLine().Split();
			int n = int.Parse(p[0]);
			int w = int.Parse(p[1]);
			int h = int.Parse(p[2]);
			int[,] dists = new int[w,h];
			for(int i = 0; i < w; i++)
				for(int j = 0; j < h; j++)
					dists[i,j] = int.MaxValue;
			Queue<Loc> Q = new Queue<Loc>();
			for(int i = 0; i < n; i++)
			{
				p = Console.ReadLine().Split();
				Q.Enqueue(new Loc(int.Parse(p[0]), int.Parse(p[1]), 0));
			}
			// Find distance for each gridpoint
			while(Q.Count > 0)
			{
				Loc top = Q.Dequeue();
				if(top.x < 0 || top.x >= w || top.y < 0 || top.y >= h) continue;
				if(dists[top.x,top.y] != int.MaxValue) continue;
				dists[top.x,top.y] = top.d;
				for(int i = 0; i < 4; i++)
					Q.Enqueue(new Loc(top.x+dx[i], top.y+dy[i], top.d+1));
			}
			// Find maximum distance for each diagonal
			int[] diag1 = new int[w+h-1];
			for(int i = 0; i < w+h-1; i++)
			{
				int x = i < w ? i : w - 1;
				int y = i < w ? 0 : i - w + 1;
				while(0 <= x && x < w && 0 <= y && y < h)
				{
					diag1[i] = Math.Max(diag1[i], dists[x,y]);
					x--;
					y++;
				}
			}
			int[] diag2 = new int[w+h-1];
			for(int i = 0; i < w+h-1; i++)
			{
				int x = i < h ? 0 : i - h + 1;
				int y = i < h ? h - i - 1 : 0;
				while(0 <= x && x < w && 0 <= y && y < h)
				{
					diag2[i] = Math.Max(diag2[i], dists[x,y]);
					x++;
					y++;
				}
			}
			// Find ans for each pair of diagonals
			int ans = 0;
			for(int i = 0; i < diag1.Length; i++)
				for(int j = i + 1; j < diag1.Length; j++)
					ans = Math.Max(ans, Math.Min(j - i, Math.Min(diag1[i], diag1[j])));
			for(int i = 0; i < diag2.Length; i++)
				for(int j = i + 1; j < diag2.Length; j++)
					ans = Math.Max(ans, Math.Min(j - i, Math.Min(diag2[i], diag2[j])));
			Console.WriteLine(ans);
		}
	}

	public class Loc
	{
		public int x, y, d;

		public Loc(int x, int y, int d)
		{
			this.x = x; this.y = y; this.d = d;
		}
	}
}