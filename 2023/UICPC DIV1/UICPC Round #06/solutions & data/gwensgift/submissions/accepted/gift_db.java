import java.util.*;

public class gift_db {
  public static void main(String[] args) {
    new gift_db().run();
  }
  
  final long oo = Long.MAX_VALUE/2;
  
  void run() {
    Scanner in = new Scanner(System.in);

    int n = in.nextInt();
    long k = in.nextLong()-1;

    long[] factorial = new long[n];
    factorial[0] = 1;
    for(int i=1;i<n;i++){
      if(oo / factorial[i-1] > i) factorial[i] = factorial[i-1] * i;
      else factorial[i] = oo;
    }
    
    int[] ans = new int[n];
    int[] perm = new int[n];
    boolean[] used = new boolean[n];
    used[0] = true;
    
    for(int i=0;i<n-1;i++){
      int which = 0;
      while(factorial[n-i-2] <= k){
	k -= factorial[n-i-2];
	which++;
      }

      for(int j=1;j<n;j++)
	if(!used[(perm[i]+j)%n]){
	  if(which == 0){
	    used[(perm[i]+j)%n] = true;
	    perm[i+1] = (perm[i]+j)%n;
	    ans[i] = j;
	    break;
	  }
	  which--;
	}
    }

    for(int i=0;i<n-1;i++)
      System.out.print((i > 0 ? " " : "") + ans[i]);
    System.out.println();
  }
}
