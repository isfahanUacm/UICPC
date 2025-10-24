import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long n = in.nextLong();
        long cal = in.nextLong();
        long ama = in.nextLong();
        String lang = in.next();
        long operations = n * (2 * cal + 5 * ama);
        long memory = n * ama;
        long time;
        if (lang.equals("cpp")) time = (long) (5 * Math.pow(10 , 8));
        else if (lang.equals("java")) time = (long) Math.pow(10,8);
        else time = (long) (2*Math.pow(10 , 7));
        long memLimit = (long) (2 * Math.pow(10 , 7));
        boolean tl = operations > time;
        boolean ml = memory > memLimit;
        if (tl && ml) System.out.println("TL and ML");
        else if (tl) System.out.println("TL");
        else if (ml) System.out.println("ML");
        else System.out.println("OK");
    }
}
