import java.util.*;

public class Antti {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String w = input.next();
		char e = w.charAt(w.length()-1);
		int n = input.nextInt();
		String[] t = new String[n];
		for (int i = 0; i < n; i++) t[i] = input.next();
		int[] c = new int[128];
		for (int i = 0; i < n; i++) c[t[i].charAt(0)]++;
		for (int i = 0; i < n; i++) {
			char a = t[i].charAt(0);
			char b = t[i].charAt(t[i].length()-1);
			if (a == e && (c[b] == 0 || (a == b && c[b] == 1))) {
				System.out.println(t[i]+"!");
				return;
			}
		}
		for (int i = 0; i < n; i++) {
			if (t[i].charAt(0) == e) {
				System.out.println(t[i]);
				return;
			}
		}
		System.out.println("?");
	}
}
