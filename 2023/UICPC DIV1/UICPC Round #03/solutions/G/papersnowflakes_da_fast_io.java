import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class papersnowflakes_da_fast_io {
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

    private long nextLong() {
        skipSpaces();
        long ret = 0;
        if (ix == bytesRead) {
            readMore();
        }
        long sign = 1L;
        if (input[ix] == '-') {
            sign = -1L;
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

    static class Event implements Comparable<Event> {
        long x;
        int t;

        Event(long x, int t) {
            this.x = x;
            this.t = t;
        }

        @Override
        public int compareTo(Event o) {
            int comp = Long.compare(x, o.x);
            if (comp == 0) comp = Integer.compare(t, o.t);
            return comp;
        }

        public String toString() {
            return String.format("{%d, %d}", x, t);
        }
    }

    private static final long INF = 1L << 62;

    private void work() {
        int n = (int) nextLong();
        int m = (int) nextLong();
        long l = nextLong();

        List<Event> events = new ArrayList<>();
        events.add(new Event(0, -2));
        int t = 1;
        long left = 0;
        long right = l;
        while (n-- > 0) {
            long x = nextLong();
            if (t == 1) {
                left = right - 2 * x;
                right -= x;
                events.add(new Event(right, 1));
            } else {
                right = left + 2 * x;
                left += x;
                events.add(new Event(left, 0));
            }

            t = 1 - t;
        }

        if (t == 0) {
            events.add(new Event(left, -2));
        } else {
            events.add(new Event(right, -1));
        }

        while (m-- > 0) {
            events.add(new Event(nextLong(), 2));
        }

        Collections.sort(events);
        // System.err.println(events);

        long total = 0;
        int cnt = 0;
        long prev = Long.MIN_VALUE;
        long rem = l;
        for (Event e : events) {
            if (prev > Long.MIN_VALUE) {
                total += cnt * (e.x - prev);
            }

            switch (e.t) {
                case -2: // loose start
                    cnt++;
                    break;
                case -1: // loose end
                    cnt--;
                    break;
                case 0: // start
                    cnt += 2;
                    break;
                case 1: // end
                    cnt -= 2;
                    break;
                case 2: // cut
                    printLong(total);
                    append(' ');
                    rem -= total;
                    total = 0;
                    break;
            }

            prev = e.x;
        }

        printLong(rem);
        append('\n');
        if (ox > 0) flushOut();
        System.out.close();
    }

    public static void main(String[] args) {
        new papersnowflakes_da_fast_io().work();
    }
}
