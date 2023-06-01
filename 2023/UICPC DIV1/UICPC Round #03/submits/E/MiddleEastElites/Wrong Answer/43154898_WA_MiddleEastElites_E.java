import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        long n;
        String p;
        long s;
        Scanner cin = new Scanner(System.in);
        n = cin.nextLong();
        p = cin.next();
        s = cin.nextLong();
        int i;
        for ( i = 0; i < s; i++) {
            cin.next();
             String str = cin.nextLine();
             if (str.contains(p)){
                 System.out.println("KEEP");
             }
             else System.out.println("REMOVE");
        }
     
    }
}