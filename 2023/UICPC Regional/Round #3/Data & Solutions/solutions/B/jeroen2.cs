/*
 * @EXPECTED_RESULTS@: CORRECT
 */
using System;
using System.Collections.Generic;

public class jeroen2
{
	public static void Main(string[] args)
	{
		// Precompute all possible moves (in 6 * 4 grid)
		List<int> lmoves = new List<int>();
		for(int x1 = 0; x1 < 6; x1++)
			for(int y1 = 0; y1 < 4; y1++)
				for(int x2 = x1; x2 < 6; x2++)
					for(int y2 = y1; y2 < 4; y2++)
					{
						if(x1 != x2 && y1 != y2) continue;
						int mask = 0;
						for(int x = x1; x <= x2; x++)
							for(int y = y1; y <= y2; y++)
								mask |= 1<<(x+6*y);
						lmoves.Add(mask);
					}
		int[] moves = lmoves.ToArray();

		// Precompute all winning states
		bool[] winning = new bool[1<<24];
		for(int i = (1<<24)-1; i >= 0; i--)
		{
			winning[i] = false;
			foreach(int m in moves)
			{
				if((i & m) != m && !winning[i|m])
				{
					winning[i] = true;
					break;
				}
			}
		}

		// Start testcases
		int tests = int.Parse(Console.ReadLine());
		while(tests-- > 0)
		{
			// Cross out bottom line, leaves us with 6*4=24 white squares
			Console.WriteLine("5 1 5 6");

			int state = 0;
			while(state < (1<<24)-1)
			{
				// Read jury move
				string[] p = Console.ReadLine().Split();
				if(p[0] != "MOVE") throw new Exception("Huh!?");
				int y1 = int.Parse(p[1])-1;
				int x1 = int.Parse(p[2])-1;
				int y2 = int.Parse(p[3])-1;
				int x2 = int.Parse(p[4])-1;
				for(int x = x1; x <= x2; x++)
					for(int y = y1; y <= y2 && y < 4; y++)
						state |= (1<<(x+6*y));

				if(state == 0) throw new Exception("I lost!?");

				// Do my move
				int move = -1;
				foreach(int m in moves)
				{
					if((m & state) != m && !winning[m | state])
					{
						move = m;
						break;
					}
				}
				if(move == -1) throw new Exception("I don't know what to do!");

				// Format move for output
				x1 = 10;
				y1 = 10;
				x2 = 0;
				y2 = 0;
				for(int x = 0; x < 6; x++)
				{
					for(int y = 0; y < 4; y++)
					{
						if((move & (1<<(x+6*y))) == 0) continue;
						x1 = Math.Min(x1, x);
						y1 = Math.Min(y1, y);
						x2 = Math.Max(x2, x);
						y2 = Math.Max(y2, y);
					}
				}
				Console.WriteLine("{0} {1} {2} {3}", y1+1, x1+1, y2+1, x2+1);
				state |= move;
			}
			if(Console.ReadLine() != "GAME") throw new Exception("But I won!");
		}
	}
}
