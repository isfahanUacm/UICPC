// @EXPECTED_RESULTS@: CORRECT

import java.util.*;
public class jakob {
	
	static class tgts {
		int[][] t;
		public void addTgt(int x1, int y1, int x2, int y2) {
			if(t == null) {
				t = new int[1][4];
				t[0][0] = x1;
				t[0][1] = y1;
				t[0][2] = x2;
				t[0][3] = y2;
			} else {
				t = Arrays.copyOf(t, t.length+1);
				t[t.length-1] = new int[4];
				t[t.length-1][0] = x1;
				t[t.length-1][1] = y1;
				t[t.length-1][2] = x2;
				t[t.length-1][3] = y2;
			}
		}
	}
	
	static tgts t [][] = new tgts[5][9];

	public static boolean isValid(int x, int y) {
		if(x < 0 || x >= 5) return false;
		if(y < 0 || y >= 9) return false;
		if((x == 0 || x == 4) && (y < 3 || y > 5)) return false;
		return true;
	}

	static boolean[][] field;
	static int cp;

	static int bt() {
		int min = cp;
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 9; j++) {
				if(field[i][j]) {
					for(int ti = 0; ti < t[i][j].t.length; ti++) {
						int x1 = t[i][j].t[ti][0];
						int y1 = t[i][j].t[ti][1];
						int x2 = t[i][j].t[ti][2];
						int y2 = t[i][j].t[ti][3];
						if(field[x1][y1] && ! field[x2][y2]) {
							field[i][j] = false;
							field[x1][y1] = false;
							field[x2][y2] = true;
							cp--;
							int tmp = bt();
							field[i][j] = true;
							field[x1][y1] = true;
							field[x2][y2] = false;
							cp++;
							if(tmp < min) min = tmp;
						}
					}
				}
			}
		}
		return min;
	}

	public static void main(String args[] ) {
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 9; j++) {
				t[i][j] = new tgts();
				for(int dir = 0; dir < 4; dir++) {
					int x1 = i, y1 = j, x2 = i, y2 = j;
					int x0 = i, y0 = j;
					if(dir == 0) {
						x1++;
						x2++; x2++; 
					} else if(dir == 1) {
						x1--;
						x2--; x2--; 
					} else if(dir == 2) {
						y1++;
						y2++; y2++; 
					} else if(dir == 3) {
						y1--;
						y2--; y2--; 
					}
					if(isValid(x0, y0) && isValid(x1,y1) && isValid(x2,y2))
						t[x0][y0].addTgt(x1,y1,x2,y2);
				}
			}
		}
		Scanner s = new Scanner(System.in);
		int ntc = s.nextInt();
		for(int tc = 0; tc < ntc; tc++){
			String ign = s.nextLine();
			field = new boolean[5][9];
			cp = 0;
			for(int i = 0; i < 5; i++) {
				String b = s.nextLine();
				for(int j = 0; j < b.length(); j++){
					if(b.charAt(j) == 'o') {
						field[i][j] = true;
						cp++;
					}
				}
			}
			int min = bt();
			System.out.println(min + " " + (cp - min));
		}
		
	}
}