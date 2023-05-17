import java.util.Scanner;

public class mees {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String s = sc.nextLine();
        int n = s.length();
        System.out.println("h" + s.substring(1, n-1) + s.substring(1, n-1) + "y");
	}
}
