// @EXPECTED_RESULTS@: CORRECT
import java.util.*;
public class Kastenlauf {
	public static void main(String [] args) {
		Scanner s = new Scanner(System.in);
		int ntc = s.nextInt();
		while(ntc-- != 0) {
			int tclen = s.nextInt() + 2;
			int [][] c = new int[tclen][2];
			for(int i = 0; i < tclen; i++) {
				c[i][0] = s.nextInt();
				c[i][1] = s.nextInt();
			}
			boolean[] mark = new boolean[tclen];
			Queue<Integer> q = new ArrayDeque<>();
			q.add(0);
			while(!q.isEmpty()) {
				int i = q.remove();
				if(mark[i]) continue;
				mark[i] = true;
				for(int j = 0; j < tclen; j++) {
					if(i == j) continue;
					if(  Math.abs(c[i][0] - c[j][0]) 
					   + Math.abs(c[i][1] - c[j][1]) <= 1000) {
						q.add(j);
					}
				}
			}
			System.out.println(mark[tclen-1] ? "happy" : "sad");
		}
	}
}
