import java.util.Scanner;

public class mees {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		if(n % 4 == 0) {
            System.out.print((n/4)+1);
            System.out.print(" ");
            System.out.println((n/4)-1);
        }
        else if(n % 2 == 1) {
            System.out.print((n+1)/2);
            System.out.print(" ");
            System.out.println((n-1)/2);
        }
        else {
            System.out.println("impossible");
        }
	}
}
