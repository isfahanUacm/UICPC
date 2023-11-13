import java.util.ArrayList;
import java.util.HashMap;

public class Cardhand_jmv {

	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		int n = in.nextInt();
		ArrayList<Card> h = new ArrayList<Card>();
		for (int i = 0; i < n; i++) {
			h.add(new Card(in.next()));
		}
		in.close();

		ArrayList<Integer> s = new ArrayList<Integer>();
		s.add(0); s.add(1); s.add(2); s.add(3);
		HashMap<Character, Integer> o = new HashMap<Character, Integer>();
		int v = n;
		for (int a = 0; a < 4; a++) {
			o.put('s', s.remove(a));
			for (int b = 0; b < 3; b++) {
				o.put('h', s.remove(b));
				for (int c = 0; c < 2; c++) {
					o.put('c', s.remove(c));
					o.put('d', s.get(0)); 

					for (int p = 0; p < 16; p++) {
						final int q = p;
						ArrayList<Card> g = (ArrayList<Card>) h.clone(), f = (ArrayList<Card>) h.clone();
						java.util.Comparator<Card> e = 
							(x, y) ->
								x.s == y.s 
								? (q & (1 << o.get(x.s))) == 0 
									? x.v - y.v 
									: y.v - x.v 
								: o.get(x.s) - o.get(y.s);
						
						int[] r = new int[n];
						for (int i = 0; i < n; i++) {
							r[i] = 1;
							for (int j = 0; j < i; j++) {
								if (e.compare(h.get(i), h.get(j)) > 0)
									r[i] = Math.max(r[i], r[j] + 1);
							}
							v = Math.min(n - r[i], v);
						}
					}
					s.add(c, o.get('c'));
				}
				s.add(b, o.get('h'));
			}
			s.add(a, o.get('s'));
		}
		
		System.out.println(v);
	}

	static class Card {
		char v, s;
		String t;
		
		Card(String t) {
			v = t.charAt(0);
			if(v == 'T') v = '0' + 10;
			if(v == 'J') v = '0' + 11;
			if(v == 'Q') v = '0' + 12;
			if(v == 'K') v = '0' + 13;
			if(v == 'A') v = '0' + 14;
			s = t.charAt(1);
			this.t = t;
		}
		
		public String toString() {
			return t;
		}
	}
}
