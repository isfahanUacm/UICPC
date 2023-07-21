import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

// Converted Darcy's solution because I ran out of time
public class snowballfight_da {

    private static class Pair {
        int x;
        long s;

        Pair(int x, long s) {
            this.x = x;
            this.s = s;
        }
    }
    long[] take_step(long[] X) {
        long a = X[0], b = X[1], c = X[2];

        long A = 0, B = 0, C = 0;
        if (b >= c) B++;
        else C++;
        if (c >= a) C++;
        else A++;
        if (a >= b) A++;
        else B++;

        return new long[]{a - A, b - B, c - C};
    }

    Pair f(long[] A) {
        long a = A[0], b = A[1], c = A[2];
        Arrays.sort(A);
        long lo = A[0], mid = A[1], hi = A[2];

        if (lo == 0) return new Pair(a == hi ? 0 : b == hi ? 1 : 2, hi - mid);
        if (a == b && b == c) return new Pair(-1, 0);

        if (mid < 50) return f(take_step(new long[]{a, b, c}));

        if (a != b && b != c && a != c) {
            long steps = Math.min(mid - lo, hi - mid);
            return f(new long[]{a - steps * ((a == hi ? 1 : 0) * 2 + (a == mid ? 1 : 0)),
                    b - steps * ((b == hi ? 1 : 0) * 2 + (b == mid ? 1 : 0)),
                    c - steps * ((c == hi ? 1 : 0) * 2 + (c == mid ? 1 : 0))
            });
        }

        if (lo == mid) { // lo lo hi -> lo-1 lo hi-2 -> lo-1 lo-1 hi-4
            long two_steps = Math.min(lo - 1, (hi - lo) / 3); // ZERO
            if (two_steps != 0)
                return f(new long[]{a - two_steps * ((a == hi ? 1 : 0) * 4 + (a == mid ? 1 : 0)),
                        b - two_steps * ((b == hi ? 1 : 0) * 4 + (b == mid ? 1 : 0)),
                        c - two_steps * ((c == hi ? 1 : 0) * 4 + (c == mid ? 1 : 0))
                });

            if (hi == lo + 2) return f(take_step(new long[]{a, b, c}));

            // lo lo lo+1 -> lo-1 lo lo-1 -> lo-1 lo-2 lo-2 -> lo-3 lo-3 lo-2
            lo %= 3;
            lo += 3;
            return f(new long[]{lo + (a == hi ? 1 : 0), lo + (b == hi ? 1 : 0), lo + (c == hi ? 1 : 0)});
        }

        // lo hi hi -> lo hi-1 hi-2 -> lo hi-3 hi-3
        long two_steps = (hi - lo) / 3;
        if (two_steps > 0)
            return f(new long[]{a - two_steps * ((a == hi ? 1 : 0) * 3),
                    b - two_steps * ((b == hi ? 1 : 0) * 3),
                    c - two_steps * ((c == hi ? 1 : 0) * 3)
            });

        // lo lo+2 lo+2 -> lo lo lo+1
        if (hi == lo + 2) return f(take_step(new long[]{a, b, c}));

        // lo lo+1 lo+1
        lo %= 3;
        lo += 3;
        return f(new long[]{lo + (a == hi ? 1 : 0), lo + (b == hi ? 1 : 0), lo + (c == hi ? 1 : 0)});
    }

    private void work() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        long[] X = new long[]{sc.nextLong(), sc.nextLong(), sc.nextLong()};

        Pair p = f(X);

        if (p.s == 0) System.out.println("Rubble!");
        else System.out.printf("%c %d\n", (char) ('A' + p.x), p.s);
    }

    public static void main(String[] args) {
        new snowballfight_da().work();
    }
}
