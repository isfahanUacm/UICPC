
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();
        int[] nums = new int[m + 1];
        for (int i = 0; i < n; i++) {
            int x = input.nextInt();
            nums[x]++;
        }//End4j
        long sum = 0;
        long[] ans = new long[m + 1];
        for (int i = m; i >= 1; i--) {
            sum += (long) i * nums[i];
            ans[i] = sum;
        }//End4i2
        for (int i = 1; i <= m; i++) {
            System.out.print(ans[i] + " ");
        }//EndOutput
    }//EndMain
}//EndClass
