import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class forcedchoice_da {

    private void work() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = sc.nextInt();
        int p = sc.nextInt();
        int s = sc.nextInt();
        Set<Integer>[] a = new HashSet[s];
        for (int i = 0; i < s; i++) {
            a[i] = new HashSet<>();
            int k = sc.nextInt();
            while (k-- > 0) a[i].add(sc.nextInt());
        }

        Set<Integer> set = new HashSet<>();
        set.add(p);
        String[] ans = new String[s];
        for (int i = s - 1; i >= 0; i--) {
            Set<Integer> tmp = new HashSet<>(set);
            tmp.removeAll(a[i]);
            if (tmp.size() < set.size()) {
                ans[i] = "KEEP";
            } else {
                ans[i] = "REMOVE";
                set.addAll(a[i]);
            }
        }

        for (String kr : ans) System.out.println(kr);
    }

    public static void main(String[] args) {
        new forcedchoice_da().work();
    }
}
