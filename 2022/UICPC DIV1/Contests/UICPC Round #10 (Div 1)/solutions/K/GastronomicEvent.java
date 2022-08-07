import java.util.Scanner;
import java.util.Vector;
import java.util.BitSet;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class GastronomicEvent {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in));
 
        int n = Integer.parseInt(br.readLine());

        int[] P = new int[n+1];
        int[] V = new int[n+1];
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 2; i <= n; i++) P[i] = Integer.parseInt(st.nextToken());
        
        for (int v = n; v >= 1; v--) {
            V[v]++;
            V[P[v]] += V[v];
        }
        int centroid = 1;
        for (int v = 2; v <= n; v++) if (2*V[v] >= n) centroid = v;

        int bef = 0;
        int v = centroid;
        while (v != 0) {
            int tmp = bef;
            bef = V[v];
            V[v] = tmp;
            V[v] = n - V[v];
            v = P[v];
        }

        int[] cnt = new int[n];
        if (P[centroid] != 0) cnt[V[P[centroid]]]++;
        for (int u = 2; u <= n; u++) if (P[u] == centroid) cnt[V[u]]++;

        Vector<Integer> S = new Vector<>();
        for (int x = 1; x < n; x++) {
            while (cnt[x] >= 3) {
                cnt[2*x]++;
                cnt[x] -= 2;
            }
            for (int i = 0; i < cnt[x]; i++) S.add(x);
        }

        BitSet M = new BitSet(n);
        M.set(n-1);
        for (int val: S) M.or(M.get(val, n));

        long res = 0;
        for (int i = n/2; i >= 0; --i) {
            if (M.get(i)) {
                res = ((long)i) * (n-1-i);
                break;
            }
        }
        for (int u = 1; u <= n; u++) res += V[u];
        
        System.out.println(res);
    }
}
