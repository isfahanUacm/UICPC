import java.io.*;
import java.util.*;

/**
 * This solution should give TIME LIMIT EXCEEDED.
 * It does dynamic programming on the remaining sum and
 * the current digit in the binary representation. At 
 * each step either any digit up to t can be chosen, except the
 * first digit must be nonzero.
 *
 * @author Finn Lidbetter
 */

public class SlowRedundant {
  
  static long MOD = 998_244_353L;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String[] s = br.readLine().split(" ");
    long n = Long.parseLong(s[0]);
    int t = Integer.parseInt(s[1]);
    long ans = 0;
    HashMap<Pair, Long> dp = new HashMap<>();
    for (int i=0; i<63; i++) {
      for (int j=1; j<=t; j++) {
        if (Long.MAX_VALUE/j>(1L<<i) && n>=j*(1L<<i)) {
          ans += solve(n-j*(1L<<i), i-1, t, dp);
          if (ans>=MOD) {
            ans %= MOD;
          }
        } 
      }
    }
    System.out.println(ans);
  }
  static long solve(long n, int i, int t, HashMap<Pair, Long> dp) {
    if (Long.MAX_VALUE/t>(1L<<(i+1)) && n>t*(1L<<(i+1))-t) {
      return 0;
    }
    if (n<0) {
      return 0;
    }
    if (n==0 && i==-1) {
      return 1L;
    }
    if (i<0)
      return 0L;
    Long prevAns = dp.get(new Pair(n,i));
    if (prevAns!=null) {
      return (long)prevAns;
    }
//    System.out.printf("%d %d\n", n, i);
    long ans = 0;
    for (int j=0; j<=t; j++) {
      ans += solve(n-j*(1L<<i), i-1, t, dp);
      if (ans>=MOD) {
        ans %= MOD;
      }
    }
    dp.put(new Pair(n,i), ans);
    return ans;
  }
}
class Pair {
  long n;
  int i;
  public Pair(long nn, int ii) {
    n = nn;
    i = ii;
  }
  public int hashCode() {
    return Objects.hash(n,i);
  }
  public boolean equals(Object o) {
    Pair p2 = (Pair) o;
    return n==p2.n && i==p2.i;
  }
}
