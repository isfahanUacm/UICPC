/*
 * Alternative solution for Airport.
 *
 * This solution converts the input into a directed graph as follows:
 * Create nodes for points A and B.
 * Create nodes for the start and end of every conveyor.
 * For every ordered pair of nodes (P, Q), find the shortest possible route
 * from P to Q via at most one conveyor. Create a directed edge from P to Q,
 * labeled with the cost of the shortest route.
 *
 * This graph has (2*N+2) nodes and O(N^2) edges. The final solution is
 * the shortest path from node A to node B within the graph. This path
 * is found in time O(N^3) using Floyd-Warshall.
 *
 * Time complexity O( N**3 ).
 * This is slower than optimal but should still be easily fast enough
 * to solve the problem.
 */

// @EXPECTED_RESULTS@: CORRECT

import java.io.*;
import java.util.*;

public class AirportJoris
{

    public static class Conveyor {
        double x1, y1, x2, y2;
    }

    // Calculate distance to conveyor under 60-degree angle.
    public static void pointToLine(double px, double py, Conveyor cv, int fw,
                                   double[] q)
    {
        // Normalized vector in direction of conveyor.
        double dx = cv.x2 - cv.x1;
        double dy = cv.y2 - cv.y1;
        double cvlen = Math.sqrt(dx*dx + dy*dy);
        dx = dx / cvlen;
        dy = dy / cvlen;

        // Find distance to line (assuming 90-degree angle).
        double dd = Math.abs((cv.x1 - px) * dy - (cv.y1 - py) * dx);

        // Find 90-degree intersection relative to start of conveyor.
        double dq = (px - cv.x1) * dx + (py - cv.y1) * dy;

        // Shift to find 60-degree intersection.
        dq += fw * dd / Math.sqrt(3);

        // Set q[0] = distance from point to 60-degree intersection
        // Set q[1] = distance from start of conveyor to intersection
        if (dq < 0) {
            // 60-degree intersection would land before start of conveyor.
            // Go to start instead.
            q[0] = Math.sqrt((cv.x1 - px) * (cv.x1 - px) +
                             (cv.y1 - py) * (cv.y1 - py));
            q[1] = 0;
        } else if (dq > cvlen) {
            // 60-degree intersection would land past end of conveyor.
            // Go to end instead.
            q[0] = Math.sqrt((cv.x2 - px) * (cv.x2 - px) +
                             (cv.y2 - py) * (cv.y2 - py));
            q[1] = cvlen;
        } else {
            // 60-degree intersection is on conveyor. Use it.
            // Calculate distance from point to 60-degree intersection.
            q[0] = dd * 2.0 / Math.sqrt(3);
            q[1] = dq;
        }
    }

    public static double solve(double ax, double ay, double bx, double by,
                               Conveyor[] conveyors)
    {
        int n = conveyors.length;

        // Create list of points (A, B, conveyor starts and ends).
        int k = 2*n + 2;
        double[] px = new double[k];
        double[] py = new double[k];
        px[0] = ax; py[0] = ay;
        px[1] = bx; py[1] = by;
        for (int i = 0; i < n; i++) {
            px[2*i+2] = conveyors[i].x1;
            py[2*i+2] = conveyors[i].y1;
            px[2*i+3] = conveyors[i].x2;
            py[2*i+3] = conveyors[i].y2;
        }

        // Create table of point-to-point distances.
        double[][] dist = new double[k][k];

        // Fill table with straight over-the-floor distances.
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                double dx = px[j] - px[i];
                double dy = py[j] - py[i];
                dist[i][j] = Math.sqrt(dx*dx + dy*dy);
            }
        }

        // Calculate distance-via-conveyor.
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                for (int t = 0; t < n; t++) {
                    double[] q1 = new double[2];
                    double[] q2 = new double[2];
                    pointToLine(px[i], py[i], conveyors[t], 1, q1);
                    pointToLine(px[j], py[j], conveyors[t], -1, q2);
                    if (q1[1] < q2[1]) {
                        double d = q1[0] + 0.5 * (q2[1] - q1[1]) + q2[0];
                        if (d < dist[i][j]) {
                            dist[i][j] = d;
                        }
                    }
                }
            }
        }

        // Find all-pairs shortest paths with Floyd-Warshall.
        for (int t = 0; t < k; t++) {
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                    if (dist[i][j] > dist[i][t] + dist[t][j]) {
                        dist[i][j] = dist[i][t] + dist[t][j];
                    }
                }
            }
        }

        // Return distance from A to B.
        return dist[0][1];
    }

    public static void main(String[] args)
    {
        try {
            BufferedReader ir = new BufferedReader(
                                  new InputStreamReader(System.in));

            // Read points A and B.
            String s = ir.readLine();
            String[] w = s.split(" ");
            assert(w.length == 4);
            double ax = Double.parseDouble(w[0]);
            double ay = Double.parseDouble(w[1]);
            double bx = Double.parseDouble(w[2]);
            double by = Double.parseDouble(w[3]);
            assert(ax >= 0 && ax <= 1000);
            assert(ay >= 0 && ay <= 1000);
            assert(bx >= 0 && bx <= 1000);
            assert(by >= 0 && by <= 1000);

            // Read number of conveyors.
            s = ir.readLine();
            w = s.split(" ");
            assert(w.length == 1);
            int n = Integer.parseInt(w[0]);
            assert(n >= 0 && n <= 100);

            // Read conveyor locations.
            Conveyor[] conveyors = new Conveyor[n];
            for (int i = 0; i < n; i++) {
                s = ir.readLine();
                w = s.split(" ");
                assert(w.length == 4);
                conveyors[i] = new Conveyor();
                conveyors[i].x1 = Double.parseDouble(w[0]);
                conveyors[i].y1 = Double.parseDouble(w[1]);
                conveyors[i].x2 = Double.parseDouble(w[2]);
                conveyors[i].y2 = Double.parseDouble(w[3]);
            }

            // Solve problem.
            double ans = solve(ax, ay, bx, by, conveyors);

            // Write output.
            System.out.println(ans);

        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

}

