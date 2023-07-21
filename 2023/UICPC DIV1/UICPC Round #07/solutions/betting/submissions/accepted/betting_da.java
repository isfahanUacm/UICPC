import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class betting_da {

    private void work(){
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int a = sc.nextInt();
	//        int b = sc.nextInt();
	int b = 100-a;
        System.out.printf("%.4f\n%.4f\n", 100.0/a, 100.0/b);
    }

    public static void main(String[] args) {
        new betting_da().work();
    }
}
