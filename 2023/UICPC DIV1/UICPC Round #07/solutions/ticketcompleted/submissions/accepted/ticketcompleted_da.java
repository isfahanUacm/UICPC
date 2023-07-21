import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.Scanner;

public class ticketcompleted_da {

    private int[] sets, h;

    private void union(int s1, int s2) {
        if (h[s1] < h[s2]) {
            sets[s1] = s2;
        } else {
            sets[s2] = s1;
            if (h[s1] == h[s2]) {
                h[s1]++;
            }
        }
    }

    private int find(int index) {
        if (sets[index] == index) {
            return index;
        }
        return sets[index] = find(sets[index]);
    }

    private void work() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = sc.nextInt();
        int m = sc.nextInt();
        sets = new int[n];
        h = new int[n];
        for (int i = 0; i < n; i++) sets[i] = i;
        while (m-- > 0) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            int s1 = find(u);
            int s2 = find(v);
            if(s1 != s2) union(s1, s2);
        }

        int[] sz = new int[n];
        for (int i = 0; i < n; i++) {
            sz[find(i)]++;
        }

        long num = 0;
        for (int i = 0; i < n; i++) {
            long s = sz[i] * (sz[i] - 1L) / 2;
            num += s;
        }

        long den = n * (n - 1L) / 2;
        System.out.printf("%.12f\n", 1.0 * num / den);
    }

    public static void main(String[] args) {
        new ticketcompleted_da().work();
    }
}
