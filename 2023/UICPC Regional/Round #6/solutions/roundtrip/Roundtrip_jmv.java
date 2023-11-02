public class Roundtrip_jmv {
	DisjointSet DS;
	Node[] ns;
	java.util.HashSet<Long> S = new java.util.HashSet<Long>();
	
	Roundtrip_jmv(java.util.Scanner in) {
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
	
		Node(int x, int y) {
			this.x = x; this.y = y; 
			if (S.contains((1L << 32) * x + y)) 
				System.err.println("Duplicate " + x + " " + y); 
			else S.add((1L << 32) * x + y);
		}
	
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
		Roundtrip_jmv R = new Roundtrip_jmv(new java.util.Scanner(System.in));
		java.util.PriorityQueue<Node> q = new java.util.PriorityQueue<Node>();
		double cost = 0;
		for (Node n : R.ns)
			if (n.c == 2)
				cost += n.process();
			else
				q.offer(n);
		while (!q.isEmpty()) 
			cost += q.poll().process();
			
		if (R.DS.s > 1) {
			for (Node n : R.ns) {
				if (n.c == 2) continue;
				if (R.DS.find(n.es[0].c) != R.DS.find(n.es[2].c)) {
					n.d = -n.d;
					q.offer(n);
					System.err.println("D: " + n.x + " " + n.y);
				}
			}
		}
		while (!q.isEmpty()) {
			Node n = q.poll();
			n.d = -n.d;
			if (R.DS.find(n.es[0].c) != R.DS.find(n.es[2].c)) {
				cost += n.d;
				R.DS.union(n.es[0].c, n.es[2].c);
				System.err.println("C: " + n.x + " " + n.y);
			}
		}
		if (R.DS.s > 1) System.out.println("ILLEGAL SOLUTION :<");
		else System.out.println(cost);
	}
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