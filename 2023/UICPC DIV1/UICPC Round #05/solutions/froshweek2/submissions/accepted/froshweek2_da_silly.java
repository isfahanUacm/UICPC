import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class froshweek2_da_silly {

    private byte[] input = new byte[1 << 23];
    private int idx;

    private int readInt() {
        while (input[idx] < '0')
            idx++;
        int ret = 0;
        while (input[idx] >= '0')
            ret = 10 * ret + input[idx++] - '0';
        return ret;
    }

    private void work() {

        try {
            System.in.read(input, 0, input.length);
        } catch (Exception e) {
            // blah
        }

        int n = readInt();
        int m = readInt();
        Integer[] tasks = new Integer[n];
        Integer[] timeslots = new Integer[m];

        for (int i = 0; i < n; i++) tasks[i] = readInt();
        for (int i = 0; i < m; i++) timeslots[i] = readInt();

        Arrays.sort(tasks, Collections.reverseOrder());
        Arrays.sort(timeslots, Collections.reverseOrder());

        int ans = 0, i = 0, j = 0;
        while (i < n && j < m) {
            if (tasks[i] <= timeslots[j]) {
                ans++;
                j++;
            }
            i++;
        }

        System.out.println(ans);
    }

    public static void main(String[] args) {
        new froshweek2_da_silly().work();
    }
}
