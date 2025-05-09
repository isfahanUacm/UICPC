import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();

        while (t-- > 0) {
            int n = input.nextInt();
            int m = input.nextInt();
            int k = input.nextInt();
            char[] directions = input.next().toCharArray();

            for (int i = 0; i < k; i++) {
                int type = input.nextInt();
                if (type == 1) {
                    int x = input.nextInt();
                    int y = input.nextInt();
                    int l = input.nextInt() - 1;
                    int r = input.nextInt();

                    for (int j = l; j < r; j++) {
                        switch (directions[j]) {
                            case 'U': if (x > 0) x--; break;
                            case 'D': if (x < n) x++; break;
                            case 'L': if (y > 0) y--; break;
                            case 'R': if (y < n) y++; break;
                        }
                    }
                    System.out.println(x + " " + y);
                } else {
                    int pos = input.nextInt() - 1;
                    char dir = input.next().charAt(0);
                    directions[pos] = dir;
                }
            }
        }
    }
}
