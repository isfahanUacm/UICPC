import java.io.*;
import java.util.*;

public class Contest06_C {




    static class kaman {
        double x, y;
        double rx, ry;
        int sign;

        kaman(double x, double y, double rx, double ry, int sign) {
            this.x = x;
            this.y = y;
            this.rx = rx;
            this.ry = ry;
            this.sign = sign;
        }
    }

    static double nomalKardan(double a) {
        double twoPi = 2.0 * Math.PI;
        a %= twoPi;
        if (a < 0) a += twoPi;
        return a;
    }

    static double FasalaKaman(double h, double k, kaman a,
                              double shiftX, double shiftY) {

        double cx = a.x + shiftX;
        double cy = a.y + shiftY;

        double wx = h - cx;
        double wy = k - cy;

        double r = Math.hypot(wx, wy);

        if (r < 1e-14) return 1.0;

        double angle = Math.atan2(wy, wx);
        double start = Math.atan2(a.ry, a.rx);

        double delta;

        if (a.sign == 1) {
            delta = nomalKardan(angle - start);
        } else {
            delta = nomalKardan(start - angle);
        }

        if (delta <= Math.PI / 2.0 + 1e-12) {
            return Math.abs(r - 1.0);
        }

        double ex1 = cx + a.rx;
        double ey1 = cy + a.ry;

        double ex2, ey2;

        if (a.sign == 1) {
            ex2 = cx - a.ry;
            ey2 = cy + a.rx;
        } else {
            ex2 = cx + a.ry;
            ey2 = cy - a.rx;
        }

        return Math.min(
                Math.hypot(h - ex1, k - ey1),
                Math.hypot(h - ex2, k - ey2)
        );
    }

    static double BaraHal(long h, long k, String s) {

        int n = s.length();

        int q = 0;

        for (int i = 0; i < n; i++) {
            q += (s.charAt(i) == 'L') ? 1 : -1;
        }

        q = (q % 4 + 4) % 4;

        int periods = (q == 0) ? 1 :
                (q == 2 ? 2 : 4);

        List<kaman> kamen = new ArrayList<>();

        double x = 0;
        double y = 0;

        int dir = 0;

        int[] dx = {1, 0, -1, 0};
        int[] dy = {0, 1, 0, -1};

        for (int p = 0; p < periods; p++) {

            for (int i = 0; i < n; i++) {

                char c = s.charAt(i);

                double ux = dx[dir];
                double uy = dy[dir];

                double nx = -uy;
                double ny = ux;

                double cx, cy;
                double rx, ry;
                int sign;

                if (c == 'L') {

                    cx = x + nx;
                    cy = y + ny;

                    rx = -nx;
                    ry = -ny;

                    sign = 1;

                    dir = (dir + 1) % 4;

                } else {

                    cx = x - nx;
                    cy = y - ny;

                    rx = nx;
                    ry = ny;

                    sign = -1;

                    dir = (dir + 3) % 4;
                }

                kamen.add(new kaman(cx, cy, rx, ry, sign));

                double oldX = x;
                double oldY = y;

                if (sign == 1) {
                    x = cx - ry;
                    y = cy + rx;
                } else {
                    x = cx + ry;
                    y = cy - rx;
                }
            }
        }

        double vx = x;
        double vy = y;

        double Javabam06 = Double.POSITIVE_INFINITY;

        if (q != 0 || (vx == 0 && vy == 0)) {

            for (kaman a : kamen) {
                Javabam06 = Math.min(
                        Javabam06,
                        FasalaKaman(h, k, a, 0, 0)
                );
            }

        } else {

            double v2 = vx * vx + vy * vy;
            double vlen = Math.sqrt(v2);

            for (kaman a : kamen) {

                double base =
                        ((h - a.x) * vx + (k - a.y) * vy) / v2;

                double radius = 1.0 / vlen;

                double lo = base - radius;
                double hi = base + radius;

                long from = (long) Math.floor(lo) - 1;
                long to = (long) Math.ceil(hi) + 1;
                for (long j = from; j <= to; j++) {

                    double shiftX = j * vx;
                    double shiftY = j * vy;

                    Javabam06 = Math.min(
                            Javabam06,
                            FasalaKaman(h, k, a, shiftX, shiftY)
                    );
                }
            }
        }

        return Javabam06;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(
                new InputStreamReader(System.in)
        );

        int AbbasAgha = Integer.parseInt(br.readLine().trim());

        StringBuilder sb = new StringBuilder();

        while (AbbasAgha-- > 0) {

            StringTokenizer st =
                    new StringTokenizer(br.readLine());

            long h = Long.parseLong(st.nextToken());
            long k = Long.parseLong(st.nextToken());

            String s = br.readLine().trim();

            double ans = BaraHal(h, k, s);

            sb.append(String.format(
                    Locale.US, "%.15f%n", ans
            ));
        }

        System.out.print(sb);
    }
}