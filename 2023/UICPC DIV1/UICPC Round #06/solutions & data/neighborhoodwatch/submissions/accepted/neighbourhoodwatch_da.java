import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class neighbourhoodwatch_da {

    private void work() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        // try (Scanner sc = new Scanner(new BufferedReader(new FileReader("nw/neighbourhoodwatch-20.in")))) {
        long n = sc.nextLong();
        int k = sc.nextInt();
        boolean[] road = new boolean[(int) n + 1];
        road[(int) n] = true;
        while (k-- > 0) {
            road[sc.nextInt() - 1] = true;
        }

        sc.close();

        long res = n * (n + 1) / 2;
        int last = -1;
        for (int i = 0; i <= n; i++) {
            if (road[i]) {
                long x = i - last;
                res -= x * (x - 1) / 2;
                last = i;
            }
        }

        System.out.println(res);
/*            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }*/
}

    public static void main(String[] args) {
        new neighbourhoodwatch_da().work();
    }
}
