import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

// Zac's C++ solution
public class lootchest_da {

    private void work() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int LP = sc.nextInt(), WP = sc.nextInt();
        double G = sc.nextDouble(), L = sc.nextDouble();

        G *= 0.01;
        L *= 0.01;

        // em[p]: expected number of matches until a prize is received
        // if we start at probability p
        double[] em = new double[101];

        // em[100] = 1 + lose*em[100] + win*0 ==> em[100] = 1/win
        em[100] = 1 / (1 - L);
        for (int i = 99; i >= 0; --i) {
            // play a game:
            //   - if we lose then no prize but go up by LP
            //   - if we win but fail to get a prize, go up by WP
            // em[i] = 1 + lose*em[i+LP] + win*noprize*em[i+WP]
            em[i] = 1 + L * em[Math.min(i + LP, 100)] + (1 - L) * (1 - i * 0.01) * em[Math.min(i + WP, 100)];
        }

        // we play em[P] games to open the first prize pack
        // if it is not the gorilla suit, then every other attempt takes em[0] games
        double ans = em[0] / G;
        System.out.printf("%.12f\n", ans);
    }

    public static void main(String[] args) {
        new lootchest_da().work();
    }
}
