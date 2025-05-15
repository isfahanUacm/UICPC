import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            String s = sc.next();
            char[] num = s.toCharArray();
            int num1 = 0;

            for (int j = 0; j < num.length; j++) {
                if (num[j] == '0') {
                    num1++;
                }
            }
            int endzero = 0;
            for (int j = num.length - 1; j >= 0; j--) {
                if (num[j] == '0') {
                    endzero++;
                }
                else {
                    break;
                }
            }
            System.out.println(num.length - 1 - num1+endzero);
        }
    }
    static long aa(long num){
        int n = 0;
        while (num != 0){
            num /= 10;
            n++;
        }
        return n;
    }
}