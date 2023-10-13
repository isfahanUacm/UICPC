// @EXPECTED_RESULTS@: CORRECT

import java.util.*;
import java.io.*;

// borrowed from Alex :-)
class pii implements Comparable {
	int first,second;
	public pii(){first = 0; second = 0;}
	public pii(int a, int b){first = a; second = b;}
	public boolean less(pii b){
		if(first < b.first)return true;
		if(first== b.first && second < b.second)return true;
		return false;
	}
	public int compareTo(Object o) {
		if (o == null) {
			return -1;
		}
		if (!(o instanceof pii)) {
			return -1;
		}
		return (less((pii) o) ? -1 : 1);
	}
}


public class tobi {
	public static final int MAX = 10000;
	public static final int MAX_IDOLS = (8+1);

	public static int numNodes, numEdges, numIdols;
	public static ArrayList<ArrayList<Integer>> adjList;
	public static ArrayList<ArrayList<Integer>> costList;
	public static ArrayList<Integer> idols;
	public static ArrayList<Integer> dist;

	public static int distMatrix[][] = new int[MAX_IDOLS][MAX_IDOLS];
	public static int tspMatrix[][] = new int[MAX_IDOLS][MAX_IDOLS];
	public static int opt[][] = new int[(1 << MAX_IDOLS)][MAX_IDOLS];
	public static int pow2[] = new int[MAX_IDOLS + 1];

	public static void dijkstra(int from) {
		dist = new ArrayList<Integer>();
		for (int i = 0; i < numNodes; i++) {
			dist.add(Integer.MAX_VALUE);
		}

		dist.set(from, 0);
		PriorityQueue<pii> pq = new PriorityQueue<pii>();
		pq.add(new pii(dist.get(from), from));
		while (!pq.isEmpty()) {
			pii top = pq.poll();
			int node = top.second;
			ArrayList<Integer> neighbours = adjList.get(node);
			ArrayList<Integer> costs = costList.get(node);
			int i = 0;
			for (Integer next : neighbours) {
				int cost = costs.get(i);
				i++;
				if (dist.get(node) + cost >= dist.get(next)) {
					continue;
				}
				dist.set(next, dist.get(node) + cost);
				pq.add(new pii(dist.get(next), next));
			}
		}
	}

	public static int tsp(int usedNodes) {
		for (int i = 0; i < pow2[usedNodes]; i++) for (int j = 0; j < usedNodes; j++) opt[i][j] = Integer.MAX_VALUE;

		opt[1][0] = 0;
		for (int i = 1; i < pow2[usedNodes]; i++) for (int j = 0; j < usedNodes; j++) {
			if (opt[i][j] == Integer.MAX_VALUE) continue;
			for (int k = 0; k < usedNodes; k++) {
				if (((i >> k) & 1) != 0 || tspMatrix[j][k] == Integer.MAX_VALUE) continue;
				if (opt[i + pow2[k]][k] > opt[i][j] + tspMatrix[j][k]) {
					opt[i + pow2[k]][k] = opt[i][j] + tspMatrix[j][k];
				}
			}
		}

		int optimum = opt[pow2[usedNodes]-1][0];
		for (int i = 1; i < usedNodes; i++) {
			if (opt[pow2[usedNodes]-1][i] == Integer.MAX_VALUE || tspMatrix[i][0] == Integer.MAX_VALUE) continue;
			if (optimum > opt[pow2[usedNodes]-1][i] + tspMatrix[i][0]) {
				optimum = opt[pow2[usedNodes]-1][i] + tspMatrix[i][0];
			}
		}
		return optimum;
	}

	public static void main(String args[]) {
		int from, to, cost, air;
		Scanner sc = new Scanner(System.in);
		sc.nextInt(); // skip number of cases
		while (sc.hasNextInt()) {
			numNodes = sc.nextInt();
			numEdges = sc.nextInt();
			idols = new ArrayList<Integer>();
			adjList = new ArrayList<ArrayList<Integer>>();
			costList = new ArrayList<ArrayList<Integer>>();
			for (int i = 0; i < numNodes; i++) {
				ArrayList<Integer> a = new ArrayList<Integer>();
				adjList.add(a);
				ArrayList<Integer> c = new ArrayList<Integer>();
				costList.add(c);
			}

			for (int i = 0; i < numEdges; i++) {
				from = sc.nextInt();
				to = sc.nextInt();
				cost = sc.nextInt();
				adjList.get(from).add(to);
				costList.get(from).add(cost);
				adjList.get(to).add(from);
				costList.get(to).add(cost);
			}

			idols.add(0);
			numIdols = sc.nextInt();
			for (int i = 0; i < numIdols; i++) {
				from = sc.nextInt();
				idols.add(from);
			}

			for (int i = 0; i < numIdols + 1; i++) {
				dijkstra(idols.get(i));
				for (int j = 0; j < numIdols + 1; j++) {
					distMatrix[i][j] = dist.get(idols.get(j));
				}
			}

			air = sc.nextInt();
			int best = 0;
			pow2[0] = 1;
			for (int i = 1; i < numIdols + 2; i++) pow2[i] = 2 * pow2[i-1];
			for (int i = 1; i < pow2[numIdols + 1]; i++) {
				if ((i & 1) == 0) continue;

				int usedNodes = 0;
				int mapping[] = new int[numIdols + 1];
				for (int j = 0; j < numIdols + 1; j++) {
					if ((i & (1 << j)) != 0) {
						mapping[usedNodes] = j;
						usedNodes++;
					}
				}
				for (int j = 0; j < usedNodes; j++) for (int k = 0; k < usedNodes; k++) {
					tspMatrix[j][k] = distMatrix[mapping[j]][mapping[k]];
				}
				if (best < usedNodes - 1 && tsp(usedNodes) <= air) {
					best = usedNodes - 1;
				}
			}
			System.out.printf("%d\n", best);
		}
	}
}
