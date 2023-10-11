/*
 * Solution to Programming Tutors.
 *
 * Just weighted bipartite matching, except we don't look for the maximum
 * possible sum of edge weights but for the least possible maximum edge weight.
 *
 * Time complexity O( N**3 * log(N) ).
 */

import java.io.*;
import java.util.*;

public class ProgJoris
{

    // Find cheapest path from Q to unmatched tutor.
    public static int[] findAugmentingPath(int[][] distance,
                                           int[][] mate,
                                           int q)
    {

        // Helper class to represent the cost of reaching a tutor.
        class PartialPath implements Comparable<PartialPath>
        {
            public int k; // tutor index
            public int d; // largest distance so far

            public PartialPath(int k, int d)
            {
                this.k = k;
                this.d = d;
            }

            public int compareTo(PartialPath o)
            {
                return d - o.d;
            }
        }

        int n = distance.length;

        // Queue of newly reached tutors.
        PriorityQueue<PartialPath> queue = new PriorityQueue<PartialPath>(n);

        int[] tutorFrom = new int[n];   // student to be matched with tutor
        int[] tutorDist = new int[n];   // max distance used to reach tutor

        // Start with direct edges from student Q to all tutors.
        for (int k = 0; k < n; k++) {
            tutorFrom[k] = q;
            tutorDist[k] = distance[q][k];
            queue.add(new PartialPath(k, tutorDist[k]));
        }

        // Explore graph.
        while (true) {

            assert (!queue.isEmpty());

            PartialPath p = queue.poll();
            if (p.d != tutorDist[p.k]) {
                // Obsolete entry for tutor; ignore it.
                continue;
            }

            if (mate[1][p.k] < 0) {
                // Reached an unmatched tutor.
                // Construct a backward path from this tutor to Q.
                ArrayList<Integer> rpath = new ArrayList<Integer>();
                rpath.add(p.k);
                int i = tutorFrom[p.k];
                rpath.add(i);
                while (i != q) {
                    assert (i < q);
                    int k = mate[0][i];
                    rpath.add(k);
                    i = tutorFrom[k];
                    rpath.add(i);
                }

                // Reverse to find path from Q to tutor.
                int[] path = new int[rpath.size()];
                for (i = 0; i < rpath.size(); i++) {
                    path[i] = rpath.get(rpath.size() - 1 - i);
                }

                // Return path from Q to tutor.
                return path;
            }

            // Consider canceling the existing link between tutor and student.
            // Consider alternative tutors for its old student.
            int i = mate[1][p.k];
            for (int k = 0; k < n; k++) {
                int d = Math.max(p.d, distance[i][k]);
                if (d < tutorDist[k]) {
                    // Found a cheaper path to this tutor.
                    tutorFrom[k] = i;
                    tutorDist[k] = d;
                    queue.add(new PartialPath(k, d));
                }
            }

        }
    }

    // Find bipartite matching with lowest maximum distance.
    public static int match(int[][] distance)
    {
        int n = distance.length;

        // mate[0][i] = index of tutor to which student i is matched
        // mate[1][k] = index of student to which tutor k is matched,
        //              or -1 if tutor is unmatched.
        int mate[][] = new int[2][n];

        // Mark all tutors as unmatched.
        for (int k = 0; k < n; k++) {
            mate[1][k] = -1;
        }

        // Largest distance used so-far.
        int ans = 0;

        // Match each student.
        for (int q = 0; q < n; q++) {

            // Match student Q using the shortest possible distance.
            int[] path = findAugmentingPath(distance, mate, q);

            // Path starts at student Q, then alternates between tutor
            // and student, and ends with an unmatched tutor.
            assert (path.length % 2 == 0);
            assert (path[0] == q);
            assert (mate[1][path[path.length-1]] == -1);

            // Modify matching according to augmenting path.
            for (int p = 0; p < path.length; p += 2) {
                mate[0][path[p]]   = path[p+1];
                mate[1][path[p+1]] = path[p];
                int d = distance[path[p]][path[p+1]];
                if (d > ans) {
                    ans = d;
                }
            }
        }

        return ans;
    }

    public static void main(String[] args)
    {
        try {
            BufferedReader ir = new BufferedReader(
                                  new InputStreamReader(System.in));

            // Read input.
            String s = ir.readLine();
            String[] w = s.split(" ");
            assert (w.length == 1);
            int n = Integer.parseInt(w[0]);
            assert (n >= 1 && n <= 100);

            int[][][] coords = new int[2][n][2];
            for (int t = 0; t <= 1; t++) {
                for (int i = 0; i < n; i++) {
                    s = ir.readLine();
                    w = s.split(" ");
                    assert (w.length == 2);
                    coords[t][i][0] = Integer.parseInt(w[0]);
                    coords[t][i][1] = Integer.parseInt(w[1]);
                    int lim = 100000000;
                    assert (coords[t][i][0] >= -lim && coords[t][i][0] <= lim);
                    assert (coords[t][i][1] >= -lim && coords[t][i][1] <= lim);
                }
            }

            // Calculate distance matrix.
            int[][] distance = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int k = 0; k < n; k++) {
                    int d = Math.abs(coords[0][i][0] - coords[1][k][0]) +
                            Math.abs(coords[0][i][1] - coords[1][k][1]);
                    distance[i][k] = d;
                }
            }

            // Find optimal matching.
            int ans = match(distance);

            // Write output.
            System.out.println(ans);

        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

}

