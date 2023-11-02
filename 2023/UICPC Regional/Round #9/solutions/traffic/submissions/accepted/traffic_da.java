import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class traffic_da {

	private void work() {
		int A = 0;
		int B = 1;
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int[] x = new int[2];
		int[] n = new int[2];
		int[][] ts = new int[2][];
		x[A] = 2 * sc.nextInt();
		x[B] = 2 * sc.nextInt();
		n[A] = sc.nextInt();
		ts[A] = new int[n[A]];
		for (int i = 0; i < n[A]; i++) {
			ts[A][i] = 2 * sc.nextInt();
		}
		n[B] = sc.nextInt();
		ts[B] = new int[n[B]];
		for (int i = 0; i < n[B]; i++) {
			ts[B][i] = 2 * sc.nextInt();
		}

		if (x[A] > x[B]) {
			A = 1;
			B = 0;
		}

		int[] i = new int[2];
		int[] v = new int[2];

		int t = 0;
		int bump = -1;
		while (i[A] < n[A] && i[B] < n[B]) {
			int nt, nvA, nvB;
			if (ts[A][i[A]] <= ts[B][i[B]]) {
				nt = ts[A][i[A]];
				nvA = 1 - v[A];
				nvB = v[B];
				if (ts[A][i[A]++] == ts[B][i[B]]) {
					i[B]++;
					nvB = 1 - v[B];
				}

			} else {
				nt = ts[B][i[B]++];
				nvA = v[A];
				nvB = 1 - v[B];
			}
			int nxA = x[A] + (nt - t) * v[A];
			int nxB = x[B] + (nt - t) * v[B];
			int nd = nxB - nxA - 9;
			if (nd <= 0) {
				bump = (t + x[B] - x[A] - 8) / 2;
				break;
			}
			t = nt;
			v[A] = nvA;
			v[B] = nvB;
			x[A] = nxA;
			x[B] = nxB;
		}

		if (bump < 0) {
			if (i[A] < n[A] && v[B] == 0) {
				int nt, nvA, nxA;
				while (i[A] < n[A]) {
					nt = ts[A][i[A]++];
					nvA = 1 - v[A];
					nxA = x[A] + (nt - t) * v[A];
					int nd = x[B] - nxA - 9;
					if (nd <= 0) {
						bump = (t + x[B] - x[A] - 8) / 2;
						break;
					}
					v[A] = nvA;
					x[A] = nxA;
					t = nt;
				}
			}
			if (i[B] < n[B] && v[A] == 1) {
				int nt, nvB, nxA, nxB;
				while (i[B] < n[B]) {
					nt = ts[B][i[B]++];
					nvB = 1 - v[B];
					nxA = x[A] + nt - t;
					nxB = x[B] + (nt - t) * v[B];
					int nd = nxB - nxA - 9;
					if (nd <= 0) {
						bump = (t + x[B] - x[A] - 8) / 2;
						break;
					}
					v[B] = nvB;
					x[A] = nxA;
					x[B] = nxB;
					t = nt;
				}
			}
			if (bump < 0 && v[B] == 0 && v[A] == 1) {
				bump = (t + x[B] - x[A] - 8) / 2;
			}
		}

		if (bump < 0)
			System.out.println("safe and sound");
		else
			System.out.println("bumper tap at time " + bump);

		sc.close();
	}

	public static void main(String[] args) {
		long startTime = System.currentTimeMillis();
		new traffic_da().work();
		long t = System.currentTimeMillis() - startTime;
		System.err.println(String.format("Elapsed time: %d:%02d.%03d\n", t / 60000, (t / 1000) % 60, t % 1000));
	}

}
