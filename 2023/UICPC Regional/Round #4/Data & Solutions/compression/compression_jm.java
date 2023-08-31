import java.util.Scanner;


public class compression_jm {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		long n = in.nextLong();
		int b = in.nextInt();
		long maxInfo = 0;
		for (int i = 0; i <= b; i++)
			maxInfo += 1L << i;
		if (maxInfo >= n)
			System.out.println("yes");			
		else
			System.out.println("no");
	}

}
