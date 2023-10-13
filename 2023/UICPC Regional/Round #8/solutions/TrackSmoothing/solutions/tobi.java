// @EXPECTED_RESULTS@: CORRECT

import java.util.*;
import java.awt.geom.Point2D;
import java.awt.geom.Point2D.Double;

public class tobi {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int numCases = sc.nextInt();

		while (numCases --> 0) {
			int radius = sc.nextInt();
			int numPoints = sc.nextInt();

			Point2D.Double last = new Point2D.Double(sc.nextInt(), sc.nextInt());
			Point2D.Double first = last;

			double o = 0;
			for (int i = 1; i < numPoints; i++) {
				Point2D.Double cur = new Point2D.Double(sc.nextInt(), sc.nextInt());
				o += cur.distance(last);
				last = cur;
			}
			o += last.distance(first);

			double c = 2. * Math.PI * radius;
			if (c > o) {
				System.out.println("Not possible");
			} else {
				System.out.println((o-c)/o);
			}
		}
	}
}
