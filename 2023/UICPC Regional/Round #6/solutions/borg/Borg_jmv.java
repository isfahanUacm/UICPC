public class Borg_jmv {
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		int nodes = in.nextInt(); in.nextLine();
		int length = in.nextInt(); in.nextLine();
		int[] cycle = new int[length];
		for (int i = 0; i < length; i++)
			cycle[i] = in.nextInt();
		if (in.nextLine().length() > 1) System.out.println("Wrong input format! Walk.");
		int edges = 0;
		int[][] graph = new int[nodes][];
		for (int i = 0; i < nodes; i++) {
			String[] line = in.nextLine().split(" ");
			graph[i] = new int[Integer.parseInt(line[0])];
			if (graph[i].length + 1 != line.length) System.out.println("Wrong input format! Graph.");
			for (int j = 0; j + 1 < line.length; j++)
				graph[i][j] = Integer.parseInt(line[j + 1]);
			edges += graph[i].length;
		}
		if (in.hasNextLine()) System.out.println("Wrong input format! Trailing.");
		double success = calcSuccess(nodes, edges, length, cycle, graph);
		System.out.println(success);
	}

	public static double calcSuccess(int nodes, int edges, int length, int[] cycle, int[][] graph) {
		double[] probabilities = new double[nodes];
		double base = 1.0 / edges;
		for (int i = 0; i < nodes; i++)
			probabilities[i] = graph[i].length * base;
		double success = 1;
		for (int i = 0; i + 1 < length; i++) {
			success -= probabilities[cycle[i]];
			probabilities[cycle[i]] = 0;
			success -= probabilities[cycle[i + 1]] / graph[cycle[i + 1]].length;
			double[] newProbabilities = new double[nodes];
			for (int j = 0; j < nodes; j++) 
				for (int k = 0; k < graph[j].length; k++) 
					newProbabilities[graph[j][k]] += probabilities[j] / graph[j].length;
			newProbabilities[cycle[i]] -= probabilities[cycle[i + 1]] / graph[cycle[i + 1]].length;
			probabilities = newProbabilities;
		}
		success -= probabilities[cycle[length - 1]];
		return success;
	}
}