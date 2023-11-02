public class AddHelp_jmv {
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		for (int t = Integer.parseInt(in.nextLine()); --t >= 0; ) {
			String s = in.nextLine().trim();
			if (s.equals("P=NP")) System.out.println("skipped");
			else {
				int x = 0, y = 0, i = 0; 
				for ( ; s.charAt(i) != '+'; i++)
					x = x * 10 + s.charAt(i) - '0';
				for ( ; ++i < s.length(); )
					y = y * 10 + s.charAt(i) - '0';
				System.out.println(x + y);
			}
		}
	}
}