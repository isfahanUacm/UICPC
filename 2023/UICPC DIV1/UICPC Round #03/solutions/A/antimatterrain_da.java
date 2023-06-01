import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

/**
 * Ported antimatterrain_zf.cpp, nothing original here
 */
public class antimatterrain_da {

    static class Thing implements Comparable<Thing> {
        final int i, x1, x2, y; // x2 == -INF indicates a point

        Thing(int i, int x1, int x2, int y) {
            this.i = i;
            this.x1 = x1;
            this.x2 = x2;
            this.y = y;
        }

        @Override
        public int compareTo(Thing o) {
            if(y < o.y) return -1;
	    if (y == o.y) return 0;
            return 1;
        }
    }

    private static final int L = 19;
    private static final int MAXN = 1 << L;
    private static final int INF = (int) (1 << 30);

    private static final Thing NONE = new Thing(-1, 0, 0, INF);

    private Map<Integer, Integer> x_to_i;
    private Stack<Thing>[] st;
    private Thing[] rmq;
    private int[] die;

    // update the object with compressed x-position i to "obj"
    private void update(int i, Thing obj, int lq, int hq, int node) {
        if (lq + 1 == hq) {
            rmq[node] = obj;
            return;
        }

        int mid = (lq + hq) >> 1, left = (node << 1) + 1, right = (node << 1) + 2;

        if (i < mid) update(i, obj, lq, mid, left);
        else update(i, obj, mid, hq, right);

        rmq[node] = rmq[left].compareTo(rmq[right]) < 0 ? rmq[left] : rmq[right];
    }

    Thing query(int lo, int hi, int lq, int hq, int node) {
        if (hi <= lq || hq <= lo) return NONE;
        if (lo <= lq && hq <= hi) return rmq[node];

        int mid = (lq + hq) >> 1;
        Thing obj_l = query(lo, hi, lq, mid, (node << 1) + 1);
        Thing obj_r = query(lo, hi, mid, hq, (node << 1) + 2);

        return obj_l.compareTo(obj_r) < 0 ? obj_l : obj_r;
    }

    void addPoint(Thing obj) {
        int i = x_to_i.get(obj.x1);
        st[i].push(obj);
        update(i, obj, 0, MAXN, 0);
    }

    void processBarrier(Thing obj) {
        int il = x_to_i.get(obj.x1), ih = x_to_i.get(obj.x2) + 1;

        Thing orig = query(il, ih, 0, MAXN, 0);
        if (orig.i == NONE.i) return;

        // continue killing off points as long as there is one in this range
        // with the same x-value as the first point to hit the wall
        for (Thing hit = orig; hit.y == orig.y; hit = query(il, ih, 0, MAXN, 0)) {
            // record this point hit a wall
            die[hit.i] = obj.y;

            int i = x_to_i.get(hit.x1);
            assert (st[i].size() > 0 && st[i].peek().i != -1);
            st[i].pop();

            // update the rmq data for the next point with y-coordinate i
            update(i, st[i].peek(), 0, MAXN, 0);
        }

    }

    private void work() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = sc.nextInt();
        int m = sc.nextInt();

        Thing[] obj = new Thing[n + m];
        die = new int[n];

        for (int i = 0; i < n; ++i) {
            int x1 = sc.nextInt();
            int y = sc.nextInt();
            obj[i] = new Thing(i, x1, -INF, y);
        }

        for (int i = n; i < m + n; ++i) {
            int x1 = sc.nextInt();
            int x2 = sc.nextInt();
            int y = sc.nextInt();
            obj[i] = new Thing(0, x1, x2, y);
        }

        Arrays.sort(obj);

        // determine the distinct x-values (compression)
        Set<Integer> xvals = new TreeSet<>();
        x_to_i = new HashMap<>();
        for (Thing o : obj) {
            xvals.add(o.x1);
            if (o.x2 != -INF) xvals.add(o.x2);
        }
        for (int x : xvals){
            int sz = x_to_i.size();
            x_to_i.put(x, sz);
        }
        assert (xvals.size() <= MAXN);

        // initialize RMQ and stack
        rmq = new Thing[2 * MAXN];
        Arrays.fill(rmq, NONE);

        st = new Stack[xvals.size()];
        for (int i = 0; i < st.length; i++) {
            st[i] = new Stack<>();
            st[i].push(NONE);
        }

        // finally do the sweep
        for (int i = n + m - 1; i >= 0; --i) {
            if (obj[i].x2 == -INF) addPoint(obj[i]);
            else processBarrier(obj[i]);
        }

        for (int i = 0; i < n; i++) System.out.println(die[i]);
    }

    public static void main(String[] args) {
        new antimatterrain_da().work();
    }
}
