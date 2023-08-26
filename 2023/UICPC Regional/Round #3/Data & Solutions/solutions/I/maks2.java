/*
 * @EXPECTED_RESULTS@: CORRECT
 */
import java.util.Scanner;

class maks2
{
    public static void main(String... args)
    {
        Scanner s = new Scanner(System.in);
        s.useDelimiter("[^\\w]+");
        int cases = s.nextInt();
        while (cases-- > 0) {
            String program = s.next();
            int N = s.nextInt();
            int[] data = new int[N];
            for (int n = 0; n < N; ++n) {
                data[n] = s.nextInt();
            }
            int i = 0, j = N;
            boolean rev = false;
            for (char c : program.toCharArray()) {
                if (c == 'R') rev = !rev;
                else if (!rev) ++i; else --j;
            }
            if (i <= j) {
                System.out.print("[");
                for (int n = 0; n < j - i; ++n) {
                    if (n > 0) System.out.print(',');
                    System.out.print(data[!rev ? i + n : j - 1 - n]);
                }
                System.out.println("]");
            } else {
                System.out.println("error");
            }
        }
    }
}
