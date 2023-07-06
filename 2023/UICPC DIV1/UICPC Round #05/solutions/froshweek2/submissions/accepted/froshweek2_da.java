import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class froshweek2_da {

    private void work() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        int n = sc.nextInt();
        int m = sc.nextInt();
        Integer[] tasks = new Integer[n];
        Integer[] timeslots = new Integer[m];

        for (int i = 0; i < n; i++) tasks[i] = sc.nextInt();
        for (int i = 0; i < m; i++) timeslots[i] = sc.nextInt();
        sc.close();

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
        new froshweek2_da().work();
    }
}
