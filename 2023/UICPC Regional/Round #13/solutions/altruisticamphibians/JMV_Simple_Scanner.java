import java.util.Scanner;

import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.sort;
import static java.util.Comparator.comparingInt;

public class JMV_Simple_Scanner {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int depth = in.nextInt();
        Frog[] frogs = new Frog[n];
        for (int i = 0; i < n; i++) {
            int leap = in.nextInt();
            int weight = in.nextInt();
            int height = in.nextInt();
            frogs[i] = new Frog(leap, weight, height);
        }
        sort(frogs, comparingInt(Frog::weight).thenComparingInt(Frog::height).reversed());
        int[] tower = new int[100_000_001];
        int saved = 0;

        for (Frog frog : frogs) {
            for (int w = frog.weight + 1; w < 2 * frog.weight && w < 100_000_001; w++)
                tower[w - frog.weight] = max(tower[w - frog.weight], min(depth, tower[w] + frog.height));

            if (tower[frog.weight] + frog.leap > depth)
                saved++;
        }
        System.out.println(saved);
    }

    static class Frog {

        private final int leap, weight, height;

        Frog(int leap, int weight, int height) {
            this.leap = leap;
            this.weight = weight;
            this.height = height;
        }

        int leap() { return leap; }
        int weight() { return weight; }
        int height() { return height; }

    }

}
