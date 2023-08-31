/* Sample solution to NCPC 2008 B: Best compression ever
 * by Mikael Goldmann
 */
import java.util.Scanner;

public class compression_mg {

    public static Scanner in = new Scanner(System.in);

    public static void main(String[] a) {
	long N = in.nextLong();
	int b = in.nextInt();
	System.out.println(N <= (1L<<(b+1))-1 ? "yes" : "no");
    }
}
