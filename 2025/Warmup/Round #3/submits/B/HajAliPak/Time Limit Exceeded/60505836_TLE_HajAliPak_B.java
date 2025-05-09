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
            int len = instructions.length();

            int[] prefixU = new int[len + 1];
            int[] prefixD = new int[len + 1];
            int[] prefixL = new int[len + 1];
            int[] prefixR = new int[len + 1];

            for (int i = 0; i < len; i++) {
                char ch = instructions.charAt(i);
                prefixU[i + 1] = prefixU[i] + (ch == 'U' ? 1 : 0);
                prefixD[i + 1] = prefixD[i] + (ch == 'D' ? 1 : 0);
                prefixL[i + 1] = prefixL[i] + (ch == 'L' ? 1 : 0);
                prefixR[i + 1] = prefixR[i] + (ch == 'R' ? 1 : 0);
            }

            StringBuilder inst = new StringBuilder(instructions);

            for (int j = 0; j < k; j++) {
                int check = input.nextInt();
                if (check == 1) {
                    int x = input.nextInt();
                    int y = input.nextInt();
                    int l = input.nextInt();
                    int r = input.nextInt();

                    int countU = prefixU[r] - prefixU[l - 1];
                    int countD = prefixD[r] - prefixD[l - 1];
                    int countL = prefixL[r] - prefixL[l - 1];
                    int countR = prefixR[r] - prefixR[l - 1];

                    x = Math.max(0, x - countU);
                    x = Math.min(n, x + countD);
                    y = Math.max(0, y - countL);
                    y = Math.min(m, y + countR);

                    System.out.println(x + " " + y);
                } else if (check == 2) {
                    int z = input.nextInt();
                    char xChar = input.next().charAt(0);
                    char oldChar = inst.charAt(z - 1);
                    if (oldChar == xChar) continue;

                    inst.setCharAt(z - 1, xChar);

                    for (int i = z - 1; i < len; i++) {
                        char ch = inst.charAt(i);
                        prefixU[i + 1] = prefixU[i] + (ch == 'U' ? 1 : 0);
                        prefixD[i + 1] = prefixD[i] + (ch == 'D' ? 1 : 0);
                        prefixL[i + 1] = prefixL[i] + (ch == 'L' ? 1 : 0);
                        prefixR[i + 1] = prefixR[i] + (ch == 'R' ? 1 : 0);
                    }
                }
            }
        }
    }
}
