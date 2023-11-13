import java.util.HashMap;
import java.util.HashSet;
import java.util.ArrayList;
import java.util.Collection;

public class Tower_jmv {
	
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		
		int n = in.nextInt(), a[] = new int[n], b[] = new int[n];
		ArrayList<Integer> c = new ArrayList<Integer>();
		long t = 0;
		HashSet<Integer> s = new HashSet<Integer>();
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
			if (!s.contains(a[i])) s.add(a[i]);
			else t += a[i];
			b[i] = in.nextInt();
			if (!s.contains(b[i])) s.add(b[i]);
			else t += b[i];
		}
		
		DisjointSet<Integer> d = new DisjointSet<Integer>(s);
		for (int i = 0; i < n; i++) {
			if (!d.union(a[i], b[i])) c.add(i);
		}
		boolean[] e = new boolean[s.size()];
		for (Integer i : c) e[d.find(a[i])] = true;
		
		HashMap<Integer, Integer> l = new HashMap<Integer, Integer>();
		for (Integer i : s) {
			int j = d.find(i);
			if (!e[j]) {
				if (!l.containsKey(j)) l.put(j, i);
				else if (l.get(j) < i) l.put(j, i);
			}
		}

		for (Integer i : l.values()) t += i;
		System.out.println(t);
		
		in.close();
	}
}

class DisjointSet<E> {
	private HashMap<E, Integer> is;
	private int[] S;
	private int d;
	
	@SuppressWarnings("unchecked")
	public DisjointSet(Collection<E> c) {
		this((E[]) c.toArray());
	}
	
	public DisjointSet(E[] es) {
		d = es.length;
		S = new int[d];
		is = new HashMap<E, Integer>(d);
		for (int i = 0; i < d; i++) {
			is.put(es[i], i);
			S[i] = -1;
		}
	}
	
	public int size() {
		return d;
	}
	
	public boolean union(E a, E b) {
		return iunion(is.get(a), is.get(b));
	}
	
	private boolean iunion(int a, int b) {
		int ai = ifind(a);
		int bi = ifind(b);
		if (ai == bi) return false;
		if (ai < bi) {
			S[ai] += S[bi];
			S[bi] = ai;
		}
		else {
			S[bi] += S[ai];
			S[ai] = bi;
		}
		d--;
		return true;
	}
	
	public int find(E a) {
		return ifind(is.get(a));
	}
	
	private int ifind(int a) {
		if (S[a] < 0) return a;
		return S[a] = ifind(S[a]);
	}
}
