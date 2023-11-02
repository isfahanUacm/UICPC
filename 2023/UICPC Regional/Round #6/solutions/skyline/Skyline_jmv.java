public class Skyline_jmv {
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		int n = in.nextInt();
		double[][] B = new double[n][4];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 4; j++) {
				B[i][j] = in.nextDouble();
			}
		}

		Ray r = new Ray(-1, 0, 0, Ray.INF);
		double a = 0, b, c = 0;
		for (int i = 0; i < n; i++) {
			double e = (i + 1) * 1e-9, f = Math.PI * e;
			Ray s = new Ray(B[i][0] + e, -1 + f, Double.POSITIVE_INFINITY, 
				new Ray(B[i][0] + e, B[i][1] + f, (B[i][3] - B[i][1]) / (B[i][2] - B[i][0]), 
				new Ray(B[i][2] + e, B[i][3] + f, Double.NEGATIVE_INFINITY, 
				new Ray(B[i][2] + e, 0 + f, 0, Ray.INF))));
			b = s.area();
			merge(r, s);
			c = r.area();
			System.out.println((c - a) / b);
			a = c;
		}
	}

	static void merge(Ray u, Ray l) {
		if (l == Ray.INF || u == Ray.INF) return;
		double x, y;
		if (l.t == Double.POSITIVE_INFINITY || l.t == Double.NEGATIVE_INFINITY) {
			x = l.x;
			y = u.y + u.t * (l.x - u.x);
		}
		else if (u.t == Double.POSITIVE_INFINITY || u.t == Double.NEGATIVE_INFINITY) {
			x = u.x;
			y = l.y + l.t * (u.x - l.x);
		}
		else {
			double dx = (u.y - l.y + u.t * (l.x - u.x)) / (l.t - u.t);
			x = l.x + dx;
			y = l.y + l.t * dx;
		}
		if (x >= l.x && x <= l.n.x && x >= u.x && x <= u.n.x 
		&& ((y >= l.y && y <= l.n.y) || (y >= l.n.y && y <= l.y)) 
		&& ((y >= u.y && y <= u.n.y) || (y >= u.n.y && y <= u.y))) {
			Ray un = new Ray(x, y, l.t, l.n);
			l = u;
			u = un;
		}
		if (u.n.x < l.n.x) merge(u.n, l);
		else merge(u, l.n);
		l.n = u;
	}

	static class Ray {
		double x, y, t;
		Ray n;

		Ray(double x, double y, double t, Ray n) {
			this.x = x;
			this.y = y;
			this.t = t;
			this.n = n;
		}

		double area() {
			return n == INF ? 0 : (t == Double.POSITIVE_INFINITY || t == Double.NEGATIVE_INFINITY ? 0 : (n.x - x) * (n.y + y) / 2) + n.area();
		}

		static final Ray INF = new Ray(Double.POSITIVE_INFINITY, 0, 0, null);
	}
}