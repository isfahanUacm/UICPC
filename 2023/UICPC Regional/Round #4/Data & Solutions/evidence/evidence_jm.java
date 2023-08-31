import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Scanner;

public class evidence_jm {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
				
		int n = in.nextInt(), r = in.nextInt();
		double[] x = new double[n], y = new double[n];
		for (int i = 0; i < n; i++)
		{			
			x[i] = Double.parseDouble(in.next());
			y[i] = Double.parseDouble(in.next());			
		}

		double bestAngle = 0.0, bestX = 0, bestY = 0;

		double[] start = new double[n], stop = new double[n];
		for (int i = 0; i < n; i++)
		{
			int j = (i + 1)%n;
			double dx = x[j] - x[i], dy = y[j] - y[i];
			double a = dx*dx + dy*dy, b = 2*(dx*x[i] + dy*y[i]), c = x[i]*x[i] + y[i]*y[i] - r*r;
			double[] result = QuadraticEquation(a,b,c);
			double px1 = x[i] + result[0]*dx, py1 = y[i] + result[0]*dy;
			double px2 = x[i] + result[1]*dx, py2 = y[i] + result[1]*dy;
			start[i] = Math.atan2(py2, px2); // Start/stop angle where line becomes
			stop[i] = Math.atan2(py1, px1);  // visible from fence
		}

		for (int i = 0; i < n; i++)
		{
			int t = i;
			while (true)
			{
				double lo = start[t], hi = stop[i];
				if (hi < lo) hi += 2*Math.PI;
				double angle = 0.0;
				while (hi - lo > 1e-6)
				{
					double x1 = (hi - lo)/3 + lo;
					double x2 = (hi - lo)/3*2 + lo;
					double va1 = GetViewAngle(x[i], y[i], x[(t + 1)%n], y[(t + 1)%n], x1, r);
					double va2 = GetViewAngle(x[i], y[i], x[(t + 1)%n], y[(t + 1)%n], x2, r);
					angle = Math.max(va1, va2);
					if (va1 > va2)
						hi = x2;
					else
						lo = x1;
				}
				if (angle > bestAngle)
				{
					bestAngle = angle;
					bestX = Math.cos(lo)*r;
					bestY = Math.sin(lo)*r;
				}

				double dif = start[(t + 1) % n] - stop[i];
				if (dif > Math.PI) dif -= 2 * Math.PI;
				if (dif < -Math.PI) dif += 2 * Math.PI;
				if (dif > 0)
					break;
				
				t = (t + 1)%n;
			}
		}

		NumberFormat format = new DecimalFormat("0.00000000");		
		//System.out.println(format.format(bestX).replace(",", ".") + " " + format.format(bestY).replace(",", "."));
    assert(0 <= bestAngle && bestAngle < 2*Math.PI);
		System.out.printf("%.10f\n", bestAngle);
	}
	
	public static double GetViewAngle(double px1, double py1, double px2, double py2, double a, double r)
	{
		double qx = Math.cos(a)*r, qy = Math.sin(a)*r;
		double vx1 = qx - px1, vy1 = qy - py1, vx2 = qx - px2, vy2 = qy - py2;
		double d = (vx1 * vx2 + vy1 * vy2) / (Math.sqrt(vx1 * vx1 + vy1 * vy1) * Math.sqrt(vx2 * vx2 + vy2 * vy2));
		double angle = Math.acos(d);
		return angle;
	}

	public static double[] QuadraticEquation(double a, double b, double c)
	{
		double d = b * b - 4 * a * c;
		if (d < 0)
			return null;
		d = Math.sqrt(d);
		return new double[] { (-b + d) / (2 * a), (-b - d) / (2 * a) };
	}

}
