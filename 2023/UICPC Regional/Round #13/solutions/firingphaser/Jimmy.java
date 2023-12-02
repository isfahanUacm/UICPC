import java.util.ArrayList;
import java.util.Scanner;

public class Jimmy {
    private static final double EPS = 1e-8;

    private static class Rect {
        LineD l1, l2, l3, l4;
        int id, minx, maxx, miny, maxy;

        Rect(int id, int x1, int y1, int x2, int y2) {
            this.id = id;
            PointD p1 = new PointD(x1, y1);
            PointD p2 = new PointD(x2, y2);
            this.l1 = new LineD(p1.x, p1.y, p1.x, p2.y);
            this.l2 = new LineD(p1.x, p2.y, p2.x, p2.y);
            this.l3 = new LineD(p2.x, p2.y, p2.x, p1.y);
            this.l4 = new LineD(p2.x, p1.y, p1.x, p1.y);
            this.minx = x1;
            this.miny = y1;
            this.maxx = x2;
            this.maxy = y2;
        }

        LineD[] getLines() {
            return new LineD[] { l1, l2, l3, l4 };
        }
    }

    public static class Event implements Comparable<Event> {
        int id;
        double dist;

        Event(int id, double dist) {
            this.dist = dist;
            this.id = id;
        }

        @Override
        public int compareTo(Event o) {
            return Double.compare(dist, o.dist);
        }

    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        //Scanner scanner = new Scanner(new FileInputStream("laser.in"));
        int n = scanner.nextInt(), laserLength = scanner.nextInt();
        Rect[] rects = new Rect[n];
        PointD[] corners = new PointD[n*4];
        for (int i = 0; i < n; i++) {
            rects[i] = new Rect(i, scanner.nextInt(), scanner.nextInt(), scanner.nextInt(), scanner.nextInt());
            corners[i*4+0] = rects[i].l1.a;
            corners[i*4+1] = rects[i].l2.a;
            corners[i*4+2] = rects[i].l3.a;
            corners[i*4+3] = rects[i].l4.a;
        }

        int best = 0;

        // For every pair of corners C1 C2 where line C1-C2 is not horizontal or vertical
        // * For every line segment intersecting with line C1-C2, sort points by distance from somewhere
        // * Sliding window over the points to find max number of "ins" within laserLength

        for (PointD p1 : corners) {
            for (PointD p2 : corners) {
                if (p1.x == p2.x || p1.y == p2.y) continue;
                LineD laser = new LineD(p1, p2);
                best = Math.max(best, countBest(rects, laser, laserLength));
            }
        }

        // For every corner C1 draw a straight horizontal and vertical line
        // * Loop through remaining lines and see if intersects with some if-statements
        for (PointD p : corners) {
            best = Math.max(best, countBest(rects, new LineD(p.x, p.y, p.x+1, p.y), laserLength));
            best = Math.max(best, countBest(rects, new LineD(p.x, p.y, p.x, p.y+1), laserLength));
        }

        // For every corner C, vertical line L1 and horizontal line L2 (all different rectangles),
        // find shortest line intersecting L1, C and L2.
        // This is done using ternary search because I couldn't get the equation working for some reason
        for (PointD cp : corners) {
            PointD cpd = new PointD(cp.x, cp.y);
            for (Rect r1 : rects) {
                for (LineD l1 : r1.getLines()) {
                    // Ignore colinear
                    if (l1.a.x == l1.b.x && l1.a.x == cp.x) continue;
                    if (l1.a.y == l1.b.y && l1.a.y == cp.y) continue;
                    if (l1.a.x != l1.b.x) continue; // l1 should be vertical
                    for (Rect r2 : rects) {
                        for (LineD l2 : r2.getLines()) {
                            // Ignore colinear
                            if (l2.a.x == l2.b.x && l2.a.x == cp.x) continue;
                            if (l2.a.y == l2.b.y && l2.a.y == cp.y) continue;
                            if (l2.a.y != l2.b.y) continue; // l2 should be horizontal

                            LineD l1d = new LineD(l1.a.x, l1.a.y, l1.b.x, l1.b.y);
                            LineD l2d = new LineD(l2.a.x, l2.a.y, l2.b.x, l2.b.y);

                            // There may be two minpoints, one above and one below the corner y
                            double y1 = search(cpd, l1d, l2d, cpd.y, Math.max(l1.a.y, l1.b.y));
                            LineD laser1 = new LineD(new PointD(l1d.a.x, y1), cpd);
                            best = Math.max(best, countBest(rects, laser1, laserLength));

                            double y2 = search(cpd, l1d, l2d, Math.min(l1.a.y, l1.b.y), cpd.y);
                            LineD laser2 = new LineD(new PointD(l1d.a.x, y2), cpd);
                            best = Math.max(best, countBest(rects, laser2, laserLength));
                        }
                    }
                }
            }
        }

        System.out.println(best);
    }

    private static double search(PointD cpd, LineD l1d, LineD l2d, double ymin, double ymax) {
        double diff = 1.0;
        int noIter = 0;
        while (diff > EPS) {
            double y1 = ymin + (ymax-ymin) / 3;
            double y2 = ymin + (ymax-ymin) / 3 * 2;
            double x1 = getX(cpd, l1d, l2d, y1);
            double x2 = getX(cpd, l1d, l2d, y2);
            double d1 = Math.sqrt((x1 - l1d.a.x) * (x1 - l1d.a.x) + (y1 - l2d.a.y) * (y1 - l2d.a.y));
            double d2 = Math.sqrt((x2 - l1d.a.x) * (x2 - l1d.a.x) + (y2 - l2d.a.y) * (y2 - l2d.a.y));
            if (d1 > d2) {
                ymin = y1;
            } else {
                ymax = y2;
            }
            diff = Math.max(Math.abs(x1-x2), Math.abs(y1-y2));
            noIter++;
        }
        return ymin;
    }

    private static double getX(PointD cpd, LineD l1d, LineD l2d, double y) {
        PointD p1 = new PointD(l1d.a.x, y);
        LineD pl1 = new LineD(p1, cpd);
        PointD res1 = new PointD();
        if (LineD.intersect(pl1, l2d, res1)) {
            return res1.x;
        }
        return Double.NaN;
    }

    private static int countBest(Rect[] rects, LineD laser, int laserLength) {
        ArrayList<Event> events = new ArrayList<>();
        for (Rect rect : rects) {
            for (LineD line : rect.getLines()) {
                double dist = intersectLaser(laser, line);
                if (!Double.isNaN(dist)) {
                    events.add(new Event(rect.id, dist));
                }
            }
        }
        int best = 0;
        for (Event e1 : events) {
            boolean inside[] = new boolean[rects.length];
            int count = 0;
            for (Event e2 : events) {
                if (e2.dist > e1.dist - EPS && e2.dist < e1.dist + laserLength + EPS) {
                    if (!inside[e2.id]) count++;
                    inside[e2.id] = true;
                }
            }
            best = Math.max(best, count);
        }
        return best;
    }

    // a is a segment, b is infinite
    private static double intersectLaser(LineD a, LineD b) {
        PointD difv = PointD.sub(b.a, a.a), av = PointD.sub(a.b, a.a), bv = PointD.sub(b.a, b.b);
        double d = PointD.det(av,bv), fa = PointD.det(difv, bv), fb = PointD.det(av, difv);
        if (Math.abs(d) < EPS) return Double.NaN;
        if (d < 0) { d = -d; fa = -fa; fb = -fb; }
        if (fb<0 || fb>d) return Double.NaN;
        return Math.sqrt(av.getNormSqr()) * fa / d;
    }


    private static class PointD implements Comparable<PointD> {
        double x, y;

        private static final double EPS = 1e-9;

        PointD()  { this(0.0,0.0); }
        PointD(double x, double y) { this.x = x; this.y = y; }
        static PointD add(PointD p1, PointD p2) { return new PointD(p1.x+p2.x, p1.y+p2.y); }
        static PointD sub(PointD p1, PointD p2) { return new PointD(p1.x-p2.x, p1.y-p2.y); }
        static PointD mul(PointD p1, double scalar) { return new PointD(p1.x*scalar, p1.y*scalar); }
        static PointD div(PointD p1, double scalar) { return new PointD(p1.x/scalar, p1.y/scalar); }
        static double det(PointD a, PointD b) { return a.x*b.y-a.y*b.x; }
        double getNormSqr() { return x*x+y*y; }
        public int compareTo(PointD other) {
            PointD p = other;
            return almostZero(x - p.x) ? Double.compare(y, p.y) : Double.compare(x, p.x);
        }

        static boolean almostZero(double x) { return Math.abs(x) < EPS; }
    }


    private static class LineD {
        PointD a, b;
        LineD(PointD a, PointD b) { this.a = a; this.b = b; }
        LineD(double x1, double y1, double x2, double y2)  { this(new PointD(x1,y1), new PointD(x2,y2)); }

        /**
         * Returns true if the two lines intersect (and are not parallel)
         * @param a a line
         * @param b a line
         * @param res will contain the intersection point
         * @return true if the lines intersect
         */
        static boolean intersect(LineD a, LineD b, PointD res) {
            PointD difv = PointD.sub(b.a, a.a), av = PointD.sub(a.b, a.a), bv = PointD.sub(b.a, b.b);
            double d = PointD.det(av,bv), fa = PointD.det(difv, bv), fb = PointD.det(av, difv);
            if (PointD.almostZero(d)) return false;
            if (d < 0) { d = -d; fa = -fa; fb = -fb; }
            PointD t = PointD.add(a.a, PointD.div(PointD.mul(av, fa), d));
            if (res != null) {
                res.x = t.x;
                res.y = t.y;
            }
            return true;
        }
    }

}
