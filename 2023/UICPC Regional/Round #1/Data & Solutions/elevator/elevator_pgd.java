//Author: Pål Grønås Drange
import java.util.Scanner;
import java.util.LinkedList;

// simple BFS solution, keeping min cost to each floor in array memo
// and a linked list as our queue.

public class elevator_pgd {
    public static void main(String ... args) {
	Scanner scanner = new Scanner(System.in);
	// f s g u d
	int f = scanner.nextInt();
	int s = scanner.nextInt();
	int g = scanner.nextInt();
	int u = scanner.nextInt();
	int d = scanner.nextInt();
	
	// if we're there, 0 presses
	if (g == s) {
	    System.out.println(0);
	    System.exit(0);
	}
	
	// if we cannot go the right direction, use stairs
	if ((u == 0 && g > s) || (d == 0 && g < s)) {
	    System.out.println("use the stairs");
	    System.exit(0);
	}
	
	int[] memo = new int[f + 1]; // 1-indexed, ignore m[0]
	memo[s] = 1;
	LinkedList<Integer> bfs = new LinkedList<Integer>();
	bfs.add(s);
	while (!bfs.isEmpty()) {
	    int current = bfs.remove();
	    int cu = current + u;
	    int cd = current - d;
	    if (cu <= f) {
		if (cu == g) {
		    System.out.println(memo[current]);
		    System.exit(0);
		}
		if (memo[cu] == 0) {
		    memo[cu] = memo[current] + 1;
		    bfs.add(cu);
		}
	    }
	    if (cd > 0) {
		if (cd == g) {
		    System.out.println(memo[current]);
		    System.exit(0);
		}
		if (memo[cd] == 0) {
		    memo[cd] = memo[current] + 1;
		    bfs.add(cd);
		}
	    }
	}
	System.out.println("use the stairs");
    }
}
