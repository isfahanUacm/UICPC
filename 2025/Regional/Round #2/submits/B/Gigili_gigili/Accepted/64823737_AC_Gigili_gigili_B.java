import java.util.Arrays;
import java.util.Objects;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int p = sc.nextInt();

        sc.nextLine();
        int[][] result = new int[p][3];
        for (int[] value : result) Arrays.fill(value, 0);


        for (int i = 0; i < n; i++)
        {
            int index = 0;
            String input = sc.nextLine();
            String[] str = input.split(" ");
            for (int j = 0; j < p * 2; j+=2)
            {
                if (Objects.equals(str[j], "+")){
                    result[index][0]++;
                    result[index][1]++;
                }
                else if (Objects.equals(str[j], "-"))
                {
                    if (!Objects.equals(str[j + 1], "0"))
                        result[index][1] ++;
                }

                int attempt = Integer.parseInt(str[j + 1]);
                result[index][2] += attempt;
                index++;
            }

        }

        for (int[] ints : result) {
            for (int anInt : ints) System.out.print(anInt + " ");
            System.out.println();
        }
    }
}