import java.util.Arrays;
import java.util.Scanner;

public class gift_da {
    private void work() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong() - 1;
        sc.close();

        long[] f = new long[21];
        f[0] = f[1] = 1;
        for(int i = 2; i < f.length; i++) f[i] = f[i-1] * i;

        int s = 0;
        int cur = n - 2;
        boolean[] m = new boolean[n];

        while(cur > 20){
            s++;
            m[s] = true;
            cur--;
            System.out.print("1 ");
        }

        while(cur >= 0){
            long pos = k / f[cur];
            k %= f[cur];

            int dig = 0;
            for(int x = 0; x <= pos; x++){
                dig++;
                int next = dig + s;
                if(next >= n) next -= n;
                while(next == 0 || m[next]){
                    dig++;
                    next++;
                    if(next == n) next = 0;
                }
            }

            s += dig;
            if(s >= n) s-=n;
            m[s] = true;

            System.out.print(dig);
            if(cur > 0) System.out.print(" ");
            cur--;
        }

        System.out.println();
    }

    public static void main(String[] args) {
        new gift_da().work();
    }
}
