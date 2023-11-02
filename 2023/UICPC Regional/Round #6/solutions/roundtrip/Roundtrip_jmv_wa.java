public class Roundtrip_jmv_wa {
	DisjointSet DS;
	Node[] ns;
	java.util.HashSet<Long> S = new java.util.HashSet<Long>();
	
	Roundtrip_jmv_wa(java.util.Scanner in) {
		int n = in.nextInt(), m = in.nextInt();
		DS = new DisjointSet(m);
		ns = new Node[n];
		for (int i = 0; i < n;  i++) 
			ns[i] = new Node(in.nextInt(), in.nextInt());
		for (int i = 0; i < m; i++) {
			Edge e = new Edge(ns[in.nextInt()], ns[in.nextInt()], i);
			e.u.add(e);
			e.v.add(e);
		}
		for (int i = 0; i < n; i++)
			ns[i].calc();
	}

	class Edge {
		Node u, v;
		int c;
		
		Edge(Node u, Node v, int c) {this.u = u; this.v = v; this.c = c;}
	}

	class Node implements Comparable<Node> {
		int c;
		double m, d, x, y;
		Edge[] es = new Edge[4];
	
		Node(int x, int y) {this.x = x; this.y = y; if (S.contains((1L << 32) * x + y)) System.err.println(x + " " + y); else S.add((1L << 32) * x + y);}
	
		void add(Edge e) {
			es[c++] = e;
		}
	
		void calc() {
			if (c == 2) {
				m = angle(0, 1);
				d = 0;
			}
			else {
				double r = angle(0, 1) + angle(2, 3);
				double s = angle(0, 2) + angle(1, 3);
				double t = angle(0, 3) + angle(1, 2);
				if (r < s) {
					if (r < t) {
						m = r;
						d = (s < t ? s : t) - r;
					}
					else {
						Edge e = es[3];
						es[3] = es[1];
						es[1] = e;
						m = t;
						d = r - t;
					}
				}
				else {
					if (s < t) {
						Edge e = es[2];
						es[2] = es[1];
						es[1] = e;
						m = s;
						d = (r < t ? r : t) - s;
					}
					else {
						Edge e = es[3];
						es[3] = es[1];
						es[1] = e;
						m = t;
						d = s - t;
					}
				}
			}
		}
		
		double process() {
			if (c == 2) {
				DS.union(es[0].c, es[1].c);
				return m;
			}
			else {
				if (DS.find(es[0].c) != DS.find(es[1].c) && DS.find(es[2].c) != DS.find(es[3].c)) {
					DS.union(es[0].c, es[1].c);
					DS.union(es[2].c, es[3].c);
					return m;
				}
				else {
					DS.union(es[0].c, es[2].c);
					DS.union(es[1].c, es[3].c);
					return m + d;
				}
			}
		}

		double angle(int i, int j) {
			Node v = es[i].u != this ? es[i].u : es[i].v, w = es[j].u != this ? es[j].u : es[j].v;
			double ax = v.x - x, ay = v.y - y, bx = w.x - x, by = w.y - y;
			double cos = (ax * bx + ay * by) / Math.sqrt((ax * ax + ay * ay) * (bx * bx + by * by));
			return Math.PI - Math.acos(cos);
		}
		
		public int compareTo(Node n) {
			return (int) Math.signum(n.d - d);
		}
	}

	public static void main(String[] args) {
		Roundtrip_jmv_err_ R = new Roundtrip_jmv_err_(new java.util.Scanner(System.in));
		java.util.PriorityQueue<Node> q = new java.util.PriorityQueue<Node>();
		double cost = 0;
		for (Node n : R.ns)
			if (n.c == 2)
				cost += n.process();
			else
				q.offer(n);
		while (!q.isEmpty()) 
			cost += q.poll().process();
		System.out.println(cost);
	}/*
		//Check all possibilities for correctness
		double min = Double.MAX_VALUE;
		for (Node n : R.ns) 
			for (int i = 0; i < n.c; i++)
				n.es[i].c = -1;
		min = Math.min(min, R.dfs(R.ns[0].es[0], R.ns[0], 0, 0.0));
		System.err.printf("Min found among all: %.5f\n", min);
	}
	
	double dfs(Edge e, Node u, int c, double d) {
		double min = Double.MAX_VALUE;
		e.c = 1;
		c++;
		Node v = e.u == u ? e.v : e.u;
		int j = -1;
		for (int i = 0; i < v.c; i++)
			if (v.es[i] == e)
				j = i;
		for (int i = 0; i < v.c; i++) {
			double f = v.angle(i, j);
			if (v.es[i] == ns[0].es[0] && c == DS.M.length)
				//System.err.printf("Walk found with cost %.5f\n", d + f);
				min = Math.min(min, d + f);
			if (v.es[i].c == -1) 
				min = Math.min(min, dfs(v.es[i], v, c, d + f));
		}
		e.c = -1;
		return min;
	}*/
}

class DisjointSet {
	int[] M;
	int s;
	
	DisjointSet(int size) {
		M = new int[size];
		java.util.Arrays.fill(M, -1);
		s = size;
	}
	
	int find(int u) {
		if (M[u] < 0) return u;
		return M[u] = find(M[u]);
	}
	
	void union(int u, int v) {
		int fu = find(u), fv = find(v);
		if (fu == fv) return;
		if (M[fu] >= M[fv]) {
			M[fu] += M[fv];
			M[fv] = fu;
		}
		else {
			M[fv] += M[fu];
			M[fu] = fv;
		}
		s--;
	}
}
