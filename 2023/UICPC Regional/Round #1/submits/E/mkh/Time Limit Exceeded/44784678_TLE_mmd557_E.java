import java.util.*;


public class Main {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        String reg = sc.nextLine();
        reg = reg.replaceAll("\\.", "\\\\.");
        reg = reg.replaceAll("\\*", ".*");
        int a = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < a; i++) {
            String tmp = sc.nextLine();
            if (tmp.matches(reg)) {
                System.out.println(tmp);
            }
        }
    }
}

