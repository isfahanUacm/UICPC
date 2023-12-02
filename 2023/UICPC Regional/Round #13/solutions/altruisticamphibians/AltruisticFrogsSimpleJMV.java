import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StreamTokenizer;

import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.sort;
import static java.util.Comparator.comparingInt;

public class AltruisticFrogsSimpleJMV {

    public static void main(String[] args) throws IOException {
        StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
        in.nextToken();
        int n = (int) in.nval;
        in.nextToken();
        int depth = (int) in.nval;
        Frog[] frogs = new Frog[n];
        for (int i = 0; i < n; i++) {
            in.nextToken();
            int leap = (int) in.nval;
            in.nextToken();
            int weight = (int) in.nval;
            in.nextToken();
            int height = (int) in.nval;
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
