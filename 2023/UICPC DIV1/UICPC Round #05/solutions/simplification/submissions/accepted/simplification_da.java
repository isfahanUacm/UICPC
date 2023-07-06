import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Scanner;

public class simplification_da {

	class Triangle implements Comparable<Triangle> {
		int left, mid, right;
		long area;

		Triangle(int left, int mid, int right, long area) {
			this.left = left;
			this.right = right;
			this.mid = mid;
			this.area = area;
		}

		@Override
		public int compareTo(Triangle o) {
			if (area < o.area)
				return -1;
			if (area > o.area)
				return 1;
			if (mid < o.mid)
				return -1;
			if (mid > o.mid)
				return 1;
			return (right - left) - (o.right - o.left);
		}

		public String toString() {
			return String.format("(%d, %d, %d) - %d", left, mid, right, area);
		}
	}

	private void work() {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int n = sc.nextInt() + 1;
		int m = n - sc.nextInt() - 1;

		int[] x = new int[n];
		int[] y = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = sc.nextInt();
			y[i] = sc.nextInt();
		}

		Triangle[] ts = new Triangle[n];
		PriorityQueue<Triangle> pq = new PriorityQueue<>();
		boolean[] seen = new boolean[n];

		for (int i = 1; i < n - 1; i++) {
			ts[i] = new Triangle(i - 1, i, i + 1, getArea(i - 1, i, i + 1, x, y));
			pq.add(ts[i]);
		}
		
		while (m-- > 0) {
			Triangle cur = pq.poll();
			while (seen[cur.left] || seen[cur.right])
				cur = pq.poll();

			seen[cur.mid] = true;
			System.out.println(cur.mid);

			if (cur.left > 0) {
				ts[cur.left] = new Triangle(ts[cur.left].left, cur.left, cur.right,
						getArea(ts[cur.left].left, cur.left, cur.right, x, y));
				pq.add(ts[cur.left]);
			}

			if (cur.right < n - 1) {
				ts[cur.right] = new Triangle(cur.left, cur.right, ts[cur.right].right,
						getArea(cur.left, cur.right, ts[cur.right].right, x, y));
				pq.add(ts[cur.right]);
			}
		}

		sc.close();
	}

	private long getArea(int i, int j, int k, int[] x, int[] y) {
		long bax = x[j] - x[i];
		long bay = y[j] - y[i];
		long cax = x[k] - x[i];
		long cay = y[k] - y[i];
		return Math.abs(bax * cay - cax * bay);
	}

	public static void main(String[] args) {
		new simplification_da().work();
	}

}
