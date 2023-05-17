import java.util.Scanner;

public class mees {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
        int k = sc.nextInt();

        double old_ex = 0.0;

        for(int i = 0; i < k; i++) {
            double new_ex = 0.0;
            for(int j = 1; j <= n; j++) {
                if(j > old_ex)
                    new_ex += j;
                else
                    new_ex += old_ex;
            }
            new_ex = new_ex / n;
            old_ex = new_ex;
        }

        System.out.println(old_ex);
	}
}
