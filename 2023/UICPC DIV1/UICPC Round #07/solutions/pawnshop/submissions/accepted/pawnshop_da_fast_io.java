import java.io.IOException;
import java.util.*;

public class pawnshop_da_fast_io {
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

    private void printInt(int n) {
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

    static class Item {
        int value, count;

        Item(int value, int count) {
            this.value = value;
            this.count = count;
        }
    }

    private int m;
    private final int[] pos = new int[300010];
    private final Item[] pq = new Item[300010];
    Map<Integer, Integer> idxMap;

    private void work() {
        Set<Integer> values = new HashSet<>();
        int n = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = nextInt();
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = nextInt();
            values.add(b[i]);
        }

        idxMap = new HashMap<>();
        m = 0;
        for (Integer i : values) {
            idxMap.put(i, m);
            pq[m] = new Item(i, 0);
            pos[m] = m++;
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            printInt(b[i]);
            append(' ');
            if (a[i] != b[i]) {
                update(a[i], 1);
                update(b[i], -1);
            }

            if (i < n - 1 && pq[0].count == 0){
                append('#');
                append(' ');
            }
        }

        append('\n');
        if (ox > 0) flushOut();
        System.out.close();
    }

    private void update(int value, int add) {
        int k = pos[idxMap.get(value)];
        int oldCount = pq[k].count;
        int newCount = (pq[k].count = oldCount + add);

        if (oldCount == 0) {
            // go up
            int p = k;
            while (p > 0) {
                p = (p - 1) / 2;
                if (pq[p].count != 0) break;
                swap(p, k);
                k = p;
            }
        }

        if (newCount == 0) {
            // go down
            int p = k;
            while (p * 2 + 1 < m) {
                p = p * 2 + 1;
                if (pq[p].count == 0 && (p + 1 == m || pq[++p].count == 0)) break;
                swap(p, k);
                k = p;
            }
        }

        // we don't care if there was no zero involved
    }

    private void swap(int p, int k) {
        int pk = idxMap.get(pq[p].value);
        int kk = idxMap.get(pq[k].value);
        Item ti = pq[p];
        pq[p] = pq[k];
        pq[k] = ti;
        int t = pos[pk];
        pos[pk] = pos[kk];
        pos[kk] = t;
    }

    public static void main(String[] args) {
        new pawnshop_da_fast_io().work();
    }
}
