import java.io.*;
import java.util.*;

public class Lukas {
  static class Point {
    public double x, y;
    Point(double _x, double _y) {
      x = _x;
      y = _y;
    }
    boolean equals(Point b) { return x == b.x && y == b.y; }
    Point plus(Point b) { return new Point(x + b.x, y + b.y); }
    Point minus(Point b) { return new Point(x - b.x, y - b.y); }
    Point multiply(double d) { return new Point(x * d, y * d); }
    Point divide(double d) { return new Point(x / d, y / d); }
    double dot(Point b) { return x * b.x + y * b.y; }
    double dist2() { return x * x + y * y; } //distance^2
    double dist() { return Math.sqrt(dist2()); } //length
    Point unit() {
        if (dist() < 1e-9) return this;
        return this.divide(this.dist());
    } //makes dist()=1
  };

  static double segDist(Point s, Point e, Point p) {
      if (s.equals(e)) return (p.minus(s)).dist();
      double d = e.minus(s).dist2(),
             t = Math.min(d, Math.max(0.0, p.minus(s).dot(e.minus(s))));
      return p.minus(s).multiply(d).minus(e.minus(s).multiply(t)).dist() / d;
  }

  static List<Point> read(Kattio io) {
    int n = io.getInt();
    List<Point> res = new ArrayList<Point>();
    for (int i = 0; i < n; ++i) {
      double x, y;
      x = io.getDouble();
      y = io.getDouble();
      res.add(new Point(x, y));
    }
    return res;
  }

  public static void main (String[] args) {
    Kattio io = new Kattio(System.in, System.out);
    List<Point> a = read(io);
    List<Point> b = read(io);

    Point cura = a.get(0), curb = b.get(0);
    double ma = (cura.minus(curb)).dist();
    int nexta = 1, nextb = 1;
    while (nexta < a.size() && nextb < b.size()) { // Stop when one of them reaches home
        Point mova = a.get(nexta).minus(cura);
        Point movb = b.get(nextb).minus(curb);

        double lena = mova.dist();
        double lenb = movb.dist();
        double len = Math.min(lena, lenb);

        Point diff = cura.minus(curb);
        cura = cura.plus(mova.unit().multiply(len));
        curb = curb.plus(movb.unit().multiply(len));

        double distance = segDist(diff, cura.minus(curb), new Point(0, 0));
        ma = Math.min(ma, distance);

        if (lena <= lenb) {
            // assign for better precision. the value of cura is almost the same as a[nexta] already
            cura = a.get(nexta);
            nexta++;
        }
        else {
            curb = b.get(nextb);
            nextb++;
        }
    }

    io.println(String.format("%.9f", ma));

    io.close();
  }
}

/** Simple yet moderately fast I/O routines.
 *
 * Example usage:
 *
 * Kattio io = new Kattio(System.in, System.out);
 *
 * while (io.hasMoreTokens()) {
 *    int n = io.getInt();
 *    double d = io.getDouble();
 *    double ans = d*n;
 *
 *    io.println("Answer: " + ans);
 * }
 *
 * io.close();
 *
 *
 * Some notes:
 *
 * - When done, you should always do io.close() or io.flush() on the
 *   Kattio-instance, otherwise, you may lose output.
 *
 * - The getInt(), getDouble(), and getLong() methods will throw an
 *   exception if there is no more data in the input, so it is generally
 *   a good idea to use hasMoreTokens() to check for end-of-file.
 *
 * @author: Kattis
 */

class Kattio extends PrintWriter {
  public Kattio(InputStream i) {
    super(new BufferedOutputStream(System.out));
    r = new BufferedReader(new InputStreamReader(i));
  }
  public Kattio(InputStream i, OutputStream o) {
    super(new BufferedOutputStream(o));
    r = new BufferedReader(new InputStreamReader(i));
  }

  public boolean hasMoreTokens() {
    return peekToken() != null;
  }

  public int getInt() {
    return Integer.parseInt(nextToken());
  }

  public double getDouble() {
    return Double.parseDouble(nextToken());
  }

  public long getLong() {
    return Long.parseLong(nextToken());
  }

  public String getWord() {
    return nextToken();
  }

  private BufferedReader r;
  private String line;
  private StringTokenizer st;
  private String token;

  private String peekToken() {
    if (token == null)
      try {
        while (st == null || !st.hasMoreTokens()) {
          line = r.readLine();
          if (line == null) return null;
          st = new StringTokenizer(line);
        }
        token = st.nextToken();
      } catch (IOException e) { }
    return token;
  }

  private String nextToken() {
    String ans = peekToken();
    token = null;
    return ans;
  }
}
