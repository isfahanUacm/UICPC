import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        while (t-- > 0) {
            int n = input.nextInt();
            int m = input.nextInt();
            int k = input.nextInt();
            String instructions = input.next();
            char[] cmds = instructions.toCharArray();

            for (int j = 0; j < k; j++) {
                int op = input.nextInt();
                if (op == 1) {
                    int x = input.nextInt();
                    int y = input.nextInt();
                    int l = input.nextInt();
                    int r = input.nextInt();
                    for (int idx = l - 1; idx < r; idx++) {
                        switch (cmds[idx]) {
                            case 'U':
                                if (x > 1) x--;
                                break;
                            case 'D':
                                if (x < n) x++;
                                break;
                            case 'L':
                                if (y > 1) y--;
                                break;
                            case 'R':
                                if (y < n) y++;
                                break;
                        }
                    }
                    System.out.println(x + " " + y);
                } else if (op == 2) {
                    int pos = input.nextInt();
                    char c = input.next().charAt(0);
                    cmds[pos - 1] = c;
                }
            }
        }
    }
}
