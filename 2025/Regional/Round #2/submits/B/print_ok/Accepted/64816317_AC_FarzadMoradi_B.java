import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int p = in.nextInt();
        in.nextLine();
        int[] solve = new int[p];
        int[] tr = new int[p];
        int[] fail = new int[p];
        for (int i = 0; i < n; i++) {
            String[] split = in.nextLine().trim().split(" ");
            for (int j = 0; j < p; j++) {
                String alamat = split[2 * j];
                int k = Integer.parseInt(split[2 * j + 1]);
                if (alamat.equals("+")) {
                    solve[j]++;
                    tr[j]++;
                    fail[j] += k;
                } else { 
                    if (k > 0) {
                        tr[j]++;
                        fail[j] += k;
                    }
                }
            }
        }
        for (int j = 0; j < p; j++) {
            System.out.println(solve[j] + " " + tr[j] + " " + fail[j]);
        }
    }
}
