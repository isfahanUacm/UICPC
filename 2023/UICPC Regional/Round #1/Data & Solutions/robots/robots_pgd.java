//Author: Pål Grønås Drange
import java.util.Scanner;
import java.util.LinkedList;

public class robots_pgd {
    final static int MOD = 2147483647; // 2 147 483 647 = 2^31 - 1
    // -1  means wall
    // -2  means BFS visited
    // -3  means unvisited
    // >=0 means right-down reachable (in k % MOD steps)
    final static int WALL = -1;
    final static int BFS_VISITED = -2;
    final static int UNVISITED = -3;
    
    public static void main(String ... args) {
	Scanner scanner = new Scanner(System.in);
	
	int n = scanner.nextInt();
	if (n == 1) {
	    System.out.println(1);
	    System.exit(0);
	}
	int[][] grid = new int[n][n];
	scanner.nextLine(); // flush line
	for (int i = 0; i < n; i++) {
	    String line = scanner.nextLine();
	    for (int j = 0; j < n; j++) {
		if (line.charAt(j) == '#') {
		    grid[i][j] = WALL;
		} else {
		    grid[i][j] = UNVISITED;
		}		    
	    }
	}
	// bfs
	grid[0][0] = 1; // 1 way to get to 0,0
	solve(grid);
    }
    
    public static void solve(int[][] grid) {
	int n = grid.length;
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
		if (i != 0 || j != 0)
		    grid[i][j] = calc(grid,i,j);
	    }
	}
	
	if (grid[n-1][n-1] >= 0) {
	    System.out.println(grid[n-1][n-1]);
	} else {
	    boolean path = findpath(grid);
	    if (path) {
		System.out.println("THE GAME IS A LIE");
	    } else {
		System.out.println("INCONCEIVABLE");
	    }
	}
    }
    
    public static int calc(int[][] g, int x, int y) {
	if (g[x][y] == WALL) {
	    return WALL;
	}
	
	long sum = 0;
	boolean reached = false;
	if (x > 0 && g[x-1][y] >= 0) {
	    sum = g[x-1][y];
	    reached = true;
	}
	if (y > 0 && g[x][y-1] >= 0) {
	    sum = sum + (long)g[x][y-1];
	    reached = true;
	}
	if (reached) {
	    return (int)(sum % MOD);
	} else {
	    return UNVISITED;
	}
    }
    
    public static boolean findpath(int[][] grid) {
	int n = grid.length;
	LinkedList<Pair> q = new LinkedList<Pair>();
	q.add(new Pair(0,0));
	while (!q.isEmpty()) {
	    Pair p = q.remove();
	    if (p.x == n - 1 && p.x == p.y) {
		return true;
	    }
	    int x = p.x;
	    int y = p.y;
	    for (int a = -1; a <= 1; a++) {
		for (int b = -1; b <= 1; b++) {
		    if ((a == 0 || b == 0) && (a != 0 || b != 0)) {
			if (x + a >= 0 && x + a < n && y + b >= 0 && y + b < n) {
			    if (grid[x + a][y + b] != WALL && grid[x + a][y + b] != BFS_VISITED) {
				grid[x + a][y + b] = BFS_VISITED;
				q.add(new Pair(x+a,y+b));
			    }
			}
		    }
		}   
	    }
	}
	return false;
    }
    
    static class Pair {
	int x; int y;
	public Pair(int x,int y) {
	    this.x = x; this.y = y;
	}
    }
}
