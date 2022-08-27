import java.util.*;
import java.lang.*;
import java.io.*;

// complexity: O(n sqrt n)

class Slow {
    
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

    class range_agg {
        int[] t;
        int[] gap;
        int[] sum_agg;
        int[] min_agg;
        int[] min_up;
        int n;
        int k;
        int size = 0;

        public range_agg(int k) {
            n = k*k;
            this.k = k;
            t = new int[n];
            gap = new int[n];
            Arrays.fill(gap, Integer.MAX_VALUE);
            sum_agg = new int[k];
            min_agg = new int[k];
            Arrays.fill(min_agg, Integer.MAX_VALUE);
            min_up = new int[k];
        }
    
		void push_updates(int idx) {
			// push pending updates
			if (min_up[idx/k] != 0) {
				for (int i = (idx/k)*k; i < (idx/k+1)*k; ++i) {
					gap[i] += min_up[idx/k];
				}
				min_up[idx/k] = 0;
			}

		}

		void add(int idx, int t_i, int gap_i) {
			push_updates(idx);

			// update index and aggregates
			++size;
			t[idx] = t_i;
			gap[idx] = gap_i;
			sum_agg[idx/k] += t_i;
			min_agg[idx/k] = Math.min(min_agg[idx/k], gap_i);
		}

		void suffix_update(int start, int gap_i) {
			push_updates(start);
			
			// update gap[i] and aggregate from start to multiple of k
			for (int i = start; i < (start/k+1)*k; ++i) {
				gap[i] += gap_i;
				// this last part only works because gap_i wiint always be negative
				min_agg[start/k] = Math.min(min_agg[start/k], gap[i]);
			}

			// update aggregates beyond this point and child update status
			for (int i = start/k+1; i < k; ++i) {
				min_up[i] += gap_i;
				min_agg[i] += gap_i;
			}
		}

		// returns sum from 0 to idx, inclusive
		int prefix_sum(int idx) {
			int sum = 0;
			for (int i = 0; i < idx/k; ++i) {
				sum += sum_agg[i];
			}

			for (int i = (idx/k)*k; i <= idx; ++i) {
				sum += t[i];
			}
			return sum;
		}

		// returns min from idx to end, inclusive
		int suffix_min(int idx) {
			push_updates(idx);

			int ans = Integer.MAX_VALUE;
			for (int i = idx; i < (idx/k+1)*k; ++i) {
				ans = Math.min(ans, gap[i]);
			}
			
			for (int i = idx/k+1; i < k; ++i) {
				ans = Math.min(ans, min_agg[i]);
			}
			return ans;
		}
    }
    
    void solve() throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(in.readLine());
        ArrayList<IntPair> t_sorted = new ArrayList<IntPair>();
        ArrayList<IntPair> h_sorted = new ArrayList<IntPair>();

        int[] t = new int[n];
        int[] h = new int[n];

        for (int i = 0; i < n; ++i) {
            String tokens[] = in.readLine().split(" ");
        
            t[i] = Integer.parseInt(tokens[0]);
            h[i] = Integer.parseInt(tokens[1]);

            t_sorted.add(new IntPair(t[i], i));
            h_sorted.add(new IntPair(h[i], i));
        }

        Collections.sort(t_sorted);
        Collections.sort(h_sorted);

        int[] i_to_h_idx = new int[n];
        for (int i = 0; i < n; ++i) {
            i_to_h_idx[h_sorted.get(i).s] = i;
        }
        
        range_agg ra = new range_agg(448);

        for (int i = 0; i < n; ++i) {
            int cur_t = t_sorted.get(i).f;
            int cur_h = h[t_sorted.get(i).s];
            int place = i_to_h_idx[t_sorted.get(i).s];

            int sum_before = ra.prefix_sum(place) + cur_t;
            int gap = cur_h - sum_before;

            if (gap >= 0) {
                if (ra.suffix_min(place) >= cur_t) {
                    ra.add(place, cur_t, gap);
                    ra.suffix_update(place+1, -cur_t);
                }
            }
        }

        System.out.println(ra.size);
	}
    
    public static void main(String[] args) throws Exception {
        (new Slow()).solve();
    }
}
