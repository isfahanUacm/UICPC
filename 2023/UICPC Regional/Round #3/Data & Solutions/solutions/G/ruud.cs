/*
 * @EXPECTED_RESULTS@: CORRECT
 */
using System;

namespace MostStableCoalition
{
	class MainClass
	{
		// w = weigth = seats (must be stricly positive integers)
		// v = value  = "stability"
		// knapsack: maximize sum(v_i x_i)
		//           subject to sum(w_i x_i) <= W and x_i in {0,1} 
		// dual:     minimize sum(v_i ~x_i)
		//           subject to sum(w_i ~x_i) > W and x_i in {0,1}
		
		class Item {
			public int w;
			public double v;
		}
		
		
		public static void Main (string[] args)
		{
		System.Threading.Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;
			int testcases = int.Parse(Console.ReadLine());
			
			for (int i = 0; i < testcases; i++) {
				Testcase();
			}
		}
		
		public static void Testcase()
		{
			int nItems = int.Parse(Console.ReadLine());
			Item[] items = new Item[nItems+1];
			
			int    totalSeats = 0;
			double totalLogPr = 0.0;
			
			for (int i = 1; i <= nItems; i++) {
				string[] line = Console.ReadLine().Split();
				items[i] = new Item();
				totalSeats += items[i].w = int.Parse(line[0]);
				totalLogPr += items[i].v = Math.Log(((double)int.Parse(line[1]))/100.0);
			}
			
			int minority = totalSeats / 2 - 1;
			
			double[] m = new double[minority+1];
			
			for (int w = 0; w <= minority; w++) {
				m[w] = 0;
			}
			
			for (int i = 1; i <= nItems; i++) {
				for (int w = minority; w >= 0; w--) {
					if (items[i].w <= w) {
						m[w] = Math.Min(m[w], m[w-items[i].w] + items[i].v);
					}
				}
			}
			
			Console.WriteLine(Math.Exp(totalLogPr - m[minority]) * 100.0);
		}
	}
}
