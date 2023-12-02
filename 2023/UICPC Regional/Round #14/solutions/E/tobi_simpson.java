// @EXPECTED_RESULTS@: CORRECT

import java.util.*;
import java.io.*;

public class tobi_simpson {
	public static double a, b, height;
	public static final int N = 100000;

	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		sc.useLocale(Locale.US);

		double V = sc.nextDouble();
		int numVases = sc.nextInt();
		double bestV = 10.e100;
		int bestId = -1;
		for (int i = 0; i < numVases; i++) {
			a = sc.nextDouble();
			b = sc.nextDouble();
			height = sc.nextDouble();
			double tmpV = volume();
			System.err.println("vol is " + tmpV);
			if (Math.abs(tmpV - V) < bestV) {
				bestV = Math.abs(tmpV - V);
				bestId = i;
			}
		}
		System.out.println(bestId);
	}

	public static double f(double x) {
		double res = a * Math.exp(-(x*x)) + b * Math.sqrt(x);
		return res * res;
	}

	public static double simpson(double tmin, double tmax) {
		double h = (tmax - tmin) / N;
		double area = 0;
		
		for (int i = 0; i < N; i++) {
			area += (h / 6.) * (f(tmin + i * h) + 4. * f(tmin + (i+.5) * h) + f(tmin + (i+1) * h));
		}

		return area;
	}

	public static double volume() {
		double area = simpson(0, height);
		return Math.PI * area;
	}
}
