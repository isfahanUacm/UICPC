import java.util.Scanner;

public class Main{
        public static void main(String[] args) {


                Scanner sc = new Scanner(System.in);
                int n = sc.nextInt(), q = sc.nextInt();
                int[] a = new int[n];
                for (int i = 0; i < n; i++) a[i] = sc.nextInt();
                
                while (q-- > 0) {
                    int t = sc.nextInt(), l = sc.nextInt() - 1, r = sc.nextInt() - 1;
                    if (t == 3) {
                        int s = 0;
                        for (int i = l; i <= r; i++) s += a[i];
                        System.out.println(s);
                    } else {
                        int x = sc.nextInt();
                        for (int i = l; i <= r; i++)a[i] = (t == 1) ? a[i] % x : Math.max(a[i], x);
                    }
                }

                
    }//EndMain
}//EndClass