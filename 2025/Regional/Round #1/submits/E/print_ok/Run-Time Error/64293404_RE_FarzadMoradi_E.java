import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner ss = new Scanner(new File("ghanophobia.in"));
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 1; i <= n; i++) {
            String s = in.next();
            int a = s.charAt(0) - '0';
            int b = s.charAt(2) - '0';
            a = a + 2;
            b = 2*b + 6;
            if(a==b){
                System.out.println("Case " + i + ": PENALTIES" );
            }
            if(a<b){
                System.out.println("Case " + i + ": NO");
            }
            else if(a>b){
                System.out.println("Case " + i + ": YES");}
        }
    }
}