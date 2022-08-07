import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class RoundTableFastIO {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);
        int nt = Integer.parseInt(reader.readLine());
        for (int it = 0; it < nt; ++it) {
            int n = Integer.parseInt(reader.readLine());
            StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
            int[] p = new int[n];
            for (int i = 0; i < n; ++i) {
                p[i] = Integer.parseInt(tokenizer.nextToken()) - 1;
            }
            int[] w = new int[n];
            for (int i = 0; i < n; ++i) w[p[i]] = i;
            long res = 0;
            for (int i = 0; i + 1 < n; ++i) {
                if (w[i] > w[i + 1]) {
                    res += (i + 1) * (long) (n - i - 1);
                }
            }
            int[] fenwick = new int[n];
            for (int i = n - 1; i >= 0; --i) {
                int at = p[i];
                while (at >= 0) {
                    res -= fenwick[at];
                    at = (at & (at + 1)) - 1;
                }
                at = p[i];
                while (at < n) {
                    fenwick[at] += 1;
                    at |= at + 1;
                }
            }
            writer.println(res);
        }
        writer.close();
    }
}
