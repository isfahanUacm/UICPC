import java.io.*;
import java.util.*;

/**
 * This solution uses a recursive definition for the sequence.
 *  a(2n+1) = a(n) + a(n-1) + ... + a(n-(t-1)/2)
 *  a(2n) = a(n) + a(n-1) + ... + a(n-t/2)
 *  a(0) = 1
 *  a(1) = 1
 *  This is because the even number 2n can be reached from either:
 *    taking a representation for n, and doubling it and adding 0,
 *    taking a representation for n-1, doubling it, and adding 2,
 *    taking a representation for n-2, doubling it, and adding 4, etc.
 *  Similarly, the odd number 2n+1 can be reached by:
 *    taking a representation for n, doubling it, and adding 1,
 *    taking a representation for n-1, doubling it, and adding 3,
 *    taking a representation for n-3, doubling it, and adding 5, etc.
 * @author Finn Lidbetter
 */

public class FastRedundant {
  static long MOD = 998_244_353L;
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    String[] s = br.readLine().split(" ");
    long n = Long.parseLong(s[0]);
    int t = Integer.parseInt(s[1]);
    
    HashMap<Long, Long> dp = new HashMap<>();
    System.out.println(solve(n, t, dp));
  }
  static long solve(long n, int t, HashMap<Long, Long> dp) {
    if (dp.containsKey(n)) {
      return dp.get(n);
    }
    if (n==1 || n==0) 
      return 1;
    long ans = 0;
    if (n%2==0) {
      for (int i=0; i<=t; i+=2) {
        if (n/2 - (i/2)>=0) {
          ans += solve(n/2 - (i/2), t, dp);
        }
      }
    } else {
      for (int i=1; i<=t; i+=2) {
        if (n/2 - ((i-1)/2) >= 0) {
          ans += solve(n/2 - ((i-1)/2), t, dp);
        }
      }
    }
    if (ans>=MOD) {
      ans%=MOD;
    }
    dp.put(n, ans);
    return ans;
  }
  static long brute(long n, int t) {
    int log = 0;
    while ((1<<log)<=n) {
      log++;
    }
    int count = 0;
    int[] vals = new int[log];
    boolean done = false;
    while (!done) {
      done = true;
      long sum = 0;
      for (int i=0; i<log; i++) {
        sum += vals[i]*(1L<<i);
      }
      if (sum==n)
        count++;
      int index = 0;
      while (index<log) {
        if (vals[index]<t) {
          vals[index]++;
          done = false;
          break;
        } else {
          vals[index] = 0;
          index++;
        }
      }
    }
    return count;
  }

}
