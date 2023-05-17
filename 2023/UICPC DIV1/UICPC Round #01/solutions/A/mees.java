import java.util.Scanner;

public class mees {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

        int m = sc.nextInt();
        int n = sc.nextInt();
        int max1 = 0;
        int max2 = 0;
		
        for(int i = 0; i < m; i++) {
            int k = sc.nextInt();
            if(k > max1) {
                max1 = k;
            }
        }
        for(int i = 0; i < n; i++) {
            int k = sc.nextInt();
            if(k > max2)
                max2 = k;
        }

        if(max1 == max2) {
            System.out.println("possible");
        }
        else {
            System.out.println("impossible");
        }
	}
}
