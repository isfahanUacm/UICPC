import java.util.LinkedList;
import java.util.Objects;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String[] strings = str.split("");
        
        for (int i = 0; i < strings.length; i++) {
            for (int j = i + 1; j < strings.length; j++) {

                if (Objects.equals(strings[i], strings[j])) {
                    strings[i] = "*";
                    strings[j] = "*";
                }
            }
        }

        int counter = 0;
        for (int i = 0; i < strings.length; i++)
        {
            if (!Objects.equals(strings[i], "*"))
                counter++;
        }

        if (counter == 0 || counter == 1)
            System.out.println("yes");
        else
            System.out.println("no");
    }
}