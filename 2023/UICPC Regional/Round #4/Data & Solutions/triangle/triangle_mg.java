/* Sample solution to NCPC 2008 J: Just a few more triangles
 * by Mikael Goldmann
 */

import java.util.*;

public class triangle_mg {
    static class Factor {
	long p;
	int e;
	Factor(long p, int e) {
	    this.p = p; this.e = e;
	}
    }

    public static void main(String[] s) {
	/* Use Chinese remainder thm to count
	 * abc = #{a,b,c | a^2 + b^2 = c^2 mod n}
	 * Then compute
	 * a0 = #{a,c | a^2 = c^2} = #{b,c | b^2 = c^2 mod n}
	 * c0 = #{a,b | a^2 + b^2 = 0 mod n}
	 * sq[x] = #{a | a^2 = x mod n}
	 * all non-zero solutions nz = abc - (2*a0 + c0 -3*sq[0] + 1)
	 *   2*a0+c0 [at least one 0] - 3*sq[0] [at least two 0:s]
	 *   + 1 [a=b=c=0]
	 * Let ac = #{a,c | 2*a^2 = c^2 mod n, except where a=0 or c=0}
	 * result is (all_non_zero-(ac-1))/2 + ac  (remove solutions where b<a)
	 */
	long n = new Scanner(System.in).nextInt();
	long abc = 1;
	for (Iterator<Factor> fi = factor(n).iterator(); fi.hasNext() ; )
	    abc *= nsol(fi.next());
	//System.err.println("abc=" +abc);
	
	int[] sq = new int[(int)n]; // sq[X] = #{a | a^2 = X mod n}
	for (long i = 0; i < n; ++i)
	    ++sq[(int)((i*i)%n)];

	int a0 = 0;
	for (int i = 0; i < n; ++i)
	    a0 += sq[i]*sq[i];
	//System.err.println("a0=" + a0);
	
	int c0 = 0;
	for (long a = 0; a < n; ++a)
	    c0 += sq[(int)((n-a)*a % n)];
	//System.err.println("c0=" + c0);

	long nz = abc - (2*a0 + c0 -3*sq[0] + 1);
	//System.err.println("nz=" + nz);

	int ac = 0;
	for (long a = 1; a < n; ++a) {
	    long a2 = (2*a*a) % n;
	    if (a2 == 0) ac += sq[0]-1;
	    else ac += sq[(int)a2];
	}
	//System.err.println("ac=" + ac);
	System.out.println((nz-ac)/2 + ac);
    }

    static long nsol(Factor f) {
	long p = f.p, e = f.e; // p is a prime
	//System.err.println(p + " " + e);
	
	long pe = 1;
	for (int i=0; i < e; ++i)
	    pe *= p;

	int[] sq = new int[(int)pe]; // sq[X] = #{a | a^2 = X mod p^e}
	for (long a = 0; a < pe; ++a)
	    ++sq[(int)((a*a)%pe)];
	long pr = 1;
	long ns = 0;
	/* For each a, count number of roots to a^2 + (p^r)^2 = X
	 * and multiply by number of b1 (sgd(b1,pe)==1)
	 * that yield distinct b1*p^r mod p^e
	 */
	for (int r = 0; r < e; ++r, pr *= p){
	    //System.err.println("r= " + r);
	    
	    for (long a = 0; a < pe; ++a) {
		ns += sq[(int)((a*a + pr*pr) % pe)] * ((pe-pe/p)/pr);
		//System.err.println("  a=" + a + "  ns= " + ns);
	    }
	}
	

	// all solutions where b == 0
	for (long a = 0; a < pe; ++a){
	    ns += sq[(int)((a*a)%pe)];
	}
	//System.err.println("final ns=" + ns);
	
	return ns;
    }

    static ArrayList<Factor> factor(long n) {
	ArrayList<Factor> f = new ArrayList<Factor>();
	for (long p = 2; p*p <= n; ++p) {
	    int e;
	    for (e = 0; n % p == 0; n /= p)
		++e;
	    if (e > 0)
		f.add(new Factor(p,e));
	}
	if (n > 1)
	    f.add(new Factor(n,1));
	return f;
    }
}
