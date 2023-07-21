import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class rsamistake_da {

    private void work() {
        generatePrimes(1000000);

        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        long a = sc.nextLong();
        long b = sc.nextLong();

        Map<Long, Integer> aFactors = getPrimeFactors(a);
        Map<Long, Integer> bFactors = getPrimeFactors(b);


        mul(aFactors, bFactors);

        boolean square = false;
        for (int k : aFactors.values()) {
            if (k > 1) {
                square = true;
                break;
            }
        }

        String answer = "full";
        if (square) {
            answer = "no";
        } else if (aFactors.size() > 2 || sumValues(aFactors) != 2) {
            answer = "partial";
        }

        System.out.printf("%s credit\n", answer);
    }

    private int sumValues(Map<Long, Integer> m) {
        int s = 0;
        for (int v : m.values()) s += v;
        return s;
    }

    private void mul(Map<Long, Integer> aFactors, Map<Long, Integer> bFactors) {
        for (Map.Entry<Long, Integer> e : bFactors.entrySet()) {
            long p = e.getKey();
            if (!aFactors.containsKey(p)) {
                aFactors.put(p, 0);
            }

            aFactors.put(p, aFactors.get(p) + bFactors.get(p));
        }
    }

    private List<Long> primes;

    private void generatePrimes(int limit) {
        boolean[] isp = new boolean[limit];
        Arrays.fill(isp, true);
        for (int i = 2; i * i < limit; i++) {
            if (isp[i]) {
                for (int j = i * i; j * j < limit; j += i) {
                    isp[j] = false;
                }
            }
        }

        primes = new ArrayList<>();
        for (int i = 2; i < limit; i++) {
            if (isp[i]) {
                primes.add((long) i);
            }
        }
    }

    private Map<Long, Integer> getPrimeFactors(long n) {
        Map<Long, Integer> factors = new HashMap<>();
        for (long p : primes) {
            if (p * p > n) break;
            if (n % p == 0) {
                int k = 0;
                while (n % p == 0) {
                    k++;
                    n /= p;
                }

                factors.put(p, k);
            }
        }

        if (n > 1) {
            factors.put(n, 1);
        }

        return factors;
    }

    public static void main(String[] args) {
        new rsamistake_da().work();
    }
}
