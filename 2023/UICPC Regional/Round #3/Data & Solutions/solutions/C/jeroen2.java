/*
 * @EXPECTED_RESULTS@: CORRECT
 */
import java.io.*;
import java.util.*;

public class jeroen2
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		while(cases-- > 0)
		{
			int N = sc.nextInt();
			String[] grid = new String[N];
			for(int i = 0; i < N; i++)
				grid[i] = sc.next();
			int notPlayed = 0;
			int[][] ind = new int[N][N];
			for(int i = 0; i < N; i++)
				for(int j = i + 1; j < N; j++)
					if(grid[i].charAt(j) == '.')
						ind[i][j] = N + notPlayed++;
			MaxFlow mf = new MaxFlow(notPlayed + N);
			int[] pts = new int[N];
			int[] optpts = new int[N];
			int totalP = 0;
			for(int i = 0; i < N; i++)
			{
				mf.Add(i, mf.Sink, 2 * N);
				for(int j = 0; j < N; j++)
				{
					if(grid[i].charAt(j) == '.')
					{
						optpts[i] += 2;
						if(i < j)
						{
							totalP += 2;
							mf.Add(mf.Source, ind[i][j], 2);
							mf.Add(ind[i][j], i, 2);
							mf.Add(ind[i][j], j, 2);
						}
					}
					else if(grid[i].charAt(j) == '1')
						pts[i] += 2;
					else if(grid[i].charAt(j) == 'd')
						pts[i] += 1;
				}
			}
			boolean first = true;
			for(int i = 0; i < N; i++)
			{
				boolean ok = true;
				for(int j = 0; j < N; j++)
				{
					if(j == i)
					{
						mf.Capacity[j][mf.Sink] = optpts[i];
					}
					else
					{
						mf.Capacity[j][mf.Sink] = pts[i] + optpts[i] - pts[j];
						ok &= mf.Capacity[j][mf.Sink] >= 0; 
					}
				}
				if(ok && mf.NetworkFlow() == totalP) {
					if(first) first = false;
					else System.out.print(' ');
					System.out.print(i+1);
				}
			}
			System.out.println();
		}
	}
	
	public static class MaxFlow
	{
		public int Nodes;
		public int Source;
		public int Sink;
		public int[][] Capacity;
		LinkedList<Integer>[] Neighbours;
		boolean[][] NeighbourAdded;
	
		public MaxFlow(int Nodes)
		{
			this.Nodes = Nodes + 2;
			this.Source = Nodes;
			this.Sink = Nodes + 1;
			Neighbours = new LinkedList[this.Nodes];
			for (int i = 0; i < this.Nodes; i++)
				Neighbours[i] = new LinkedList<Integer>();
			Capacity = new int[this.Nodes][this.Nodes];
			NeighbourAdded = new boolean[this.Nodes][this.Nodes];
		}
	
		public void Add(int From, int To, int Cap)
		{
			Capacity[From][To] += Cap;
			if (!NeighbourAdded[From][To])
			{
				NeighbourAdded[From][To] = true;
				NeighbourAdded[To][From] = true;
				Neighbours[From].add(To);
				Neighbours[To].add(From);
			}
		}
	
		public int NetworkFlow()
		{
			int[][] flow = new int[Nodes][Nodes];
			int[] parent = new int[Nodes];
			int[] cap = new int[Nodes];
	
			int total = 0;
			while (true)
			{
				for (int i = 0; i < Nodes; i++)
					parent[i] = -1;
				parent[this.Source] = -2;
				cap[this.Source] = Integer.MAX_VALUE;
				Queue<Integer> Q = new LinkedList<Integer>();
				Q.offer(this.Source);
				while (!Q.isEmpty() && parent[this.Sink] == -1)
				{
					int act = Q.poll();
					for (int next : Neighbours[act])
					{
						if (parent[next] == -1 && Capacity[act][next] >
								flow[act][next])
						{
							parent[next] = act;
							cap[next] = Math.min(cap[act], Capacity[act][next] -
																	 flow[act][next]);
							Q.offer(next);
						}
					}
				}
	
				if (parent[this.Sink] == -1)
					return total;
	
				total += cap[this.Sink];
				int j = this.Sink;
				while (j != this.Source)
				{
					flow[parent[j]][j] += cap[this.Sink];
					flow[j][parent[j]] -= cap[this.Sink];
					j = parent[j];
				}
			}
		}
	}
}

