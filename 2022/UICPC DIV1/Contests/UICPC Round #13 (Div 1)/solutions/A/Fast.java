import java.util.*;
import java.lang.*;
import java.io.*;

// complexity: actually O(n log n)

class Fast {
    
    class IntPair implements Comparable<IntPair> {
        int f;
        int s;

        public IntPair(int f, int s) {
            this.f = f;
            this.s = s;
        }

        public int compareTo(IntPair other) {
            if (this.f == other.f) {
                if (this.s == other.s) {
                    return this.toString().compareTo(other.toString());
                }
                else
                    return this.s - other.s;
            }
            else
                return this.f - other.f;
        }
    }
    
    void solve() throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(in.readLine());
        ArrayList<IntPair> stores = new ArrayList<IntPair>();

        for (int i = 0; i < n; ++i) {
            String tokens[] = in.readLine().split(" ");
            stores.add(new IntPair(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1])));
        }

        Collections.sort(stores);
        TreeSet<IntPair> taken = new TreeSet<IntPair>();
        taken.add(new IntPair(0, 0));

        int added = 0;
        for (IntPair store : stores) {
            IntPair greater = taken.ceiling(new IntPair(store.s, Integer.MAX_VALUE));
            if (greater != null) {
                int greater_start = greater.f - greater.s;
                store.s = Math.min(store.s, greater_start);  //need to end before the thing that starts after me
            }

            int sum_ti = 0;
            while (true) {
                IntPair before = taken.floor(new IntPair(store.s, Integer.MAX_VALUE));
                
                // success
                if (sum_ti + store.f <= store.s - before.f) {
                    taken.add(new IntPair(store.s, sum_ti + store.f));
                    ++added;
                    break;
                }

                // fail
                if (before.f == 0) {
                    taken.add(new IntPair(store.s, sum_ti));
                    break;
                }

                sum_ti += before.s;
                taken.remove(before);
            }
        }

        System.out.println(added);
    }
    
    public static void main(String[] args) throws Exception {
        (new Fast()).solve();
    }
}
