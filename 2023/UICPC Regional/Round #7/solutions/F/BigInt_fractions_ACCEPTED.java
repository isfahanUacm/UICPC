

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * A solution for Endless Turning using fractions
 * @author robbert van Staveren
 *
 */
public class BigInt_fractions_ACCEPTED {
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int R = sc.nextInt();
		long N = sc.nextLong();
		long X = sc.nextInt();
		long Y = sc.nextInt();
		sc.nextLine();
		Line[] lines = new Line[R];
		Line firstRoad = null;
		for(int i=0; i<R; i++)
		{
			String s = sc.nextLine();
			lines[i] = new Line(s.split(" ")[0],Long.parseLong(s.split(" ")[1]),Long.parseLong(s.split(" ")[2]),Long.parseLong(s.split(" ")[3]),Long.parseLong(s.split(" ")[4]));
			if(!lines[i].vert() && lines[i].longValueAt(X) == Y)
				firstRoad = lines[i];
		}
		sc.close();
		ArrayList<Line> path = firstRoad.getPath(true, lines, new ArrayList<Line>(), firstRoad, new Point(X, Y));
		if(path.size() >= N)
			System.out.println(path.get((int)N-1).name);
		else
		{
			if(path.size()==0)
				System.out.println(firstRoad.name);
			else
			{
				if(path.get(path.size()-1).equals(firstRoad))
					System.out.println(path.get((int)((N-1)%path.size())).name);
				else
					System.out.println(path.get(path.size()-1).name);
			}
		}
	}

	private static class Line
	{
		Point p1;
		Fraction slope;
		String name;
		public Line(String s, long x1, long y1, long x2, long y2)
		{
			p1 = new Point(x1, y1);
			slope = new Fraction(y2-y1, x2-x1);
			name = s;
		}
		public ArrayList<Line> getPath(boolean east, Line[] lines, ArrayList<Line> currPath, Line firstRoad, Point currPoint) {
			if(this.equals(firstRoad) && !currPath.isEmpty())
				return currPath;
			Line next = null;
			Point nextPoint = null;
			for(Line l : lines)
			{
				if(!this.slope.equals(l.slope))
				{
					Point intersect = this.intersect(l);
					if(east)
					{
						if(vert())
						{
							if(intersect.y.compareTo(currPoint.y) < 0)
							{
								if(nextPoint == null || intersect.y.compareTo(nextPoint.y) > 0)
								{
									next = l;
									nextPoint = intersect;
								}
							}
						}
						else
						{
							if(intersect.x.compareTo(currPoint.x) > 0)
							{
								if(nextPoint == null || intersect.x.compareTo(nextPoint.x) < 0)
								{
									next = l;
									nextPoint = intersect;
								}
							}
						}
					}
					else
					{
						if(vert())
						{
							if(intersect.y.compareTo(currPoint.y) > 0)
							{
								if(nextPoint == null || intersect.y.compareTo(nextPoint.y) < 0)
								{
									next = l;
									nextPoint = intersect;
								}
							}
						}
						else
						{
							if(intersect.x.compareTo(currPoint.x) < 0)
							{
								if(nextPoint == null || intersect.x.compareTo(nextPoint.x) > 0)
								{
									next = l;
									nextPoint = intersect;
								}
							}
						}
					}
				}
			}
			if(next == null)
				return currPath;
			currPath.add(next);
			if(vert())
				east = !east;
			else
			{
				if(!next.vert() && next.slope.compareTo(slope)>0)
					east = !east;
			}
			return next.getPath(east, lines, currPath, firstRoad, nextPoint);
		}

		private Point intersect(Line l) {
			if(l.vert())
				return l.intersect(this);
			if(this.vert())
				return new Point(p1.x, l.valueAt(p1.x.num));
			Fraction dy = l.valueAt(p1.x.num).subtract(p1.y);
			Fraction dydx = slope.subtract(l.slope);
			Fraction dx = new Fraction(dy.num.multiply(dydx.den), dydx.num.multiply(dy.den));
			Fraction x = new Fraction(p1.x.num.multiply(dx.den).add(dx.num), dx.den);
			return new Point(x, valueAt(x));
		}

		private Fraction valueAt(long x) {
			return new Fraction(p1.y.num.multiply(slope.den).add((BigInteger.valueOf(x).subtract(p1.x.num)).multiply(slope.num)), slope.den);
		}

		private Fraction valueAt(BigInteger x) {
			return new Fraction(p1.y.num.multiply(slope.den).add(x.subtract(p1.x.num).multiply(slope.num)), slope.den);
		}

		private Fraction valueAt(Fraction x) {
			Fraction dx = x.subtract(p1.x);
			Fraction dy = slope.product(dx);
			return p1.y.add(dy);
		}

		public long longValueAt(long x) {
			if((x-p1.x.num.longValue()) % slope.den.longValue() == 0)
				return p1.y.num.longValue() + (x-p1.x.num.longValue()) * slope.num.longValue() / slope.den.longValue();
			else
				return Long.MIN_VALUE;
		}
		public boolean vert() {
			return slope.den.equals(BigInteger.ZERO);
		}
	}

	private static class Point
	{
		Fraction x;
		Fraction y;
		public Point(long x, long y)
		{
			this.x = new Fraction(x,1L);
			this.y = new Fraction(y,1L);
		}

		public Point(Fraction x, Fraction y)
		{
			this.x = x;
			this.y = y;
		}
	}

	private static class Fraction implements Comparable<Fraction>
	{
		BigInteger num;
		BigInteger den;
		public Fraction(long num, long den)
		{
			long gcd = gcd(Math.abs(num), Math.abs(den));
			if(den<0)
				gcd*=-1;
			this.num = BigInteger.valueOf(num/gcd);
			this.den = BigInteger.valueOf(den/gcd);
		}
		public Fraction add(Fraction that) {
			return new Fraction(num.multiply(that.den).add(that.num.multiply(den)), den.multiply(that.den));
		}
		public Fraction(BigInteger num, BigInteger den) {
			if(den.signum() == -1)
			{
				num = num.negate();
				den = den.negate();
			}
			BigInteger gcd = num.gcd(den);
                        if(gcd.equals(BigInteger.ZERO))
                                gcd = BigInteger.ONE;
			this.num = num.divide(gcd);
			this.den = den.divide(gcd);
		}
		public Fraction product(Fraction that) {
			return new Fraction(num.multiply(that.num), den.multiply(that.den));
		}
		public Fraction subtract(Fraction that) {
			return new Fraction(num.multiply(that.den).subtract(that.num.multiply(den)), den.multiply(that.den));
		}
		@Override
		public int compareTo(Fraction that) {
			return num.multiply(that.den).compareTo(that.num.multiply(den));
		}

		public String toString()
		{
			return "" + num + "/" + den;
		}
	}

	public static long gcd(long a, long b)
	{
		if(b>a)
			return gcd(b, a);
		if (b==0)
			return a;
		return gcd(b,a%b);
	}
}
