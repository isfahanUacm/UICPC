// @EXPECTED_RESULTS@: CORRECT

import java.io.*;
import java.util.*;

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
		pii p = (pii) o;
		if (p.first == first && p.second == second) {
			return 0;
		}
		return (less((pii) o) ? -1 : 1);
	}
}

public class tobi {
	public static final int MAX = 250;
	public static int numAS[] = new int[2];
	public static int numTS[] = new int[2];
	public static int numOp[] = new int[2];

	public static ArrayList<ArrayList<ArrayList<pii>>> adjList;
	public static ArrayList<ArrayList<ArrayList<Integer>>> revList;

	public static boolean productive[][] = new boolean[2][MAX];
	public static boolean traversed[][] = new boolean[MAX][MAX];

	public static void prod(int factory, int node) {
		if (productive[factory][node]) return;
		productive[factory][node] = true;
		for (int i = 0; i < revList.get(factory).get(node).size(); i++) prod(factory, revList.get(factory).get(node).get(i));
	}

	public static boolean same(int left, int right) {
		if (left == numTS[0] - 1 && right != numTS[1] - 1) return false;
		if (left != numTS[0] - 1 && right == numTS[1] - 1) return false;
		if (traversed[left][right]) return true;
		traversed[left][right] = true;

		int leftP = 0; int rightP = 0;
		while (true) {
			while (leftP < adjList.get(0).get(left).size() && !productive[0][adjList.get(0).get(left).get(leftP).second]) leftP++;
			while (rightP < adjList.get(1).get(right).size() && !productive[1][adjList.get(1).get(right).get(rightP).second]) rightP++;
			if (leftP >= adjList.get(0).get(left).size() && rightP < adjList.get(1).get(right).size()) return false;
			if (leftP < adjList.get(0).get(left).size() && rightP >= adjList.get(1).get(right).size()) return false;
			if (leftP >= adjList.get(0).get(left).size() && rightP >= adjList.get(1).get(right).size()) return true;
			if (adjList.get(0).get(left).get(leftP).first != adjList.get(1).get(right).get(rightP).first) return false;
			if (!same(adjList.get(0).get(left).get(leftP).second, adjList.get(1).get(right).get(rightP).second)) return false;
			leftP++; rightP++;
		}
	}
	
	public static void main(String[] args) {
		int numCases, from, to, label;
		Scanner sc = new Scanner(System.in);
		numCases = sc.nextInt();

		while (numCases --> 0) {
			adjList = new ArrayList<ArrayList<ArrayList<pii>>>();
			revList = new ArrayList<ArrayList<ArrayList<Integer>>>();
			for (int i = 0; i < 2; i++) {
				adjList.add(new ArrayList<ArrayList<pii>>());
				revList.add(new ArrayList<ArrayList<Integer>>());
				numAS[i] = sc.nextInt();
				numTS[i] = sc.nextInt();
				numOp[i] = sc.nextInt();
				for (int j = 0; j < numTS[i]; j++) {
					adjList.get(i).add(new ArrayList<pii>());
					revList.get(i).add(new ArrayList<Integer>());
					productive[i][j] = false;
				}
			}
			for (int i = 0; i < numTS[0]; i++) for (int j = 0; j < numTS[1]; j++) traversed[i][j] = false;
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < numAS[i]; j++) {
					from = sc.nextInt();
					to = sc.nextInt();
					label = sc.nextInt();
					pii next = new pii(label,to);
					adjList.get(i).get(from).add(next);
					revList.get(i).get(to).add(from);
				}
				for (int j = 0; j < numTS[i]; j++) {
					Collections.sort(adjList.get(i).get(j));
				}
				prod(i, numTS[i] - 1);
			}
			System.out.printf("%s\n", same(0,0) ? "eligible" : "not eligible");
		}
	}
}
