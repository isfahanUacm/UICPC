import java.io.IOException;
import java.util.Map;
import java.util.TreeMap;

public class distance_da_fast_io {

    static class Point implements Comparable<Point> {
        long x, cnt, totLeft, totRight;

        Point(long x, int cnt) {
            this.x = x;
            this.cnt = cnt;
        }

        @Override
        public int compareTo(Point o) {
            return Long.compare(x, o.x);
        }
    }

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

    private void work() {

        int n = nextInt();
        long[] x = new long[n];
        long[] y = new long[n];
        for (int i = 0; i < n; i++) {
            x[i] = nextInt();
            y[i] = nextInt();
        }

        long res = solve(x) + solve(y);
        printLong(res);
        append('\n');
        if (ox > 0) flushOut();
        System.out.close();
    }

    private long solve(long[] a) {
        TreeMap<Long, Integer> ps = new TreeMap<>();
        for (long x : a) {
            if (!ps.containsKey(x)) ps.put(x, 0);
            ps.put(x, ps.get(x) + 1);
        }

        Point[] p = new Point[ps.size()];
        int k = 0;
        for (Map.Entry<Long, Integer> e : ps.entrySet()) {
            p[k++] = new Point(e.getKey(), e.getValue());
        }
        p[0].totLeft = p[0].cnt;
        for (int i = 1; i < p.length; i++) p[i].totLeft = p[i].cnt + p[i - 1].totLeft;

        p[p.length - 1].totRight = p[p.length - 1].cnt;
        for (int i = p.length - 2; i >= 0; i--) p[i].totRight = p[i].cnt + p[i + 1].totRight;

        long ret = 0;
        for (int i = 0; i < p.length - 1; i++) {
            long len = p[i + 1].x - p[i].x;
            ret += len * p[i].totLeft * p[i + 1].totRight;
        }

        return ret;
    }

    public static void main(String[] args) {
        new distance_da_fast_io().work();
    }
}
