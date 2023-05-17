import java.util.Scanner;
import java.util.ArrayList;

public class mees_scanner {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
        int m = sc.nextInt();
        
        ArrayList<Integer> forward = new ArrayList<Integer>();
        ArrayList<Integer> backward = new ArrayList<Integer>();

        for(int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();

            if(a < b) {
                forward.add(i+1);
            }
            else {
                backward.add(i+1);
            }
        }

        if(forward.size() < backward.size()) {
            System.out.println(forward.size());

            for(int i = 0; i < forward.size(); i++) {
                System.out.println(forward.get(i));
            }
        }
        else {
            System.out.println(backward.size());

            for(int i = 0; i < backward.size(); i++) {
                System.out.println(backward.get(i));
            }

        }
	}
}
