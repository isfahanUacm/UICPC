import java.util.*;

public class Antti {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int[] t = new int[n];
		for (int i = 0; i < n; i++) t[i] = input.nextInt();
		int[] r = {0,100};
		for (int i = 0; i+2 < n; i++) {
			int u = Math.max(t[i],t[i+2]);
			if (u < r[1]) {
				r[0] = i+1;
				r[1] = u;
			}
		}
		System.out.println(r[0]+" "+r[1]);
	}
}
