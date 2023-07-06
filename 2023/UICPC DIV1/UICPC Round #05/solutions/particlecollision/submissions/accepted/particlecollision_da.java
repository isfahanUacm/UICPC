import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class particlecollision_da {

    enum Result {
        TWO_THEN_THREE(1), THREE_THEN_TWO(2), TWO_THEN_MISS(3), THREE_THEN_MISS(4), COMPLETE_MISS(5);

        private int res;

        Result(int res) {
            this.res = res;
        }

        public String toString() {
            return Integer.toString(res);
        }
    }

    static class Pt {
        double x, y;

        Pt(double x, double y) {
            this.x = x;
            this.y = y;
        }

        Pt rotate(int degrees, boolean round) {
            double th = Math.toRadians(degrees);
            double sin = Math.sin(th);
            double cos = Math.cos(th);
            double nx = x * cos - y * sin;
            double ny = x * sin + y * cos;
            if (round) {
                nx = Math.round(nx);
                ny = Math.round(ny);
            }
            return new Pt(nx, ny);
        }

        Pt mul(double k) {
            return new Pt(k * this.x, k * this.y);
        }

        Pt add(Pt p) {
            return new Pt(this.x + p.x, this.y + p.y);
        }

        double dist(Pt p) {
            return Math.sqrt(this.distSq(p));
        }

        double distSq(Pt p) {
            double dx = this.x - p.x;
            double dy = this.y - p.y;
            return dx * dx + dy * dy;
        }

        public String toString() {
            return String.format("(%.3f, %.3f)", x, y);
        }
    }

    private int r;

    private void work() {

        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        Pt[] p = new Pt[4];
        for (int i = 0; i < 4; i++) {
            String[] spl = sc.nextLine().split("\\s+");
            int x = Integer.parseInt(spl[0]);
            int y = Integer.parseInt(spl[1]);
            if (i == 3)
                r = Integer.parseInt(spl[2]);
            p[i] = new Pt(x, y);
        }
        sc.close();

        Result ans = solve(p);

        Pt ov = p[3];
        p[3] = ov.rotate(-1, false);
        if (ans != solve(p))
            throw new IllegalArgumentException(String.format("when rotated by -1 degree, expected %d but got %d"));
        p[3] = ov.rotate(1, false);
        if (ans != solve(p))
            throw new IllegalArgumentException(String.format("when rotated by +1 degree, expected %d but got %d"));

        System.out.println(ans);
    }

    public Result solve(Pt[] p) {

        // smallest distance
        double t1 = ternarySearch(p[0], p[1], p[3]);
        double t2 = ternarySearch(p[0], p[2], p[3]);

        double d1 = f(p[0], p[1], p[3], t1);
        double d2 = f(p[0], p[2], p[3], t2);

        // actual collision
        t1 = binarySearch(p[0], p[1], p[3], t1);
        t2 = binarySearch(p[0], p[2], p[3], t2);

        if (d1 >= 2 * r + 1e-10 && d2 >= 2 * r + 1e-10) {
            // missed both
            return Result.COMPLETE_MISS;
        }

        // if it cannot hit p1 or it can hit both but p2 is closer
        if (d1 >= 2 * r + 1e-10 || (d2 < 2 * r + 1e-10 && t2 < t1)) {
            // get the vector from 2
            Pt v2 = getNextVector(p[0], p[2], p[3], t2);
            // can it hit 1?
            double t21 = ternarySearch(p[2], p[1], v2);
            double d21 = f(p[2], p[1], v2, t21);
            return (d21 < 2 * r + 1e-10) ? Result.THREE_THEN_TWO : Result.THREE_THEN_MISS;
        }

        // get the vector from 1
        Pt v1 = getNextVector(p[0], p[1], p[3], t1);
        // can it hit 2?
        double t12 = ternarySearch(p[1], p[2], v1);
        double d12 = f(p[1], p[2], v1, t12);
        return (d12 < 2 * r + 1e-10) ? Result.TWO_THEN_THREE : Result.TWO_THEN_MISS;
    }

    private Pt getNextVector(Pt p0, Pt p1, Pt v, double t) {
        Pt c = p0.add(v.mul(t));
        return new Pt(p1.x - c.x, p1.y - c.y);
    }

    // closest p0 can get to p1 along v
    private double ternarySearch(Pt p0, Pt p1, Pt v) {
        double lo = 0;
        double hi = 1e9;
        int steps = 200;
        while (steps-- > 0) {
            double a = (2 * lo + hi) / 3;
            double b = (lo + 2 * hi) / 3;
            if (f(p0, p1, v, a) < f(p0, p1, v, b))
                hi = b;
            else
                lo = a;
        }
        return lo;
    }

    // given closest p0 and p1 are at p0 + hi*v, when do they actually collide?
    private double binarySearch(Pt p0, Pt p1, Pt v, double hi) {
        double lo = 0;
        int steps = 200;
        while (steps-- > 0) {
            double m = 0.5 * (lo + hi);
            if (f(p0, p1, v, m) < 2 * r)
                hi = m;
            else
                lo = m;
        }
        return lo;
    }

    private double f(Pt p0, Pt p1, Pt v, double k) {
        return p0.add(v.mul(k)).dist(p1);
    }

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();
        new particlecollision_da().work();
        long t = System.currentTimeMillis() - startTime;
        System.err.println(String.format("Elapsed time: %d:%02d.%03d\n", t / 60000, (t / 1000) % 60, t % 1000));
    }
}
