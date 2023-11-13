public class Exponial_jmv {
	static final int N = 1_000_000_000;
	static int n;
	static int[] primes;
	
	static {
		int m = (int) Math.sqrt(N) / 2;
		n = 1;
		boolean[] nonPrime = new boolean[m];
		for (int i = 0; i < Math.sqrt(m); i++) {
			if (!nonPrime[i]) {
				n++;
				for (int j = i; (j += 2 * i + 3) < m; ) {
					nonPrime[j] = true;
				}
			}
		}
		for (int i = (int) Math.sqrt(m); i < m; i++) {
			n += nonPrime[i] ? 0 : 1;
		}
				
		primes = new int[n];
		primes[0] = 2;
		for (int i = 0, j = 0; j < m; j++) {
			if (!nonPrime[j]) primes[++i] = 2 * j + 3;
		}
	}
	
	static int[] factors(long q) {
		int[] factors = new int[n + 1];
		for (int i = 0; i < n; i++) {
			while (q % primes[i] == 0) {
				factors[i]++;
				q /= primes[i];
			}
		}
		if (q != 1) {
			factors[n] = (int) q;		// Store q's remainder in the last position. 
		}
		return factors;
	}
	
	static long phi(int[] factors) {
		long phi = 1;
		if (factors[n] != 0) phi *= factors[n] - 1;	// Special case detailed above. 
		for (int i = 0; i < n; i++) {
			if (factors[i] > 0) {
				phi *= (primes[i] - 1);
				for (int j = 1; j < factors[i]; j++) {
					phi *= primes[i];
				}
			}
		}
		return phi;
	}
	
	static long fastExp(long q, long e, long m) {
		long r = 1, p = q;
		for (; e > 0; e >>= 1) {
			if ((e & 1) > 0) r = (r * p) % m;
			p = (p * p) % m;
		}
		return r % m;
	}
	
	static long exponial(long q, long m) {
		if (m == 1) return 0;
		int[] qFactors = factors(q), mFactors = factors(m);
		for (int i = 0; i < n; i++) {
			if (qFactors[i] > 0) {
				mFactors[i] = 0;
			}
		}
		long phi = phi(mFactors);
		long exponial = q > 5 ? exponial(q - 1, phi) : q - 1 < 3 ? q - 1 : q - 1 == 3 ? 9 : 0x40000;
		long o = q < 5 ? q == 4 ? 9 : q - 1 : 42;  
		long result = fastExp(q, o, m);
		if (q >= 5) result *= fastExp(q, ((exponial - o) % phi + phi) % phi, m); 
		return result % m;
	}
	
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		System.out.println(exponial(in.nextInt(), in.nextInt()));
		in.close();
	}
}
