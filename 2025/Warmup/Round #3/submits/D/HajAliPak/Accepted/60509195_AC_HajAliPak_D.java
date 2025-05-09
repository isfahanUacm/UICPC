
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int zz = input.nextInt();
        int nexts = input.nextInt();
        input.nextLine();
        String now = input.nextLine();


        String binary = String.format("%8s", Integer.toBinaryString(zz)).replace(' ', '0');


        int[] arr = new int[8];
        for (int i = 0; i < 8; i++) {
            arr[i] = binary.charAt(7 - i) - '0';
        }

        for (int g = 0; g < nexts; g++) {
            StringBuilder next = new StringBuilder();
            for (int i = 0; i < now.length(); i++) {
                char left = (i == 0) ? '0' : (now.charAt(i - 1) == 'X' ? '1' : '0');
                char mid = now.charAt(i) == 'X' ? '1' : '0';
                char right = (i == now.length() - 1) ? '0' : (now.charAt(i + 1) == 'X' ? '1' : '0');

                String xx = "" + left + mid + right;
                int yyyy = Integer.parseInt(xx, 2);
                next.append(arr[yyyy] == 1 ? 'X' : '.');
            }
            System.out.println(next.toString());
            now = next.toString();
        }
    }
}
