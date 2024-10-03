import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long maxDif = 0;
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextLong();
        }

        for (int i = 0; i < n; i++) {
            ArrayList<Long> reshte = new ArrayList<>();
            reshte.add(arr[i]);
            int j = i;
            while (j + 1 < n && arr[j + 1] >= arr[j]) {
                j++;
                reshte.add(arr[j]);
            }
            while (j + 1 < n && arr[j + 1] <= arr[j]) {
                j++;
                reshte.add(arr[j]);
            }
            long max = reshte.stream().max(Long::compare).orElse(0L);
            long first = reshte.getFirst();
            long last = reshte.getLast();
            long difFirst = max - first;
            long difLast = max - last;
            maxDif = Math.max(maxDif, Math.min(difFirst, difLast));
        }
        System.out.print(maxDif);
    }
}
