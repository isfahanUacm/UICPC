import java.util.Scanner;
import java.util.Vector;
import java.util.BitSet;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.LinkedList;

public class Antennas {
    public static boolean is_reachable(int v, int u, int n, SegmentTree SL, SegmentTree SR, int[] p, int[] dist, Queue<Integer> q) {
        if (u < 0 || u >= n || (0 <= dist[u] && dist[u] < n)
                  || p[u] < Math.abs(u - v)) return false;
        dist[u] = dist[v] + 1;
        q.add(u);
        SR.update(u, -(1<<30));
        SL.update(u, -(1<<30));
        return true;
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in));
 
        int t = Integer.parseInt(br.readLine());

        for (int z = 0; z < t; z++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            a--;
            b--;

            int[] p = new int[n];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) p[i] = Integer.parseInt(st.nextToken());

            int[] p1 = new int[n];
            int[] p2 = new int[n];
            for (int i = 0; i < n; i++) {
                p1[i] = p[i] - i;
                p2[i] = p[i] + i;
            }
            SegmentTree SR = new SegmentTree(p1);
            SegmentTree SL = new SegmentTree(p2);
                        
            int[] dist = new int[n];
            for (int i = 0; i < n; i++) dist[i] = n;
            Queue<Integer> q = new LinkedList<Integer>();
                        
            dist[a] = -1;
            is_reachable(a, a, n, SL, SR, p, dist, q);
            
            while (!q.isEmpty()) {
                int v = q.remove();
                while (true) {
                    int u = SR.range_max(v, v + p[v]);
                    if (!is_reachable(v, u, n, SL, SR, p, dist, q)) break;
                }
                while (true) {
                    int u = SL.range_max(v - p[v], v);
                    if (!is_reachable(v, u, n, SL, SR, p, dist, q)) break;
                }
            }
            System.out.println(dist[b]);
        }
    }
}

class SegmentTree {
    int len;
    int[] a;
    int[] b;

    public void pull(int v) {
        if (a[2*v] > a[2*v+1]) {
            a[v] = a[2*v];
            b[v] = b[2*v];
        } else {
            a[v] = a[2*v+1];
            b[v] = b[2*v+1];
        }
    }
    
    public SegmentTree(int[] vals) {
        len = 1;
		while (len < vals.length) len *= 2;
        a = new int[2*len];
        b = new int[2*len];
        
        for (int i = len; i < 2*len; i++) {
            a[i] = -(1<<30);
            b[i] = i;
        }
        for (int i = 0; i < vals.length; i++) a[i + len] = vals[i];
        for (int i = len-1; i >= 1; i--) pull(i);
    }
    
    public void update(int i, int val) {
        i += len;
		a[i] = val;
		while (i != 1) {
			i >>= 1;
			pull(i);
        }
    }

    private int _range_max(int v, int a, int b, int l, int r) {
        if (b < l || r < a) return Math.max(l, 0) + len;
		if (l <= a && b <= r) return this.b[v];
		int m = (a + b) / 2;
        int p1 = _range_max(2*v, a, m, l, r);
        int p2 = _range_max(2*v+1, m+1, b, l, r);
        if (this.a[p1] > this.a[p2]) return p1;
        return p2;
    }

    public int range_max(int l, int r) {
        if (r < 0 || l >= len || r < l) return -1;
        return _range_max(1, 0, len-1, l, r) - len;
    }
}
