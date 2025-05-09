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

            for (int j = 0; j < k; j++) {
                int check = input.nextInt();
                if (check == 1) {
                    int x = input.nextInt();
                    int y = input.nextInt();
                    int l = input.nextInt();
                    int r = input.nextInt();

                    int countU = 0, countD = 0, countL = 0, countR = 0;
                    for (int f = l - 1; f < r; f++) {
                        char move = instructions.charAt(f);
                        if (move == 'U') countU++;
                        else if (move == 'D') countD++;
                        else if (move == 'L') countL++;
                        else if (move == 'R') countR++;
                    }
                    






                    x = Math.max(0, x - countU);
                    x = Math.min(n, x + countD);
                    y = Math.max(0, y - countL);
                    y = Math.min(m, y + countR);

                    System.out.println(x + " " + y);
                } else if (check == 2) {
                    int z = input.nextInt();
                    char xChar = input.next().charAt(0);
                    StringBuilder xs = new StringBuilder(instructions);
                    xs.setCharAt(z - 1, xChar);
                    instructions = xs.toString();
                }
            }

        }
    }
}
