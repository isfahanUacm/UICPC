/*
 * @EXPECTED_RESULTS@: CORRECT
 */
using System;
using System.Collections.Generic;
using System.Linq;

public class jeroen
{
	public static void Main(string[] args)
	{
		int cases = int.Parse(Console.ReadLine());
		while(cases-- > 0)
		{
			int N = int.Parse(Console.ReadLine());
			string[] grid = new string[N];
			for(int i = 0; i < N; i++)
				grid[i] = Console.ReadLine();
			int notPlayed = 0;
			int[,] ind = new int[N, N];
			for(int i = 0; i < N; i++)
				for(int j = i + 1; j < N; j++)
					if(grid[i][j] == '.')
						ind[i,j] = N + notPlayed++;
			MaxFlow mf = new MaxFlow(notPlayed + N);
			int[] pts = new int[N];
			int[] optpts = new int[N];
			int totalP = 0;
			for(int i = 0; i < N; i++)
			{
				mf.Add(i, mf.Sink, 2 * N);
				for(int j = 0; j < N; j++)
				{
					if(grid[i][j] == '.')
					{
						optpts[i] += 2;
						if(i < j)
						{
							totalP += 2;
							mf.Add(mf.Source, ind[i,j], 2);
							mf.Add(ind[i,j], i, 2);
							mf.Add(ind[i,j], j, 2);
						}
					}
					else if(grid[i][j] == '1')
						pts[i] += 2;
					else if(grid[i][j] == 'd')
						pts[i] += 1;
				}
			}
			List<int> canWin = new List<int>();
			for(int i = 0; i < N; i++)
			{
				bool ok = true;
				for(int j = 0; j < N; j++)
				{
					if(j == i)
					{
						mf.Capacity[j, mf.Sink] = optpts[i];
					}
					else
					{
						mf.Capacity[j, mf.Sink] = pts[i] + optpts[i] - pts[j];
						ok &= mf.Capacity[j, mf.Sink] >= 0; 
					}
				}
				if(ok && mf.NetworkFlow() == totalP)
					canWin.Add(i+1);
			}
			Console.WriteLine(string.Join(" ", canWin.Select(i => i.ToString()).ToArray()));
		}
	}
}


public class MaxFlow
{
	public int Nodes;
	public int Source;
	public int Sink;
	public int[,] Capacity;
	LinkedList<int>[] Neighbours;
	bool[,] NeighbourAdded;

	public MaxFlow(int Nodes)
	{
		this.Nodes = Nodes + 2;
		this.Source = Nodes;
		this.Sink = Nodes + 1;
		Neighbours = new LinkedList<int>[this.Nodes];
		for (int i = 0; i < this.Nodes; i++)
			Neighbours[i] = new LinkedList<int>();
		Capacity = new int[this.Nodes, this.Nodes];
		NeighbourAdded = new bool[this.Nodes, this.Nodes];
	}

	public void Add(int From, int To, int Cap)
	{
		Capacity[From, To] += Cap;
		if (!NeighbourAdded[From, To])
		{
			NeighbourAdded[From, To] = true;
			NeighbourAdded[To, From] = true;
			Neighbours[From].AddLast(To);
			Neighbours[To].AddLast(From);
		}
	}

	public int NetworkFlow()
	{
		int[,] flow = new int[Nodes, Nodes];
		int[] parent = new int[Nodes];
		int[] cap = new int[Nodes];

		int total = 0;
		while (true)
		{
			for (int i = 0; i < Nodes; i++)
				parent[i] = -1;
			parent[this.Source] = -2;
			cap[this.Source] = int.MaxValue;
			Queue<int> Q = new Queue<int>();
			Q.Enqueue(this.Source);
			while (Q.Count > 0 && parent[this.Sink] == -1)
			{
				int act = Q.Dequeue();
				foreach (int next in Neighbours[act])
				{
					if (parent[next] == -1 && Capacity[act, next] >
							flow[act, next])
					{
						parent[next] = act;
						cap[next] = Math.Min(cap[act], Capacity[act, next] -
																 flow[act, next]);
						Q.Enqueue(next);
					}
				}
			}

			if (parent[this.Sink] == -1)
				return total;

			total += cap[this.Sink];
			int j = this.Sink;
			while (j != this.Source)
			{
				flow[parent[j], j] += cap[this.Sink];
				flow[j, parent[j]] -= cap[this.Sink];
				j = parent[j];
			}
		}
	}
}
