public class Compass_jmv {
    public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		int head1 = in.nextInt();
		int head2 = in.nextInt();
		int difference = head2 - head1; 
		if (difference > 180) difference -= 360;
		else if (difference <= -180) difference += 360;
		System.out.println(difference);
		in.close();
    }
}
