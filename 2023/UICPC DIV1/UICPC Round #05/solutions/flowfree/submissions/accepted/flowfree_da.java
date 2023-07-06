import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class flowfree_da {

	private static String colors = "RGBYW";
	private static int NOT_SOLVABLE = 0;
	private static int SOLVABLE = 1;

	private int result;
	private int[] paintedCount;
	private int[][] board;

	private void work() {
		readBoard();
		solve();
		System.out.println((result != 1 ? "not " : "") + "solvable");
	}

	private void readBoard() {
		board = new int[4][4];
		Scanner sc = new Scanner(System.in);
		for (int i = 0; i < 4; i++) {
			char[] line = sc.next().toCharArray();
			for (int j = 0; j < 4; j++) {
				board[i][j] = colors.indexOf(line[j]);
				if (board[i][j] < 0 || board[i][j] > 4) {
					sc.close();
					throw new IllegalArgumentException(String.format("Illegal color in the input: %c", line[j]));
				}
			}
		}
		sc.close();
	}

	private void solve() {

		Map<Integer, List<Cell>> m = new HashMap<>();
		for (int i = 0; i < 4; i++) {
			m.put(i, new ArrayList<>());
		}

		List<Cell> blanks = new ArrayList<>();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				Cell cell = new Cell(i, j);
				if (board[i][j] == 4)
					blanks.add(cell);
				else
					m.get(board[i][j]).add(cell);
			}
		}

		Cell[][] colors = new Cell[(16 - blanks.size()) / 2][2];
		for (Map.Entry<Integer, List<Cell>> e : m.entrySet()) {
			int color = e.getKey();
			List<Cell> cells = e.getValue();
			if (cells.isEmpty()) {
				if (color != 3)
					throw new IllegalArgumentException(
							String.format("Only the 4th color (Yellow) can be missing %d", cells.size()));
			} else {
				if (cells.size() != 2)
					throw new IllegalArgumentException(
							String.format("Expected 2 or 0 cells of the same color but got %d", cells.size()));

				colors[color][0] = cells.get(0);
				colors[color][1] = cells.get(1);
			}
		}

		result = NOT_SOLVABLE;
		paintedCount = new int[colors.length];
		evaluateAll(0, blanks, colors);
	}

	private void evaluateAll(int k, List<Cell> blanks, Cell[][] colors) {
		if (result == SOLVABLE)
			return;

		if (k == blanks.size()) {
			boolean ok = true;
			for (int i = 0; i < colors.length && ok; i++) {
				ok &= findPath(i, colors[i][0], colors[i][1]);
			}

			if (ok)
				result = SOLVABLE;

			return;
		}

		Cell nextBlank = blanks.get(k);
		for (int color = 0; color < colors.length; color++) {
			board[nextBlank.r][nextBlank.c] = color;
			paintedCount[color]++;
			evaluateAll(k + 1, blanks, colors);
			paintedCount[color]--;
		}
	}

	private Set<State> seen = new HashSet<State>();
	private Queue<State> q = new LinkedList<>();
	private int[] dr = { -1, 0, 1, 0 };
	private int[] dc = { 0, 1, 0, -1 };

	private boolean findPath(int color, Cell s, Cell e) {

		seen.clear();
		q.clear();
		State start = new State(s);
		q.add(start);
		seen.add(start);

		while (!q.isEmpty()) {
			State cur = q.poll();
			if (cur.tail.equals(e)) {
				if (cur.path.size() - 2 == paintedCount[color])
					return true;
			} else {
				Cell prev = cur.tail;
				for (int i = 0; i < 4; i++) {
					int rr = prev.r + dr[i];
					if (rr < 0 || rr == 4)
						continue;
					int cc = prev.c + dc[i];
					if (cc < 0 || cc == 4)
						continue;
					if (board[rr][cc] == color) {
						Cell next = new Cell(rr, cc);
						if (!cur.path.contains(next)) {
							State ns = new State(cur, next);
							if (!seen.contains(ns)) {
								seen.add(ns);
								q.add(ns);
							}
						}
					}
				}
			}
		}

		return false;
	}

	public static void main(String[] args) throws IOException {
		new flowfree_da().work();
	}

	class Cell {
		int r, c;
		private int hash;

		Cell(int r, int c) {
			this.r = r;
			this.c = c;
		}

		public String toString() {
			return String.format("(%d, %d)", r, c);
		}

		public int hashCode() {
			if (hash == 0)
				hash = 37 * r + c;
			return hash;
		}

		public boolean equals(Object o) {
			Cell cell = (Cell) o;
			return r == cell.r && c == cell.c;
		}
	}

	class State {
		State prev;
		Cell tail;
		Set<Cell> path;
		int hash;

		State(Cell next) {
			this(null, next);
		}

		State(State prev, Cell next) {
			path = new HashSet<>();
			if (prev != null)
				path.addAll(prev.path);
			path.add(next);
			tail = next;
		}

		public int hashCode() {
			if (hash == 0)
				for (Cell c : path)
					hash = 31 * hash + c.hashCode();
			return hash;
		}

		public boolean equals(Object o) {
			State s = (State) o;
			return tail.equals(s.tail) && path.equals(s.path);
		}
	}
}