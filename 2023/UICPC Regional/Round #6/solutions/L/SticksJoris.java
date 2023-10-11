/*
 * Solution to Stick Triangles.
 *
 * Try all sticks, then find a stick which is shorter and one which is
 * longer.
 *
 * Time complexity O( N**2 ).
 *
 * This is slower than optimal, but it should still be easily fast enough.
 */

import java.io.*;
import java.util.*;

public class SticksJoris
{

    public static void main(String[] args)
    {
        try {
            BufferedReader ir = new BufferedReader(
                                  new InputStreamReader(System.in));

            // Read input.
            String s = ir.readLine();
            String[] w = s.split(" ");
            assert(w.length == 1);
            int n = Integer.parseInt(w[0]);
            assert(n >= 3 && n <= 20000);

            s = ir.readLine();
            w = s.split(" ");
            assert(w.length == n);
            long[] sticks = new long[n];
            for (int i = 0; i < n; i++) {
                sticks[i] = Long.parseLong(w[i]);
                assert(sticks[i] > 0 && sticks[i] < (1L<<60));
            }

            boolean possible = false;

            // Choose the middle stick.
            for (int b = 0; b < n; b++) {

                long bsize = sticks[b];

                // Find a stick of maximum length but not longer than B.
                int a = -1;
                long asize = 0;
                for (int i = 0; i < n; i++) {
                    if (i != b && sticks[i] <= bsize && sticks[i] > asize) {
                        a = i;
                        asize = sticks[a];
                    }
                }

                if (a < 0) {
                    continue;
                }

                // Find a stick of minimum length but not shorter than B.
                int c = -1;
                long csize = Long.MAX_VALUE;
                for (int i = 0; i < n; i++) {
                    if (i != a && i != b &&
                        sticks[i] >= bsize && sticks[i] < csize) {
                        c = i;
                        csize = sticks[c];
                    }
                }

                if (c < 0) {
                    continue;
                }

                if (asize + bsize > csize) {
                    possible = true;
                    break;
                }

            }

            // Write output.
            System.out.println(possible ? "possible" : "impossible");

        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

}

