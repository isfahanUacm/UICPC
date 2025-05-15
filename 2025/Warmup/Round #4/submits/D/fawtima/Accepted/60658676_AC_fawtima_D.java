import java.util.ArrayList;
import java.util.Scanner;
public class Main {
    public static void main(String[] arg) {
        Scanner sc =new Scanner(System.in);
        int v , k;
        int n = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();
        int button = 0;

        if(a == c && d > b) {
            button = d - b;
        }
        else if (c > a) {
            button = (((c-a)-1)*(n+1))+(n-b)+d+1;
        }
        System.out.println(button);


    }
}