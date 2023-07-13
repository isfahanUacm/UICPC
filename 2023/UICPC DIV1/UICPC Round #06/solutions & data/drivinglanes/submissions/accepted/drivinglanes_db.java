import java.util.*;

public class drivinglanes_db {
  public static void main(String[] args) {
    new drivinglanes_db().run();
  }

  final long oo = Long.MAX_VALUE/2;
  long[][] DP;
  long[] L;
  long[] C;
  long[] S;

  int n,m,k,r;
  
  void run() {
    Scanner in = new Scanner(System.in);

    n = in.nextInt(); m = in.nextInt();
    k = in.nextInt(); r = in.nextInt();

    L = new long[n];
    for(int i=0;i<n;i++)
      L[i] = in.nextLong();
    
    C = new long[n];
    S = new long[n];
    for(int i=0;i<n-1;i++){
      S[i] = in.nextLong();
      C[i] = in.nextLong();
    }

    DP = new long[n+1][m+1];

    for(int i=0;i<=n;i++)
      for(int j=0;j<=m;j++)
	DP[i][j] = -1;

    System.out.println(f(0,0));
  }

  long f(int seg, int l){
    if(seg == n) return (l == 0 ? 0 : oo);
    long x = DP[seg][l];
    if(x >= 0) return x;
    
    x = oo;
    for(int i=0;i<m;i++)
      if( Math.abs(l-i) * k <= L[seg] ){
	long curr = f(seg+1, i) + L[seg] +
	  Math.abs(l-i) * r + S[seg] + C[seg] * (i+1);
	x = Math.min(x, curr);
      }
    
    return DP[seg][l] = x;
  }
}
