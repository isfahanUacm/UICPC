import java.io.*;
import java.util.StringTokenizer;

public class harry_ternary_large_range {

  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(System.in);
    OutputWriter out = new OutputWriter(System.out);
    Task solver = new Task();
    solver.solve(in, out);
    out.close();
  }
}

class Task {
  static Integer[] a;
  static int n;

  public void solve(Scanner in, OutputWriter out) throws IOException {
    n = in.nextInt();
    a = new Integer[n];
    for (int i = 0; i < n; i++) a[i] = in.nextInt();

    int low = 1;
    int high = n - 1;
    while (high - low >= 400) {
      int left = (2 * low + high) / 3;
      int right = (low + 2 * high) / 3;

      if (calc(left) >= calc(right)) high = right;
      else low = left;
    }

    Long max = (long) -1;
    for (int i = low; i <= high; i++) max = Math.max(max, calc(i));

    out.print(max);
    out.print("\n");
  }

  public Long calc(int split) {
    // If we split at index i, we calculate (a_1^2 + ... + a_i^2)*(a_{i+1} + ... + a_n^2)
    Long temp_sq = (long) 0;
    Long temp_s = (long) 0;
    for (int i = 0; i < split; i++) temp_sq += a[i] * a[i];
    for (int i = split; i < n; i++) temp_s += a[i];
    return (temp_sq * temp_s);
  }
}

class Scanner {
  public BufferedReader reader;
  public StringTokenizer st;

  public Scanner(InputStream stream) {
    reader = new BufferedReader(new InputStreamReader(stream));
    st = null;
  }

  public String next() {
    while (st == null || !st.hasMoreTokens()) {
      try {
        String line = reader.readLine();
        if (line == null) return null;
        st = new StringTokenizer(line);
      } catch (Exception e) {
        throw (new RuntimeException());
      }
    }
    return st.nextToken();
  }

  public int nextInt() {
    return Integer.parseInt(next());
  }

  public long nextLong() {
    return Long.parseLong(next());
  }

  public double nextDouble() {
    return Double.parseDouble(next());
  }
}

class OutputWriter {
  BufferedWriter writer;

  public OutputWriter(OutputStream stream) {
    writer = new BufferedWriter(new OutputStreamWriter(stream));
  }

  public void print(int i) throws IOException {
    writer.write(i);
  }

  public void print(String s) throws IOException {
    writer.write(s);
  }

  public void print(char[] c) throws IOException {
    writer.write(c);
  }

  public void print(Long l) throws IOException {
    writer.write(Long.toString(l));
  }

  public void close() throws IOException {
    writer.close();
  }
}
