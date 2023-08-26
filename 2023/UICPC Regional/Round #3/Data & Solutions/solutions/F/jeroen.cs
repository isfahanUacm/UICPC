/*
 * @EXPECTED_RESULTS@: CORRECT
 */
using System;
using System.Collections.Generic;

public class jeroen
{
	public const char WALL = '#';
	public const char ME = '@';
	public const char FIRE = '*';
	private static int[] dr = { 0, -1, 0, 1 };
	private static int[] dc = { -1, 0, 1, 0 };

	public static void Main(string[] args)
	{
		int t = int.Parse(Console.ReadLine());
		while(t-- > 0)
		{
			string[] p = Console.ReadLine().Split();
			int C = int.Parse(p[0]);
			int R = int.Parse(p[1]);
			string[] grid = new string[R];
			for(int i = 0; i < R; i++)
				grid[i] = Console.ReadLine();

			Queue<State> Q = new Queue<State>();

			// First add all fire
			for(int i = 0; i < R; i++)
				for(int j = 0; j < C; j++)
					if(grid[i][j] == FIRE)
						Q.Enqueue(new State(0, i, j, false));

			// Then add me
			bool meFound = false;
			for (int i = 0; i < R; i++)
			{
				for (int j = 0; j < C; j++)
				{
					if (grid[i][j] == ME)
					{
						if (meFound) throw new Exception("Multiple " + ME + " characters.");
						meFound = true;
						Q.Enqueue(new State(0, i, j, true));
					}
				}
			}
			if (!meFound) throw new Exception("No " + ME + " characters.");
			

			// BFS
			bool[,,] done = new bool[R,C,2];
			bool escaped = false;
			while(Q.Count > 0)
			{
				State top = Q.Dequeue();
				if(top.r < 0 || top.r >= R || top.c < 0 || top.c >= C)
				{
					if(top.me)
					{
						Console.WriteLine(top.steps);
						escaped = true;
						break;
					} else continue;
				}
				if(done[top.r,top.c,top.me?1:0]) continue;
				done[top.r,top.c,top.me?1:0] = true;
				if(grid[top.r][top.c] == WALL) continue;
				if(top.me && done[top.r,top.c,0]) continue; // burn!
				for(int i = 0; i < 4; i++)
					Q.Enqueue(new State(top.steps+1,top.r+dr[i],top.c+dc[i],top.me));
			}
			if(!escaped) Console.WriteLine("IMPOSSIBLE");
		}
	}

	class State
	{
		public int steps, r, c;
		public bool me;

		public State(int steps, int r, int c, bool me)
		{
			this.steps = steps;
			this.r = r;
			this.c = c;
			this.me = me;
		}
	}
}