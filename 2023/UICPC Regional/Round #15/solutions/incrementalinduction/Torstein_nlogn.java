import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.OutputStream;

import java.util.Arrays; 


class Torstein_nlogn {

    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);

        
        int n = io.getInt();
        int[] deg = new int[n];
        for (int i = 1; i < n; i++) {
            String line = io.getWord();
            for (int j = 0; j < i; j++) {
                if (line.charAt(j) == '1') deg[i]++;
                else deg[j]++;
            }
        }
        
        Arrays.sort(deg);
        int max_k = 0;
        int b_out = n * (n - 1) / 2;
        for (int i = 0; i < n; i++) {
            b_out -= deg[n-i-1];
            max_k = Math.max(max_k, b_out - (n-i-1) * (n-i-2) / 2);
        }

        io.println(max_k);
        io.flush();
        io.close();
    }
}

class Kattio extends PrintWriter {
    public Kattio(InputStream i) {
        super(new BufferedOutputStream(System.out));
        r = new BufferedReader(new InputStreamReader(i));
    }
    public Kattio(InputStream i, OutputStream o) {
        super(new BufferedOutputStream(o));
        r = new BufferedReader(new InputStreamReader(i));
    }

    public boolean hasMoreTokens() {
        return peekToken() != null;
    }

    public int getInt() {
        return Integer.parseInt(nextToken());
    }

    public double getDouble() {
        return Double.parseDouble(nextToken());
    }

    public long getLong() {
        return Long.parseLong(nextToken());
    }

    public String getWord() {
        return nextToken();
    }

    private BufferedReader r;
    private String line;
    private StringTokenizer st;
    private String token;

    private String peekToken() {
        if (token == null)
            try {
                while (st == null || !st.hasMoreTokens()) {
                    line = r.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                }
                token = st.nextToken();
            } catch (IOException e) { }
        return token;
    }

    private String nextToken() {
        String ans = peekToken();
        token = null;
        return ans;
    }
}
