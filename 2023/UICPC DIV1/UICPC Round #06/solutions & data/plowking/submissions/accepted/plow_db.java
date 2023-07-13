import java.util.*;

public class plow_db {
  public static void main(String[] args) {
    new plow_db().run();
  }
  
  void run() {
    Scanner in = new Scanner(System.in);

    long n = in.nextLong();
    long m = in.nextLong();
    
    long d = (long)((3 + Math.sqrt(3*3 - 4*2*(n-m))) / 2);
    if(1 - 3 + 2*(n-m) >= 0) d = 1;

    while(d * (d-1) / 2 + (n - d) < m) d++;

    long ans = (d*d*d - 3*d*d + 8*d - 6) / 6;

    for(long i=m-n+d+1;i<=m;i++)
      ans += i;

    System.out.println(ans);
  }
}
