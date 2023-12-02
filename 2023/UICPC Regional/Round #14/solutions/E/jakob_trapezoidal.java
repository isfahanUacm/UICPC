// @EXPECTED_RESULTS@: CORRECT
// straightforward integration by trapezoidal rule. should pass.
import static java.lang.Math.abs;
import static java.lang.Math.ceil;
import static java.lang.Math.exp;
import static java.lang.Math.sqrt;
import java.util.*;
import java.util.Scanner;

public class jakob_trapezoidal {
	
	static double function(double a, double b, double x) {
		double value = a * exp(-x*x) + b * sqrt(x);
		return value * value * Math.PI;
	}

	static double volume(double a, double b, double h) {
		int numberOfSteps = (int)ceil(h / 1e-5);
		double dx = h/(double)numberOfSteps;
		double volume = 0.0;

		int step = 0;
		double x = step * dx;
		double value = function(a, b, x);
		volume += (value * dx)/2;
		
		for(step = 1; step < numberOfSteps; step++) {
			x = step * dx;
			value = function(a, b, x);
			volume += value * dx;
		}

		step = numberOfSteps;
		x = step * dx;
		value = function(a, b, x);
		volume += (value * dx)/2;
  
		return volume;
	}
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		sc.useLocale(Locale.US);
		int numCases = 1;
		while (numCases --> 0) {
			double V = sc.nextDouble();
			int numVases = sc.nextInt();
			double bestV = 10.e100;
			int bestId = -1;
			for (int i = 0; i < numVases; i++) {
				double a = sc.nextDouble();
				double b = sc.nextDouble();
				double height = sc.nextDouble();
				double tmpV = volume(a, b, height);
				System.err.println("vol is " + tmpV);
				if (Math.abs(tmpV - V) < bestV) {
					bestV = Math.abs(tmpV - V);
					bestId = i;
				}
			}
			System.out.println(bestId);
		}
	}

}
