import java.io.File;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.*;

public class bugs_jm {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
				
		int B = in.nextInt(), T = in.nextInt();		
		double f = Double.parseDouble(in.next());
				
		int[] bugSeverity = new int[B];
		ArrayList<Bug> bugList = new ArrayList<Bug>();
		for (int i = 0; i < B; i++)
		{			
			double fixProb = Double.parseDouble(in.next());
			int sev = in.nextInt();
			bugSeverity[i] = sev;
			for (int j = 0; j < T; j++)
			{
				bugList.add(new Bug(i, sev, fixProb, j));
				fixProb *= f;
			}
		}
			
		Collections.sort(bugList);		

		Bug[][] bugOrder = new Bug[1<<B][];
		for (int fixedMask = 0; fixedMask < (1 << B); fixedMask++)
		{
			int cnt = 0, j = 0;
			for (int i = 0; i < B; i++)
				if (((1 << i) & fixedMask) == 0) cnt++;
			bugOrder[fixedMask] = new Bug[cnt*T];
			for (Bug bug : bugList)
				if (((1 << bug.Index) & fixedMask) == 0)
					bugOrder[fixedMask][j++] = bug;
		}

		double[][] current = new double[1 << B][T + 1], old = new double[1 << B][T + 1];
		for (int fixedMask = 0; fixedMask < (1 << B); fixedMask++)
		{
			int severity = 0;
			for (int i = 0; i < B; i++)
				if (((1 << i) & fixedMask) > 0)
					severity += bugSeverity[i];
			for (int i = 0; i <= T; i++)
				current[fixedMask][i] = severity;
		}

		for (int timeLeft = 1; timeLeft <= T; timeLeft++)
		{
			double[][] tmp = old;
			old = current;
			current = tmp;
			for (int fixedMask = 0; fixedMask < (1 << B); fixedMask++)
			{
				for (int failures = T; failures >= Math.min(T, bugOrder[fixedMask].length); failures--)
					current[fixedMask][failures] = old[fixedMask][failures];

				for (int failures = Math.min(T, bugOrder[fixedMask].length) - 1; failures >= 0; failures--)
				{
					int mask = 1 << bugOrder[fixedMask][failures].Index;
					double fixProb = bugOrder[fixedMask][failures].FixProb;
					double v1 = old[fixedMask | mask][failures - bugOrder[fixedMask][failures].TryNo] * fixProb;
					double v2 = old[fixedMask][failures + 1]*(1.0 - fixProb);
					current[fixedMask][failures] = v1 + v2;
				}
			}
		}

		double answer = current[0][0];

		NumberFormat format = new DecimalFormat("0.000000");
		System.out.println(format.format(answer).replace(",", "."));
	}
	
	public static class Bug implements Comparable<Bug>
	{
		public int Index;
		public int Severity;
		public double FixProb;
		public int TryNo;

		public Bug(int index, int severity, double fixProb, int tryNo)
		{
			Index = index;
			Severity = severity;
			FixProb = fixProb;
			TryNo = tryNo;
		}

		public int compareTo(Bug other)
		{
			if (Index == other.Index)
				return TryNo - other.TryNo;
			double x = Severity*FixProb, y = other.Severity*other.FixProb;
			if (Math.abs(x-y) < 1e-8)
				return TryNo - other.TryNo;
			if (x < y)
				return 1;
			return -1;			
		}
	}
	
}

