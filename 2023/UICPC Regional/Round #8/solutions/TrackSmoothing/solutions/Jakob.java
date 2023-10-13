// @EXPECTED_RESULTS@: CORRECT

import java.util.*;
public class Jakob {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int ntc = sc.nextInt();
		while(ntc-->0) {
			int radius = sc.nextInt();
			int npoints = sc.nextInt();
			int fx = sc.nextInt();
			int fy = sc.nextInt();
			double len = 0;
			int px = fx, py = fy, x=0, y=0;
			for(int i = 1; i < npoints; i++){
				x = sc.nextInt();
				y = sc.nextInt();
				len += Math.sqrt((x-px)*(x-px) + (y-py)*(y-py));
				px = x; 
				py = y;
			}
			len += Math.sqrt((x-fx)*(x-fx) + (y-fy)*(y-fy));
			double add = 2 * Math.PI * radius;
			if(add > len) {
				System.out.println("Not possible");
			} else {
				System.out.println((len - add) / len);
			}
		}
	}
}
