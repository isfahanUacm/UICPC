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
        cin.nextLine();
        for ( i = 0; i < s; i++) {
             String str = cin.nextLine();
             if (str.contains(p)){
                 System.out.println("KEEP");
                 i++;
                 break;
             }
             else System.out.println("REMOVE");
        }
        for (int j = i; j < s; j++) {
            String string = cin.nextLine();
            System.out.println("REMOVE");
        }
    }
}