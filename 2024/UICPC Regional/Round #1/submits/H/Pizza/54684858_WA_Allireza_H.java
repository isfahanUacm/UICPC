import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] ertefa = new long[n];
        for (int i = 0; i < n; i++) {
            ertefa[i] = scanner.nextLong();
        }
        int[] chap = new int[n];
        int[] rast = new int[n];
        chap[0] = 0;
        for (int i = 1; i < n; i++) {
            if (ertefa[i] > ertefa[i - 1]) {
                chap[i] = chap[i - 1] + 1;
            } else {
                chap[i] = 0;
            }
        }
        rast[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (ertefa[i] > ertefa[i + 1]) {
                rast[i] = rast[i + 1] + 1;
            } else {
                rast[i] = 0;
            }
        }
        long max = 0;
        for (int j = 1; j < n - 1; j++) {
            if (chap[j] > 0 && rast[j] > 0) {
                long ghole = Math.min(ertefa[j] - ertefa[j - chap[j]], ertefa[j] - ertefa[j + rast[j]]);
                max = Math.max(max, ghole);
            }
        }
        System.out.print(max);
    }
}
