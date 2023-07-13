import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class treasure_da {

    class Point {
        long x, y;

        Point(long x, long y) {
            this.x = x;
            this.y = y;
        }

        Point sub(Point p) {
            return new Point(x - p.x, y - p.y);
        }

        long dot(Point p) {
            return x * p.x + y * p.y;
        }

        long cross(Point p) {
            return x * p.y - p.x * y;
        }

        long lenSq() {
            return x * x + y * y;
        }

        public String toString() {
            return String.format("(%d, %d)", x, y);
        }
    }

    private int ccw(Point a, Point b, Point c) {
        Point p = b.sub(a);
        Point q = c.sub(b);
        long cross = p.cross(q);
        if (cross < 0) return -1;
        if (cross > 0) return 1;
        return 0;
    }

    private boolean onSegment(Point a, Point b, Point c) {
        return b.x <= Math.max(a.x, c.x) && b.x >= Math.min(a.x, c.x) &&
                b.y <= Math.max(a.y, c.y) && b.y >= Math.min(a.y, c.y);

    }

    private boolean intersect(Point a, Point b, Point c, Point d) {
        int aa = ccw(a, b, c);
        int bb = ccw(a, b, d);
        int cc = ccw(c, d, a);
        int dd = ccw(c, d, b);

        if (aa != bb && cc != dd) return true;

        if (aa == 0 && onSegment(a, c, b)) return true;
        if (bb == 0 && onSegment(a, d, b)) return true;
        if (cc == 0 && onSegment(c, a, d)) return true;
        return dd == 0 && onSegment(c, b, d);

    }

    private void solve() {
        for (int i = 0; i < p; i++) {
            System.out.println(check(i) ? "visible" : "not visible");
        }
    }

    private boolean check(int idx) {

        Point pt = t.sub(pirates[idx][0]);
        Point dir = pirates[idx][1].sub(pirates[idx][0]);

        // too far?
        long rsq = dir.lenSq();
        long td = pt.lenSq();
        if (rsq < td) return false;

        // facing the right way?
        if (pt.dot(dir) < 0) return false;

        // other pirates in the way?
        for (int i = 0; i < p; i++) {
            if (i == idx) continue;
            if (ccw(pirates[idx][0], t, pirates[i][0]) == 0 && onSegment(pirates[idx][0], pirates[i][0], t))
                return false;
        }

        // walls blocking the view?
        for (int i = 0; i < w; i++) {
            if (intersect(pirates[idx][0], t, walls[i][0], walls[i][1])) return false;
        }

        return true;
    }

    private void readInput() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        w = sc.nextInt();
        p = sc.nextInt();
        walls = new Point[w][2];
        pirates = new Point[p][2];
        t = new Point(sc.nextInt(), sc.nextInt());
        for (int i = 0; i < w; i++) {
            walls[i][0] = new Point(sc.nextInt(), sc.nextInt());
            walls[i][1] = new Point(sc.nextInt(), sc.nextInt());
        }
        for (int i = 0; i < p; i++) {
            pirates[i][0] = new Point(sc.nextInt(), sc.nextInt());
            pirates[i][1] = new Point(sc.nextInt(), sc.nextInt());
        }
        sc.close();
    }

    private void work() {
        readInput();
        solve();
    }

    private int w, p;
    private Point t;
    private Point[][] walls, pirates;

    public static void main(String[] args) {
        new treasure_da().work();
    }
}
