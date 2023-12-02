import java.util.Scanner;

public class Jimmy {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(), m = scanner.nextInt(), k = scanner.nextInt();
        System.out.println(solve(n, m, k));
    }

    private static long solve(long n, long m, long k) {
        long most = 0;
        long start = Math.max(0, (n-(k-1)*m) / k);
        long stop = n / k;
        System.err.println("start = " + start);
        System.err.println("stop  = " + stop);

        for (long maxShots = start; maxShots <= stop; maxShots++) {
            long nleft = n - maxShots * k;
            if (nleft > (k-1)*m) continue;
            if (nleft < 0) continue;

            long base = nleft / m;
            long extra = nleft % m;

            long dd = base*(m-extra)*(m-extra+1)/2;
            dd += base*(m-extra) * extra;
            dd += (base+1)*extra*(extra+1)/2;
            dd += base*(m-extra)*maxShots;
            dd += (base+1)*extra*maxShots;
            dd += k*maxShots*(maxShots+1)/2;

            most = Math.max(most, dd);
        }
        return most;
    }
}
