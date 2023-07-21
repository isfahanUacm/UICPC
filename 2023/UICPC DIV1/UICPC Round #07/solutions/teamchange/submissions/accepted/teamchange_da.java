import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

// Zac's Python solution
public class teamchange_da {
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

    private char[] nextString(int n) {
        char[] ret = new char[n];
        skipSpaces();
        for (int i = 0; i < n; i++) {
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
            ret[i] = (char) input[ix++];
        }

        return ret;
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
        n = nextInt();
        int r = nextInt();
        char[] team = nextString(n);
        char[] change = nextString(n);

        g = new int[2 * n + 2][2 * n + 2];
        int s = in(n), t = out(n);

        for (int i = 0; i < n; i++) {
            if (change[i] != '?') {
                if (team[i] == change[i]) {
                    addEdge(s, in(i), 2);
                } else {
                    addEdge(out(i), t, 2);
                }
            }

            addEdge(in(i), out(i), 1);
        }

        while (r-- > 0) {
            int u = nextInt() - 1;
            int v = nextInt() - 1;
            addEdge(out(u), in(v), 2);
            addEdge(out(v), in(u), 2);
        }

        int[] par = new int[2 * n + 2];
        Arrays.fill(par, -1);
        while (augment(s, -2, t, 1000000000, par) > 0) {
            Arrays.fill(par, -1);
        }

        for (int i = 0; i < n; i++) {
            if (par[out(i)] >= 0) {
                append(team[i]);
            } else if (par[in(i)] >= 0) {
                append('X');
            } else {
                append(team[i] == 'A' ? 'B' : 'A');
            }
        }

        append('\n');
        if (ox > 0) flushOut();
        System.out.close();
    }

    private int n;
    private int[][] g;

    private void addEdge(int u, int v, int c) {
        g[u][v] += c;
    }

    private int augment(int v, int pre, int t, int mn, int[] par) {
        if (v == t) return mn;
        if (par[v] >= 0) return 0;
        par[v] = pre;
        for (int w = 0; w < 2 * n + 2; w++) {
            if (g[v][w] != 0) {
                int nxt = augment(w, v, t, Math.min(mn, g[v][w]), par);
                if (nxt > 0) {
                    g[v][w] -= nxt;
                    g[w][v] += nxt;
                    return nxt;
                }
            }
        }

        return 0;
    }

    private int in(int v) {
        return 2 * v;
    }

    private int out(int v) {
        return 2 * v + 1;
    }

    public static void main(String[] args) {
        new teamchange_da().work();
    }
}
