import java.util.*;

public class space_jmv {
	public static final int MAX = 12;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), c = 0;
		int[] a = new int[n + 2], b = new int[n + 2];
		for (int i = 2; i < n + 2; i++) {
			c += a[i] = in.nextInt();
		}
		
		for (int i = 1; i <= MAX + 1; i++) {
			HashSet<S> m = new HashSet<S>(), p = new HashSet<S>(), o;
			for (int j = 2; j < n + 2; j++) {
				b[j] = a[j];
			}
			byte[] t = new byte[i + 1];
			for (int j = 2; j <= i; j++) {
				t[j] = 1;
			}
			m.add(new S(t));
			
			for (int k = 0, l = n + 1; k < c; k++) {
				while (b[l] == 0) {
					l--;
				}
				b[l]--;
				
				for (S s : m) {
					for (int j = l; j <= i ; j++) {
						if (s.h[j] > 0) {
							byte[] g = s.h.clone();
							g[j - l]++;
							g[j]--;
							S u = new S(g);
							if (!p.contains(u)) p.add(u);
						}
					}
				}
				
				m.clear();
				o = p; p = m; m = o;
			}
			
			if (!m.isEmpty()) {
				System.out.println(i - 1);
				return;
			}
		}
		
		System.out.println("impossible");
	}
	
	static class S {
		byte[] h;
		S(byte[] h) {this.h = h;}
		
		public int hashCode() {
			int r = 0;
			for (int i = 0; i < h.length; i++) {
				r += 37 * h[i];
				r *= 59;
				r += 13;
			}
			return r;
		}
		
		public boolean equals(Object o) {
			S s = (S) o;
			if (h.length != s.h.length) return false;
			for (int i = 0; i < h.length; i++) {
				if (h[i] != s.h[i]) return false;
			}
			return true;
		}
	}
}