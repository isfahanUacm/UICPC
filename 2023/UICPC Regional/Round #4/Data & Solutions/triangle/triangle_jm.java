import java.util.*;

public class triangle_jm {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		// Factorize
		int t = N;
		ArrayList<Integer> primes = new ArrayList<Integer>();
		for (int p = 2; p*p <= t; p++)
			while (t%p == 0)
			{
				primes.add(p);
				t /= p;
			}
		if (t > 1)
			primes.add(t);
        
		// [Ax] = Integer sequence number
		// allSols = number of solutions to x^2+y^2-z^2 = 0 (mod n) [A062775]
		// eqSols = number of solutions to x^2-y^2 = 0 (mod n) [A062803]
		// zeroSols = number of solutions to x^2+y^2 = 0 (mod n) [A086933]
		// squareZeroSols = number of solutions to x^2 = 0 (mod n) [A000188]
		// pairSols = number of solutions to x^2-2*y^2 = 0 (mod n) [A088964]
		// pairZeroSols = number of solutions to 2*x^2 = 0 (mod n)

		long allSols = 1, eqSols = 1, zeroSols = 1, squareZeroSols = 1, pairSols = 1, pairZeroSols = 1;
		for (int i = 0; i < primes.size(); i++)
		{
			long p = primes.get(i);
			int e = 1;
			while (i + 1 < primes.size()&& p == primes.get(i + 1))
			{
				e++;
				i++;
			}

			if (e == 1)
				allSols *= p*p;
			else if (e > 1)
			{
				int k = e/2 + e%2;

				if (p == 2 && e%2 == 1)
					allSols *= Power(2, 3*k - 1)*(Power(2, k) - 1);
				else if (p == 2 && e%2 == 0)
					allSols *= Power(2, 3*k)*(Power(2, k + 1) - 1);
				else if (e%2 == 1)
					allSols *= Power(p, 3*k - 2)*(Power(p, k) + Power(p, k - 1) - 1);
				else
					allSols *= Power(p, 3*k - 1)*(Power(p, k + 1) + Power(p, k) - 1);
			}
			
			
			if (p == 2)
			{
				eqSols *= e * Power(2, e);
				zeroSols *= Power(2, e);
				pairSols *= Power(p, e);
				pairZeroSols *= Power(p, (e + 1) / 2);
			}
			else
			{
				pairZeroSols *= Power(p, e / 2);
				eqSols *= ((p - 1) * e + p) * Power(p, e - 1);
				if (p % 4 == 3)
					zeroSols *= Power(p, e - (e % 2));
				else
					zeroSols *= ((p - 1) * e + p) * Power(p, e - 1);
				if (p % 8 == 1 || p % 8 == 7)
					pairSols *= ((p - 1) * e + p) * Power(p, e - 1);
				else
					pairSols *= Power(p, e - e % 2);
			}
			
			squareZeroSols *= Power(p, e / 2);
		}
		
		long solutions = (allSols + pairSols)/2 - eqSols - (zeroSols + pairZeroSols) / 2 + squareZeroSols;

		System.out.println(solutions);
		
	}
	
	static long Power(long b, long exp)
	{
		long v = 1;
		while (exp-- > 0)
			v *= b;
		return v;
	}

}
