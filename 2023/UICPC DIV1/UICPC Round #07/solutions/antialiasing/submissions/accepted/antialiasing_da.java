import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class antialiasing_da {

    static class Fraction implements Comparable<Fraction> {
        long n, d;

        Fraction(long n, long d) {
            if (d == 0) {
                throw new ArithmeticException("Denominator cannot be zero");
            }

            if (n == 0) {
                this.d = 1;
            } else {
                long g = gcd(n, d);
                this.n = n / g;
                this.d = d / g;
            }

            if (this.d < 0) {
                this.n = -this.n;
                this.d = -this.d;
            }
        }

        public Fraction mul(Fraction f) {
            return new Fraction(n * f.n, d * f.d);
        }

        public Fraction add(Fraction f) {
            return new Fraction(n * f.d + f.n * d, d * f.d);
        }

        public Fraction neg() {
            return new Fraction(-n, d);
        }

        public Fraction inv() {
            return new Fraction(d, n);
        }

        public String toString() {
            return n + "/" + d;
        }

        public int compareTo(Fraction o) {
            long c = n * o.d - o.n * d;
            if (c < 0) return -1;
            if (c > 0) return 1;
            return 0;
        }

        private long gcd(long a, long b) {
            return b == 0 ? a : gcd(b, a % b);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Fraction fraction = (Fraction) o;
            return n == fraction.n && d == fraction.d;
        }

        @Override
        public int hashCode() {
            return Objects.hash(n, d);
        }
    }

    static class PtF {
        Fraction x, y;

        PtF(Fraction x, Fraction y) {
            this.x = x;
            this.y = y;
        }

        public Fraction dot(PtF p) {
            return x.mul(p.x).add(y.mul(p.y));
        }

        public Fraction cross(PtF p) {
            return x.mul(p.y).add((y.mul(p.x)).neg());
        }

        public PtF sub(PtF p) {
            return new PtF(x.add(p.x.neg()), y.add(p.y.neg()));
        }

        public String toString() {
            return "(" + x + ", " + y + ")";
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            PtF ptF = (PtF) o;
            return x.equals(ptF.x) && y.equals(ptF.y);
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }
    }

    static class SegF implements Comparable<SegF> {
        PtF p0, p1, v;
        Fraction a, b, c; // line ax + by = c

        SegF(PtF p0, PtF p1) {
            this.p0 = p0;
            this.p1 = p1;
            v = p1.sub(p0);

            a = p1.y.add(p0.y.neg());
            b = p0.x.add(p1.x.neg());
            c = a.mul(p0.x).add(b.mul(p0.y));
        }

        public boolean contains(PtF p) {
            Fraction f = a.mul(p.x).add(b.mul(p.y)).add(c.neg());
            if (f.n != 0L) return false;
            Fraction minX = p0.x.compareTo(p1.x) < 0 ? p0.x : p1.x;
            Fraction maxX = p0.x.compareTo(p1.x) < 0 ? p1.x : p0.x;
            Fraction minY = p0.y.compareTo(p1.y) < 0 ? p0.y : p1.y;
            Fraction maxY = p0.y.compareTo(p1.y) < 0 ? p1.y : p0.y;
            return minX.compareTo(p.x) <= 0 && p.x.compareTo(maxX) <= 0
                    && minY.compareTo(p.y) <= 0 && p.y.compareTo(maxY) <= 0;
        }

        public PtF isect(SegF s) {
            Fraction d = a.mul(s.b).add((b.mul(s.a)).neg());
            if (d.n == 0L) {
                return null; // parallel lines, deal with them somewhere else
            }

            PtF p = new PtF(c.mul(s.b).add((b.mul(s.c)).neg()).mul(d.inv()),
                    a.mul(s.c).add((c.mul(s.a)).neg()).mul(d.inv()));
            if (!this.contains(p) || !s.contains(p)) {
                return null;
            }

            return p;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            SegF segF = (SegF) o;
            return p0.equals(segF.p0) && p1.equals(segF.p1);
        }

        @Override
        public int hashCode() {
            return Objects.hash(p0, p1);
        }

        public String toString() {
            return String.format("[%s - %s] %sX+%sY+%s", p0, p1, a, b, c);
        }

        @Override
        public int compareTo(SegF o) {
            if (p1.y.compareTo(p0.y) == 0 && p1.y.compareTo(o.p1.y) == 0) {
                return o.p1.x.compareTo(p1.x);
            }

            Fraction k = v.cross(o.v);
            if (k.n == 0) {
                Fraction d = v.dot(v).add(o.v.dot(o.v).neg());
                if (d.n == 0) {
                    return 0;
                }

                if (d.n < 0) {
                    return -1;
                }
                return 1;
            }

            if (k.n < 0) {
                return -1;
            }
            return 1;
        }
    }

// ============ SOLUTION BELOW =============

    private void work() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = sc.nextInt();
        int q = sc.nextInt();

        PtF[] v = new PtF[n];
        SegF[] e = new SegF[n];
        for (int i = 0; i < n; i++) {
            long x = sc.nextInt();
            long y = sc.nextInt();
            v[i] = new PtF(new Fraction(2 * x + 1, 2), new Fraction(2 * y + 1, 2));
            if (i > 0) {
                e[i - 1] = new SegF(v[i - 1], v[i]);
            }
        }

        e[n - 1] = new SegF(v[n - 1], v[0]);


        PtF[] corners = new PtF[4];
        SegF[] pixel = new SegF[4];
        while (q-- > 0) {
            long x = sc.nextInt();
            long y = sc.nextInt();

            PtF center = new PtF(new Fraction(2 * x + 1, 2), new Fraction(2 * y + 1, 2));

            corners[0] = new PtF(new Fraction(x, 1), new Fraction(y, 1));
            corners[1] = new PtF(new Fraction(x + 1, 1), new Fraction(y, 1));
            corners[2] = new PtF(new Fraction(x + 1, 1), new Fraction(y + 1, 1));
            corners[3] = new PtF(new Fraction(x, 1), new Fraction(y + 1, 1));

            for (int i = 0; i < 4; i++) {
                pixel[i] = new SegF(corners[i], corners[(i + 1) & 3]);
            }

            Fraction res = null;
            List<PtF> ps = new ArrayList<>();

            // add all internal corners
            for (int j = 0; j < 4; j++) {
                if (isPointInside(corners[j], e)) {
                    ps.add(corners[j]);
                }
            }

            if (ps.size() == 4) {
                res = new Fraction(1, 1);
            } else {
                for (int i = 0; i < n; i++) {
                    if (center.equals(v[i])) {
                        // just check the adjacent segments, must be exactly 2 intersections
                        SegF s0 = e[(i - 1 + n) % n];
                        for (int j = 0; j < 4; j++) {
                            PtF p0 = s0.isect(pixel[j]);
                            if (p0 != null) ps.add(p0);
                        }
                        SegF s1 = e[i];
                        ps.add(center);
                        for (int j = 0; j < 4; j++) {
                            PtF p1 = s1.isect(pixel[j]);
                            if (p1 != null) ps.add(p1);
                        }

                        PtF[] points = ps.toArray(new PtF[0]);
                        res = getArea(points, points.length);
                        break;
                    }
                }

                if (res == null) {
                    // intersecting some edge, maybe

                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < 4; j++) {
                            PtF p = e[i].isect(pixel[j]);
                            if (p != null) ps.add(p);
                        }
                    }

                    PtF[] points = ps.toArray(new PtF[0]);
                    res = getArea(points, points.length);
                }
            }

            System.out.println(res);
        }
    }

    private boolean isPointInside(PtF p, SegF[] e) {
        PtF p0 = new PtF(p.x.add(new Fraction(-1002, 1)), p.y.add(new Fraction(1, 1)));
        SegF s = new SegF(p0, p);
        int count = 0;
        for (SegF segF : e) {
            if (segF.isect(s) != null) count++;
        }

        return (count & 1) != 0;
    }

    private Fraction getArea(PtF[] p, int n) {
        if (n < 3) return new Fraction(0, 1);
        sort(p, n);
        Fraction sum = new Fraction(0, 1);
        for (int i = n - 1, j = 0; j < n; i = j++) {
            sum = sum.add(p[i].cross(p[j]));
        }

        if (sum.n < 0) sum = sum.neg();
        return new Fraction(sum.n, 2 * sum.d);
    }

    private void sort(PtF[] p, int n){
        Fraction cx = new Fraction(0, 1);
        Fraction cy = new Fraction(0, 1);
        for(PtF pt : p){
            cx = cx.add(pt.x);
            cy = cy.add(pt.y);
        }
        Fraction inverseN = new Fraction(1, n);
        cx = cx.mul(inverseN);
        cy = cy.mul(inverseN);
        PtF c = new PtF(cx, cy);

        SegF[] a = new SegF[n];
        for(int i = 0; i < n; i++){
            a[i] = new SegF(c, p[i]);
        }

        Arrays.sort(a);

        for(int i = 0; i < n; i++){
            p[i] = a[i].p1;
        }
    }

    public static void main(String[] args) {
        new antialiasing_da().work();
    }
}
