/*
 * Solution for problem Endless Turning.
 *
 * Start at (X,Y) and trace the sequence of intersections until
 * we reach the first street for the second time.
 * Then resolve the current location.
 *
 * Time complexity O( R**2 ).
 */

import java.io.*;
import java.util.*;

public class TurnJoris
{

    public static final boolean DEBUG = false;

    public static class Street {
        String name;
        int x1, y1, x2, y2;
    }

    public static class Point {
        double x, y;
        Point(double x, double y) { this.x = x; this.y = y; }
    }

    // Return true if specified point is on specified street.
    public static boolean pointOnStreet(Street st, int x, int y)
    {
        long dx = st.x2 - st.x1;
        long dy = st.y2 - st.y1;
        long d2x = x - st.x1;
        long d2y = y - st.y1;
        return (d2x * dy == d2y * dx);
    }

    // Return location of intersection between streets,
    // or return null if the streets do not intersect.
    public static Point intersectStreets(Street st1, Street st2)
    {
        // x = st1.x1 + u * st1.dx == st2.x1 + v * st2.dx
        // y = st1.y1 + u * st1.dy == st2.y1 + v * st2.dy

        long dx1 = st1.x2 - st1.x1;
        long dy1 = st1.y2 - st1.y1;
        long dx2 = st2.x2 - st2.x1;
        long dy2 = st2.y2 - st2.y1;
        long px  = st1.x1 - st2.x1;
        long py  = st1.y1 - st2.y1;

        // -u * dx1 + v * dx2 == px
        // -u * dy1 + v * dy2 == py

        long w = dx1 * dy2 - dx2 * dy1;
        if (w == 0) {
            // streets are parallel; no solutions
            return null;
        } else {
            // solve
            double u = (double)(dx2 * py - dy2 * px) / (double)w;
            double v = (double)(dx1 * py - dy1 * px) / (double)w;
            return new Point(st1.x1 + u * dx1, st1.y1 + u * dy1);
        }
    }

    // Return true if point p2 is forward from point p1 when tracing
    // street st in direction d.
    public static boolean isForwardPoint(Street st, Point p1, Point p2, int d)
    {
        int sdx = d * (st.x2 - st.x1);
        int sdy = d * (st.y2 - st.y1);
        double dx = p2.x - p1.x;
        double dy = p2.y - p1.y;
        return (dx * sdx + dy * sdy > 0);
    }

    // Return true if turning from st1 to st2 is a right turn.
    public static boolean rightTurn(Street st1, Street st2)
    {
        long dx1 = st1.x2 - st1.x1;
        long dy1 = st1.y2 - st1.y1;
        long dx2 = st2.x2 - st2.x1;
        long dy2 = st2.y2 - st2.y1;
        return (dy1 * dx2 - dx1 * dy2 > 0);
    }

    // Calculate distance between points.
    public static double pointDist(Point p1, Point p2)
    {
        double dx = p2.x - p1.x;
        double dy = p2.y - p1.y;
        return Math.sqrt(dx * dx + dy * dy);
    }

    // Solve problem.
    public static String solve(Street[] streets,
                               long n, int x, int y)
    {
        int r = streets.length;

        // Find home street.
        int s0 = -1;
        for (int i = 0; i < r; i++) {
            if (pointOnStreet(streets[i], x, y)) {
                s0 = i;
                break;
            }
        }
        assert (s0 >= 0);

        // Decide in which direction we start.
        assert (streets[s0].x1 != streets[s0].x2);
        int d = (streets[s0].x2 > streets[s0].x1) ? 1 : -1;

        int prevStreet = -1;
        Point p = new Point(x, y);

        // Build sequence of streets.
        ArrayList<Integer> path = new ArrayList<Integer>();
        path.add(s0);

        // Trace forward until we come back home or escape.
        int s = s0;
        while (true) {

            // Find next intersection we will encounter.
            int nextStreet = -1;
            Point nextPoint = null;
            double nextDist = Double.MAX_VALUE;
            int nextDir = 0;
            
            for (int i = 0; i < r; i++) {
                if (i != s && i != prevStreet) {
                    Point ptmp = intersectStreets(streets[s], streets[i]);
                    if (ptmp != null &&
                        isForwardPoint(streets[s], p, ptmp, d)) {
                        double nd = pointDist(p, ptmp);
                        if (nd < nextDist) {
                            nextStreet = i;
                            nextPoint = ptmp;
                            nextDist = nd;
                            nextDir = rightTurn(streets[s], streets[i]) ?
                                        d : (-d);
                        }
                    }
                }
            }

            // Stop if we escaped from the city (no next intersection).
            if (nextStreet < 0) {
                break;
            }

            // Add new street to path.
            path.add(nextStreet);

            // Stop if we are back home.
            if (nextStreet == s0) {
                break;
            }

            // Go to next street and trace forward.
            prevStreet = s;
            s = nextStreet;
            d = nextDir;
            p = nextPoint;
        }

        if (DEBUG) {
            System.err.println("Path:");
            for (int ts : path) {
                System.err.println("  " + streets[ts].name);
            }
        }

        // Use list of streets to resolve current location.
        int endStreet;
        if (path.size() > 1 && path.get(path.size()-1) == s0) {
            // Circular trace.
            if (DEBUG) {
                System.err.println("in loop, cycle length = " + (path.size() - 1));
            }
            endStreet = path.get((int)(n % (path.size() - 1)));
        } else if (n < path.size()) {
            // On route to escape.
            if (DEBUG) {
                System.err.println("on route to escape, path length = " + path.size());
            }
            endStreet = path.get((int) n);
        } else {
            // Escaped from city.
            if (DEBUG) {
                System.err.println("escaped, path length = " + path.size());
            }
            endStreet = path.get(path.size() - 1);
        }

        // Return name of final street.
        return streets[endStreet].name;
    }

    // Check that all street names are unique and meet requirements.
    public static void checkStreetNames(Street[] streets)
    {
        HashSet<String> names = new HashSet<String>();
        for (Street st : streets) {
            assert (st.name.length() >= 1 && st.name.length() <= 20);
            for (int i = 0; i < st.name.length(); i++) {
                char c = st.name.charAt(i);
                assert ((c >= '0' && c <= '9') ||
                        (c >= 'A' && c <= 'Z') ||
                        (c >= 'a' && c <= 'z'));
            }
            assert (!names.contains(st.name));
            names.add(st.name);
        }
    }

    // Check that all intersections meet requirements.
    public static void checkIntersections(Street[] streets, int x, int y)
    {
        int r = streets.length;

        int lim = 10000000;
        double mindist = 1.0e-4;

        HashMap<Long,ArrayList<Point>> htbl =
            new HashMap<Long,ArrayList<Point>>();

        // Check all intersections.
        for (int i = 0; i < r; i++) {
            for (int k = i + 1; k < r; k++) {

                // Check that streets are not colinear.
                assert (!pointOnStreet(streets[i],
                                       streets[k].x1, streets[k].y1) ||
                        !pointOnStreet(streets[i],
                                       streets[k].x2, streets[k].y2));

                Point p = intersectStreets(streets[i], streets[k]);
                if (p != null) {

                    // Check that intersection coordinates are in range.
                    assert (p.x >= -lim && p.x <= lim);
                    assert (p.y >= -lim && p.y <= lim);

                    // Check that intersection is at sufficient distance
                    // from home.
                    assert (pointDist(p, new Point(x, y)) > mindist);

                    // Check that intersection is at sufficient distance
                    // from all other intersections.
                    int cx = (int)(p.x * 100);
                    int cy = (int)(p.y * 100);
                    for (int hx = cx - 1; hx <= cx + 1; hx++) {
                        for (int hy = cy - 1; hy <= cy + 1; hy++) {
                            long hh = (long)hx * (1L << 30) + (long)hy;
                            ArrayList<Point> pts = htbl.get(hh);
                            if (pts != null) {
                                for (Point pp : pts) {
                                    assert (pointDist(p, pp) > mindist);
                                }
                            }
                        }
                    }

                    long hh = (long)cx * (1L << 30) + (long)cy;
                    ArrayList<Point> pts = htbl.get(hh);
                    if (pts == null) {
                        pts = new ArrayList<Point>();
                        htbl.put(hh, pts);
                    }
                    pts.add(p);
                }
            }
        }
    }

    public static void main(String[] args)
    {
        try {
            BufferedReader ir = new BufferedReader(
                                  new InputStreamReader(System.in));

            // Read input.
            String s = ir.readLine();
            String[] w = s.split(" ");
            assert (w.length == 4);
            int r = Integer.parseInt(w[0]);
            long n = Long.parseLong(w[1]);
            int x = Integer.parseInt(w[2]);
            int y = Integer.parseInt(w[3]);
            int lim = 10000000;
            long nlim = 10000000000L;
            assert (r > 0 && r <= 100);
            assert (n >= 0 && n <= nlim);
            assert (x >= -lim && x <= lim);
            assert (y >= -lim && y <= lim);

            Street[] streets = new Street[r];
            for (int i = 0; i < r; i++) {
                s = ir.readLine();
                w = s.split(" ");
                assert(w.length == 5);

                Street st = new Street();
                st.name = w[0];
                st.x1 = Integer.parseInt(w[1]);
                st.y1 = Integer.parseInt(w[2]);
                st.x2 = Integer.parseInt(w[3]);
                st.y2 = Integer.parseInt(w[4]);
                assert (st.name.length() > 0 && st.name.length() <= 20);
                assert (st.x1 >= -lim && st.x1 <= lim);
                assert (st.y1 >= -lim && st.y1 <= lim);
                assert (st.x2 >= -lim && st.x2 <= lim);
                assert (st.y2 >= -lim && st.y2 <= lim);
                assert (st.x1 != st.x2 || st.y1 != st.y2);

                streets[i] = st;
            }

            checkStreetNames(streets);
            checkIntersections(streets, x, y);

            // Solve problem.
            String ans = solve(streets, n, x, y);

            // Write output.
            System.out.println(ans);

        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

}

