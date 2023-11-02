import java.io.*;
import java.util.*;

/**
 * This solution is incredibly brute force-y. Try 
 * all strings of log(n) digits up to t and count it if the
 * representation gives a sum of n.
 *
 * @author Finn Lidbetter
 */

public class BruteRedundant {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    String[] s = br.readLine().split(" ");
    long n = Long.parseLong(s[0]);
    int t = Integer.parseInt(s[1]);
    
    System.out.println(brute(n, t));
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
