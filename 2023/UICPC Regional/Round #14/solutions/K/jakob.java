// @EXPECTED_RESULTS@: CORRECT

import java.math.BigInteger;
import java.util.Scanner;
public class jakob {

	public static void debug(String s) {
		if (false) System.err.println(s);
	}
	
	public static void myAssert(boolean b) {
		if(!b)
			System.exit(1);
	}
	
	static class rational {
		public final BigInteger zaehler, nenner;
		public rational(int n) {
			zaehler = BigInteger.valueOf(n);
			nenner = BigInteger.ONE;
		}
		private rational(BigInteger zaehler, BigInteger nenner) {
			myAssert( !nenner.equals(BigInteger.ZERO));
			if(nenner.signum() == -1) {
				nenner = nenner.negate();
				zaehler = zaehler.negate();
			}
			BigInteger ggt = zaehler.equals(BigInteger.ZERO) ? nenner : zaehler.gcd(nenner);
			this.zaehler = zaehler.divide(ggt);
			this.nenner = nenner.divide(ggt);
		}
		public boolean isZero() {
			return zaehler.equals(BigInteger.ZERO);
		}
		public boolean equals(Object o) {
			return o instanceof rational 
				&& ((rational)o).nenner.equals(nenner)
				&& ((rational)o).zaehler.equals(zaehler);
		}
		public int compareTo(rational r) {
			// int mys = zaehler.signum();
			// int rs = r.zaehler.signum();
			// if(rs != mys) {
			// 	return mys < rs ? -1 : 1;
			// }
			BigInteger mm = this.zaehler.multiply(r.nenner);
			BigInteger rm = r.zaehler.multiply(this.nenner);
			return mm.compareTo(rm);
		}
		public static final rational ONE = new rational(1);
		public static final rational ZERO = new rational(0);
		public String toString() {
			if(nenner.equals(BigInteger.ONE))
			return zaehler.toString();
			return zaehler +"/" + nenner;
		}
	}

	public static rational add(rational a, rational b) {
		return new rational(a.zaehler.multiply(b.nenner).add(b.zaehler.multiply(a.nenner)),
		                    a.nenner.multiply(b.nenner));
	}
	public static rational sub(rational a, rational b) {
		return new rational(a.zaehler.multiply(b.nenner).subtract(b.zaehler.multiply(a.nenner)),
		                    a.nenner.multiply(b.nenner));
	}
	public static rational mul(rational a, rational b) {
		return new rational(a.zaehler.multiply(b.zaehler), 
		                    a.nenner.multiply(b.nenner));
	}
	public static rational div(rational a, rational b) {
		return new rational(a.zaehler.multiply(b.nenner), 
		                    a.nenner.multiply(b.zaehler));
	}
	
	public static vec3 cross(vec3 a, vec3 b) {
		return new vec3(sub(mul(a.y,b.z), mul(a.z,b.y)),
		                sub(mul(a.z,b.x), mul(a.x,b.z)),
		                sub(mul(a.x,b.y), mul(a.y,b.x)));
	}

	public static rational scal(vec3 a, vec3 b) {
		return add(add(mul(a.x, b.x), mul(a.y, b.y)), mul(a.z, b.z));
	}

	public static vec3 mul(vec3 a, rational b) {
		return new vec3(mul(a.x,b), mul(a.y,b), mul(a.z,b));
	}

	public static vec3 add(vec3 a, vec3 b) {
		return new vec3(add(a.x,b.x), add(a.y,b.y), add(a.z,b.z));
	}

	public static vec3 sub(vec3 a, vec3 b) {
		return new vec3(sub(a.x,b.x), sub(a.y,b.y), sub(a.z,b.z));
	}
	

	static class vec3 {
		public final rational x, y, z;
		public vec3(int x, int y, int z) {
			this.x = new rational(x);
			this.y = new rational(y);
			this.z = new rational(z);
		}
		public vec3(rational x, rational y, rational z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}
		public boolean isZero() {
			return x.isZero() && y.isZero() && z.isZero();
		}
		public boolean equals(Object o) {
			return o instanceof vec3 && sub(((vec3)o), this).isZero();
		}
		public String toString() {
			return "[" + x + "," + y + "," + z + "]";
		}
	}

	static class plane {
		public final vec3 lot;
		public final rational offset;
		public plane(vec3 lot, rational offset) {
			this.lot = lot;
			this.offset = offset;
		}
		public plane(vec3 a, vec3 b, vec3 c) {
			vec3 bma = sub(b, a);
			vec3 cma = sub(c, a);
			vec3 ll = cross(bma, cma);
			lot = cross(sub(b, a), sub(c, a));
			offset = scal(a, lot);
		}
		public String toString() {
			return "{ x * " + lot + " = "  + offset + " }";
		}
	}
	
	static class line {
		public final vec3 base, direction;
		public line(vec3 base, vec3 direction) {
			this.base = base;
			this.direction = direction;
		}
		public rational linecoord(vec3 v) {
			return div(sub(scal(v, direction), scal(base, direction)), scal(direction, direction));
		}
		public String toString() {
			return "{ x = " + base + " + k * " + direction + " }";
		}
	}

	static class segment {
		public final vec3 start, end;
		public segment(vec3 start, vec3 end) {
			this.end = end;
			this.start = start;
		}
		public String toString() {
			return "{ x = k * " + start + " + (1-k) * " + end + ", 0<=k<=1}";
		}
	}

	static enum cut {
		NONE, ONE, MANY;
	}

	static vec3 cutpoint;

	static cut intersects(plane p, line l) {
		cutpoint = null;
		if(scal(l.direction, p.lot).isZero()) {
			if(scal(l.base, p.lot).equals(p.offset)) {
				return cut.MANY;
			}
			return cut.NONE;
		}
		rational baseOff = scal(p.lot, l.base);
		rational dirLen = scal(p.lot, l.direction);
		rational x = sub(div(p.offset, dirLen), div(baseOff, dirLen));
		cutpoint = add(l.base, mul(l.direction, x));
		return cut.ONE;
	} 

	static cut intersects(plane p, segment s) {
		line l = new line(s.start, sub(s.end, s.start));
		cut cc = intersects(p, l);
		if(cc == cut.MANY || cc == cut.NONE) 
			return cc;
		rational linecoord = l.linecoord(cutpoint);
		if(rational.ZERO.compareTo(linecoord) <= 0 && linecoord.compareTo(rational.ONE) <= 0)
			return cut.ONE;
		cutpoint = null;
		return cut.NONE;
	} 

	static cut intersects(segment a, segment b) {
		line la = new line(a.start, sub(a.end, a.start));
		line lb = new line(b.start, sub(b.end, b.start));
		vec3 dircross = cross(la.direction, lb.direction);
		vec3 a2b = sub(b.start, a.start);
		if(dircross.isZero()) { // parallel
			if(cross(la.direction, a2b).isZero()) { // ... lines have no distance
				rational astartinb = lb.linecoord(a.start);
				rational aendinb = lb.linecoord(a.end);
				int cr = astartinb.compareTo(aendinb);
				if(cr > 0) {
					rational tmp = astartinb;
					astartinb = aendinb;
					aendinb = tmp;
				}
				int aso = astartinb.compareTo(rational.ONE);
				int aez = aendinb.compareTo(rational.ZERO);
				
				if(aez < 0) {
					return cut.NONE;
				}
				if(aez == 0) {
					return cut.ONE;
				}
				if(aso > 0) {
					return cut.NONE;
				}
				if(aso == 0) {
					return cut.ONE;
				}
				return cut.MANY;
			} else { // ... lines have distance
				return cut.NONE;
			}
		} else { // not parallel
			if(!scal(la.base, dircross).equals(scal(lb.base, dircross))) { // windschief
				return cut.NONE;
			}
			vec3 p1 = la.base;
			vec3 p2 = add(la.base, la.direction);
			vec3 p3 = add(la.base, dircross);
			plane pp = new plane(p1, p2, p3);
			cut c2 = intersects(pp, lb);
			myAssert (c2 == cut.ONE);
			vec3 sec = cutpoint;
			rational lca = la.linecoord(sec);
			rational lcb = lb.linecoord(sec);
			if(rational.ZERO.compareTo(lca) <= 0 && lca.compareTo(rational.ONE) <= 0
			   && rational.ZERO.compareTo(lcb) <= 0 && lcb.compareTo(rational.ONE) <= 0)
				return cut.ONE;
			cutpoint = null;
			return cut.NONE;
		}
	}

	static class triangle {
		public final vec3 a, b, c;
		public triangle(vec3 a, vec3 b, vec3 c) {
			this.a = a;
			this.b = b;
			this.c = c;
		}
		public String toString() {
			return "{ x = k * " + a + " + l * " + b + " + m * "+ c + ", 0<=k,l,m<=1, k+l+m==1}";
		}
	}

	static boolean pointInTriangle(triangle t, vec3 p) {
		plane tp = new plane(t.a, t.b, t.c);
		if(!scal(tp.lot, p).equals(tp.offset))
			return false; 
		// now we know p is in t's plane.
		{
			vec3 ab = sub(t.b, t.a), ac = sub(t.c, t.a), ap = sub(p, t.a);
			vec3 abxac = cross(ab, ac);
			vec3 abxap = cross(ab, ap);
			vec3 apxac = cross(ap, ac);
			myAssert (!abxac.isZero());
			rational tbp = scal(abxac, abxap), tpc1 = scal(abxac, apxac);
			if(tbp.compareTo(rational.ZERO) < 0 || tpc1.compareTo(rational.ZERO) < 0)
				return false;
		}
		{
			vec3 ba = sub(t.a, t.b), bc = sub(t.c, t.b), bp = sub(p, t.b);
			vec3 baxbc = cross(ba, bc);
			vec3 baxbp = cross(ba, bp);
			vec3 bpxbc = cross(bp, bc);
			myAssert( !baxbc.isZero());
			rational tap = scal(baxbc, baxbp), tpc2 = scal(baxbc, bpxbc);
			if(tap.compareTo(rational.ZERO) < 0 || tpc2.compareTo(rational.ZERO) < 0)
				return false;
		}
		return true;
	}

	static int nincuts = 0;
	static int noutcuts = 0;
	static vec3[] x = new vec3[3];
	static boolean sideinplane = false;

	static void f(plane pplane, triangle ptri, segment q) {
		debug("checking " + q + " against " + ptri);
		cut cc = intersects(pplane, q);
		if(cc == cut.ONE) {
			vec3 section = cutpoint;
			if(pointInTriangle(ptri, section)) {
				debug("... intersects " + ptri + " at " + section);
				nincuts++;
			} else {
				debug("... intersects " + pplane + " at " + section + " but is not in triangle");
				noutcuts++;
			}
		} else if(cc == cut.MANY) {
			debug("... intersects " + pplane + " multiple times");
			sideinplane = true;
		} else {
			debug("... does not intersect " + pplane);
		}
	}

	public static void main(String args[] ) {
		Scanner s = new Scanner(System.in);
		int ntc = s.nextInt();
		for(int tc = 0; tc < ntc; tc++) {
			vec3 p1 = new vec3( s.nextInt(), s.nextInt(), s.nextInt());
			vec3 p2 = new vec3( s.nextInt(), s.nextInt(), s.nextInt());
			vec3 p3 = new vec3( s.nextInt(), s.nextInt(), s.nextInt());
			vec3 q1 = new vec3( s.nextInt(), s.nextInt(), s.nextInt());
			vec3 q2 = new vec3( s.nextInt(), s.nextInt(), s.nextInt());
			vec3 q3 = new vec3( s.nextInt(), s.nextInt(), s.nextInt());
			
			triangle ptri = new triangle(p1, p2, p3);
			plane pplane = new plane(p1, p2, p3);
			segment qa = new segment(q1, q2);
			segment qb = new segment(q2, q3);
			segment qc = new segment(q3, q1);
			{
				segment pa = new segment(p1, p2);
				segment pb = new segment(p2, p3);
				segment pc = new segment(p3, p1);
				myAssert (intersects(pa, qa) == cut.NONE);
				myAssert (intersects(pa, qb) == cut.NONE);
				myAssert (intersects(pa, qc) == cut.NONE);
				myAssert (intersects(pb, qa) == cut.NONE);
				myAssert (intersects(pb, qb) == cut.NONE);
				myAssert (intersects(pb, qc) == cut.NONE);
				myAssert (intersects(pc, qa) == cut.NONE);
				myAssert (intersects(pc, qb) == cut.NONE);
				myAssert (intersects(pc, qc) == cut.NONE);
			}
			nincuts = 0;
			noutcuts = 0;
			sideinplane = false;
			f(pplane, ptri, qa);
			f(pplane, ptri, qb);
			f(pplane, ptri, qc);
			
			if(sideinplane) {
				System.out.println("NO");
			} else {
				if(nincuts != 0 && noutcuts != 0) {
					System.out.println("YES");				
				} else {
					System.out.println("NO");
				}
			}
		}
	}
}
