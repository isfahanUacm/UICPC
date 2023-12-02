import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StreamTokenizer;

import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.sort;
import static java.util.Comparator.comparingInt;

public class AltruisticFrogsJMV {

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
        sort(frogs, comparingInt(Frog::weight).thenComparingInt(Frog::height));

        // Rolled-out navigable map<int, int> :scream:
        // This map will have strictly increasing values with and decreasing keys.
        int[] tower = new int[1_000_000], swap = new int[1_000_000], tmp;

        // Add a guard on the low end.
        int t = 0;
        tower[t++] = 1 << 30;
        tower[t++] = 0;

        int saved = 0;
        for (int f = frogs.length - 1; f >= 0 ; ) {
            int weight = frogs[f].weight, height = frogs[f].height;

            // Put the largest, relevant (capacity, help) in swap.
            int s = 0, g = 0, max = 0;
            for ( ; g < t && tower[g] >= 2 * weight; g++)
                max = tower[++g];
            swap[s++] = 2 * weight;
            swap[s++] = max;

            // Find the most help the current frogs can get, copying entries to the swap.
            while (g < t && tower[g] > weight) {
                swap[s++] = tower[g++];
                swap[s++] = max = tower[g++];
            }

            // Save as many as possible of the current frogs -- smaller frogs can't help them anyway.
            while (f >= 0 && frogs[f].weight == weight)
                if (frogs[f--].leap + max > depth)
                    saved++;

            // Do a merge-sort of the tower with itself, shifted by the current frog, pruning irrelevant entries.
            int h = 0;
            while (swap[h] > weight || g < t) {
                int spare, total;
                if (g == t || swap[h] - weight > tower[g]) {
                    spare = swap[h++] - weight;
                    total = swap[h++] + height;
                }
                else if (swap[h] <= weight || swap[h] - weight < tower[g]){
                    spare = tower[g++];
                    total = tower[g++];
                }
                else {
                    spare = max(swap[h++] - weight, tower[g++]);
                    total = max(swap[h++] + height, tower[g++]);
                }
                if (total > max) {
                    swap[s++] = spare;
                    swap[s++] = max = min(depth, total);
                }
            }
            t = s;
            tmp = swap;
            swap = tower;
            tower = tmp;
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
