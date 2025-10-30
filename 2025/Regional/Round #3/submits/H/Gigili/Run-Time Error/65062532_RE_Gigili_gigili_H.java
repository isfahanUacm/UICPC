import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

//        Queue<String> q1 = new LinkedList<>();
//        Queue<String> q2 = new LinkedList<>();
//        Queue<String> q3 = new LinkedList<>();

        String str1 = sc.nextLine();
        String str2 = sc.nextLine();
        String str3 = sc.nextLine();

        int[] result = new int[(str1.length() + str2.length() + str3.length()) / 2];

        int i = 0, j = 0, k = 0, counter = 0;
        for (int index = 0; index < result.length; index++)
        {
            if (str1.charAt(i) == str2.charAt(j))
            {
                result[counter++] = Character.getNumericValue(str1.charAt(i));
                i++;
                j++;
            }
            else if (str1.charAt(i) == str3.charAt(k))
            {
                result[counter++] = Character.getNumericValue(str1.charAt(i));
                i++;
                k++;
            }
            else if (str2.charAt(j) == str3.charAt(k))
            {
                result[counter++] = Character.getNumericValue(str3.charAt(k));
                k++;
                j++;
            }
        }

        for( int l = 0; l < result.length; l++)
            System.out.print(result[l]);

    }
}