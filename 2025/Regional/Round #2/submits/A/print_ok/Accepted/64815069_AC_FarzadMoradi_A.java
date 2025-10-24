import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int be = in.nextInt();
        String s = in.next();
        if(s.equals("L")){
            if(be%2==1){
                System.out.print(be/2 + 1 + " ");
                System.out.print(be/2 + 1 + " ");
                System.out.print(n - be);
            }
            else{
                System.out.print(be/2 + " ");
                System.out.print(be/2 + " ");
                System.out.print(n - be + " ");
            }
        }
        else if(s.equals("R")){
            if(n-be%2==1){
                System.out.print(be -1 + " ");
                System.out.print((n - be)/2 + 1+" ");
                System.out.print((n - be)/2 + 1+" ");
            }
            else{
                System.out.print(be -1+" ");
                System.out.print((n - be)/2 +1 + " ");
                System.out.print((n - be)/2 +1 + " ");
            }
        }
    }
}