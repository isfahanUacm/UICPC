import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class traderoutes_da {
    private static final int IN_BUFFER_SIZE = 1 << 16;
    private static final int OUT_BUFFER_SIZE = 1 << 16;
    private final byte[] input = new byte[IN_BUFFER_SIZE];
    private int ix = IN_BUFFER_SIZE;
    private int bytesRead = ix;
    private final byte[] output = new byte[OUT_BUFFER_SIZE];
    private int ox = 0;

    private void readMore() {
        try {
            bytesRead = System.in.read(input, 0, IN_BUFFER_SIZE);
            if (bytesRead <= 0)
                throw new RuntimeException();
            ix = 0;
        } catch (IOException e) {
            throw new RuntimeException();
        }
    }

    private void flushOut() {
        System.out.write(output, 0, ox);
        ox = 0;
    }

    private void append(char c) {
        if (ox == OUT_BUFFER_SIZE)
            flushOut();
        output[ox++] = (byte) c;
    }

    private int nextInt() {
        skipSpaces();
        int ret = 0;
        if (ix == bytesRead) {
            readMore();
        }
        int sign = 1;
        if (input[ix] == '-') {
            sign = -1;
            ix++;
        }
        while (true) {
            if (ix == bytesRead) {
                try {
                    readMore();
                } catch (RuntimeException e) {
                    return ret;
                }
            }
            if (input[ix] < '0') {
                break;
            }
            ret *= 10;
            ret += input[ix++] - '0';
        }
        return sign * ret;
    }

    private void skipSpaces() {
        while (true) {
            if (ix == bytesRead) {
                readMore();
            }
            if (input[ix] > ' ')
                break;
            ix++;
        }
    }

    private final char[] nn = new char[32];

    private void printLong(long n) {
        if (n == 0) {
            append('0');
        } else {
            if (n < 0) {
                append('-');
                n = -n;
            }
            int kk = 0;
            while (n > 0) {
                nn[kk++] = (char) (n % 10 + '0');
                n /= 10;
            }
            for (int i = kk - 1; i >= 0; i--) {
                append(nn[i]);
            }
        }
    }

    static class Trade implements Comparable<Trade> {
        int k, value;

        Trade(int value, int k) {
            this.k = k;
            this.value = value;
        }

        @Override
        public int compareTo(Trade o) {
            if (value < o.value) return -1;
            if (value > o.value) return 1;
            return k - o.k;
        }

        public String toString() {
            return String.format("(%d, %d)", value, k);
        }
    }

    private void work() {
        int n = nextInt();
        p = new int[n];
        b = new int[n];
        v = new int[n];
        id = new int[n];
        keep = new PriorityQueue[n];
        keep[0] = new PriorityQueue<Trade>();

        for (int i = 1; i < n; i++) {
            id[i] = i;
            p[i] = nextInt() - 1;
            keep[i] = new PriorityQueue<Trade>();
        }

        for (int i = 0; i < n; i++) {
            b[i] = nextInt();
        }

        for (int i = 0; i < n; i++) {
            v[i] = nextInt();
        }

        for (int i = n - 1; i >= 0; --i) {
            keep[id[i]].add(new Trade(v[i], i));
            while (keep[id[i]].size() > b[i]) keep[id[i]].poll();

            if (i > 0) {
                if (keep[id[i]].size() > keep[id[p[i]]].size()) {
                    int t = id[i];
                    id[i] = id[p[i]];
                    id[p[i]] = t;
                }
                while (!keep[id[i]].isEmpty()) {
                    keep[id[p[i]]].add(keep[id[i]].poll());
                }
            }
        }

        long total = 0;
        Set<Integer> s = new TreeSet<>();
        while (!keep[id[0]].isEmpty()) {
            Trade trade = (Trade) keep[id[0]].poll();
            total += trade.value;
            s.add(trade.k + 1);
        }

        printLong(total);
        append('\n');
        printLong(s.size());
        for (int k : s) {
            append(' ');
            printLong(k);
        }

        append('\n');
        if (ox > 0) flushOut();
        System.out.close();
    }

    private int[] p, b, v, id;
    PriorityQueue[] keep;

    public static void main(String[] args) {
        new traderoutes_da().work();
    }
}
