public class Raffle_jmv {

	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		final double n = in.nextDouble(), p = in.nextDouble();
		
		/*
		 * The chances of winning, with m ballots, are (nC(p-1)*m)/(n+m)Cp. 
		 * Going from m to m + 1 changes the odds by a factor 
		 * ((m + 1) / m) / ((n + m + 1) / (n + m + 1 - p)). 
		 * This factor decreases with increasing m, so the answer is found
		 * by iterating over m, from m = 1, until the odds start decreasing. 
		 * The chances of winning with a single ballot are p / (n + 1). 
		 */
		
		double c = p / (n + 1);
		for (double m = 1, o; (o = (m + 1) * (n + m + 1 - p) / (m * (n + m + 1))) > 1; c *= o, m++);
		
		System.out.format("%.8e\n", c);
		
		in.close();
	}
}
