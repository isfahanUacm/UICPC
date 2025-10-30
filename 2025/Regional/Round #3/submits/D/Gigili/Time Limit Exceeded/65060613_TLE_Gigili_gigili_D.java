import java.util.LinkedList;
import java.util.Objects;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String[] strings = str.split("");

        int len = strings.length;
        for (int i = 0; i < strings.length; i++) {
            for (int j = i + 1; j < strings.length; j++) {

                if ( strings[i] != "*" && Objects.equals(strings[i], strings[j])) {
                    len -= 2;
                    strings[i] = "*";
                    strings[j] = "*";
                    break;
                }
            }
        }

        if (len == 0 || len == 1)
            System.out.println("yes");
        else
            System.out.println("no");
    }
}