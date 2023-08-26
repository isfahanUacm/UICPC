import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Scanner;

/*
 * Solution to Fire
 * Author: Bas den Heijer
 * 
 * Time: O(w h)
 * Memory: O(w h)
 * 
 * Slow: using Scanner to read, objects in the entire grid, seperate BFS passes,
 * Exception catching for bounds, LinkedList as queue
 * 
 * @EXPECTED_RESULTS@: CORRECT
 * 
 */

class bas {

	private static Scanner sc;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int n = sc.nextInt();
		for (int i=0; i<n; i++)
			doShizzle();
	}
	
	static int[] dx = new int[] {1,0,-1,0};
	static int[] dy = new int[] {0,-1,0,1};
	static int VERYFAR = Integer.MAX_VALUE;

	private static void doShizzle() {
		int w = sc.nextInt();
		int h = sc.nextInt();
		Cell[][] grid = new Cell[w][h];
		sc.nextLine(); // Should be empty
		
		for (int y=0; y<h; y++) {
			String line = sc.nextLine();
			for (int x=0; x<w; x++) {
				grid[x][y] = new Cell(line.charAt(x), x, y);
			}
		}
		
		
		// First determine fireDist everywhere
		LinkedList<Cell> queue = new LinkedList<Cell>();
		for (Cell[] line : grid) for (Cell cell : line)
			if (cell.type == '*') queue.add(cell);
		
		while (!queue.isEmpty()) {
			Cell cell = queue.removeFirst();
			for (int i=0; i<4; i++) {
				Cell neighbour;
				try {
					neighbour = grid[cell.x+dx[i]][cell.y+dy[i]];
				} catch (ArrayIndexOutOfBoundsException e) {continue;} // outside the grid
				
				if (neighbour.isWalkable() && neighbour.fireDist == VERYFAR) {
					neighbour.fireDist = cell.fireDist + 1;
					queue.add(neighbour);
				}
			}
		}
		
		// Now try to escape
		queue.clear();
		for (Cell[] line : grid) for (Cell cell : line)
			if (cell.type == '@') queue.add(cell); // Should happen only once
		
		int escapeTime = VERYFAR;
		BFS: while (!queue.isEmpty()) {
			Cell cell = queue.removeFirst();
			for (int i=0; i<4; i++) {
				Cell neighbour;
				try {
					neighbour = grid[cell.x+dx[i]][cell.y+dy[i]];
				} catch (ArrayIndexOutOfBoundsException e) { // outside the grid
					escapeTime = cell.youDist + 1;
					break BFS;
				}
				
				if (neighbour.isWalkable() && neighbour.youDist == VERYFAR && neighbour.fireDist > cell.youDist + 1) {
					neighbour.youDist = cell.youDist + 1;
					queue.add(neighbour);
				}
			}
		}
		
		if (escapeTime == VERYFAR) System.out.println("IMPOSSIBLE");
		else System.out.println(escapeTime);
	}

	private static class Cell {
		char type;
		int fireDist = VERYFAR;
		int youDist = VERYFAR;
		int x;
		int y;
		
		public Cell(char type, int x, int y) {
			this.type = type;
			this.x = x;
			this.y = y;
			if (type == '@')
				youDist = 0;
			if (type == '*')
				fireDist = 0;
		}

		public boolean isWalkable() {
			return type != '#';
		}
	}
}