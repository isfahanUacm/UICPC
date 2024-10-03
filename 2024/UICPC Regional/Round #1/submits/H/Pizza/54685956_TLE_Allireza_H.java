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
            int[] reshte = new int[n]; // Adjust size accordingly, though this could be dynamically adjusted.
            int index = 0;
            reshte[index++] = (int) arr[i]; // Store first element

            int j = i;
            // Increasing sequence
            while (j + 1 < n && arr[j + 1] >= arr[j]) {
                j++;
                reshte[index++] = (int) arr[j];
            }
            // Decreasing sequence
            while (j + 1 < n && arr[j + 1] <= arr[j]) {
                j++;
                reshte[index++] = (int) arr[j];
            }

            long max = arr[i];
            for (int k = 0; k < index; k++) {
                max = Math.max(max, reshte[k]);
            }

            long first = reshte[0];
            long last = reshte[index - 1];
            long difFirst = max - first;
            long difLast = max - last;
            maxDif = Math.max(maxDif, Math.min(difFirst, difLast));
        }
        System.out.print(maxDif);
    }
}
