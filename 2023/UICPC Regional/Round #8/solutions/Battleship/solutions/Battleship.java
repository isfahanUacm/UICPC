// @EXPECTED_RESULTS@: CORRECT

import java.util.Scanner;

public class Battleship {
	public static void main(String args[]){
		int ntc;
		Scanner s = new Scanner(System.in);
		ntc = s.nextInt();
		for(int tccounter = 1; tccounter <= ntc; tccounter++) {
			int w = s.nextInt();
			int h = s.nextInt();
			int ns = s.nextInt();
			s.nextLine();
			System.err.println(w + " " + h + " " + ns);
			char[][] p1 = new char[h][];
			char[][] p2 = new char[h][];
			int p1s = 0;
			int p2s = 0;
			for(int i = h-1; i >= 0; i--){
				p1[i] = s.nextLine().toCharArray();
				for(int j = 0; j < w; j++){
					if(p1[i][j] == '#') p1s++;
				}
			}
			for(int i = h-1; i >= 0; i--){
				p2[i] = s.nextLine().toCharArray();
				for(int j = 0; j < w; j++){
					if(p2[i][j] == '#') p2s++;
				}
			}
			boolean p1turn = true;
			boolean end = false;
			int sh;
			for(sh = 0; sh < ns; sh++){
				int x = s.nextInt();
				int y = s.nextInt();
				if(end) continue;
				char[][] target;
				if(p1turn) {
					target = p2;
				} else {
					target = p1;
				}
				if(target[y][x] == '#') {
					// hit!
					target[y][x] = '_';
					if(p1turn) {
						p2s--; 
						if(p2s == 0) {
							p1turn = !p1turn;
							System.err.println("testcase " + tccounter + " shot " + (sh+1));
						}
					} else {
						p1s--;
						if(p1s == 0) {
							end = true;
						}
					}
				} else {
					p1turn = !p1turn;
				}
			}
			if(p1s == 0 && p2s == 0) {
				System.out.println("draw");
			} else if(p1s == 0) {
				System.out.println("player two wins");
			} else if(p2s == 0) {
				System.out.println("player one wins");
			} else {
				System.out.println("draw");
			}
		}
	}
}
