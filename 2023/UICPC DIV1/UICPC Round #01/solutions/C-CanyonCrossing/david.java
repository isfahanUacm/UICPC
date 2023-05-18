import java.util.ArrayDeque;
import java.util.Scanner;

public class david {
	private final static int[] dx = {1,0,-1,0};
	private final static int[] dy = {0,1,0,-1};
	
	private static boolean isPossible(int R, int C, int K, int H, int[][] grid) {
		boolean done[][] = new boolean[R][C];
		
		ArrayDeque<Integer> work = new ArrayDeque<Integer>();
		ArrayDeque<Integer> nextWork = new ArrayDeque<Integer>();
		System.err.println("S");
		for (int i=0; i<=K; i++) {
			if (i == 0) {
				// setup
				for (int j=0; j<C; j++) {
					if (grid[i][j] >= H)
						work.add(j);
					else
						nextWork.add(j);
					done[0][j] = true;
				}
			}
			
			while (!work.isEmpty()) {
				int pos = work.remove();
				int x = pos/C;
				int y = pos%C;
				
				if (x == R-1) return true;
				for (int j=0; j<4; j++) {
					if (x + dx[j] < 0 || x + dx[j] >= R || y + dy[j] < 0 || y + dy[j] >= C) continue;
					if (done[x+dx[j]][y+dy[j]]) continue;
					if (grid[x+dx[j]][y+dy[j]] >= H)
						work.add((x+dx[j])*C+y+dy[j]);
					else
						nextWork.add((x+dx[j])*C+y+dy[j]);
					done[x+dx[j]][y+dy[j]] = true;
				}
			}
			
			ArrayDeque<Integer> t = work;
			work = nextWork;
			nextWork = t;
		}
		
		return false;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int R = sc.nextInt();
		int C = sc.nextInt();
		int K = sc.nextInt();
		
		int grid[][] = new int[R][C];
		for (int i=0; i<R; i++) {
			for (int j=0; j<C; j++) {
				grid[i][j] = sc.nextInt();
			}
		}
		
		int low = 0;
		int high = 1000000001;
		while (high - low > 1) {
			int mid = (high+low)/2;
			if (isPossible(R,C,K, mid, grid))
				low = mid;
			else
				high = mid;
		}
		
		System.out.println(low);
	}
}
