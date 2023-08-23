import java.io.*;

public class moogle_tab{

  static double[] s;
  static double[][] mem = new double[298][301];
  static double[][] err = new double[301][301];

  public static double err(int f, int t){
    if(t<=f+1) return 0.0;
    else if(err[f][t]==-1.0){
      double d = (s[t]-s[f])/((double)(t-f));
      double app = s[f]+d;
      double sum = 0.0;
      for(int i=f+1;i<t;i++,app+=d) sum+=Math.abs(app-s[i]);
      err[f][t] = sum;
    }
    return err[f][t];
  }

  public static double solve(int c, int f, int t){
    if(c==2) return err(f,t);
    else if(mem[c-3][f]==-1.0){
      double ret = Double.MAX_VALUE;
      for(int i=f+1;i<=t-c+2;i++){
        double h = err(f,i)+solve(c-1,i,t);
        if(h<ret)ret=h;
      }
      mem[c-3][f]=ret;
    }
    return mem[c-3][f];
  }

  public static void main(String[] args) throws Exception{
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    int t = Integer.parseInt(in.readLine());
    while(t-->0){
      String[] inp = in.readLine().split(" ");
      int h = Integer.parseInt(inp[0]);
      int c = Integer.parseInt(inp[1]);
      s = new double[h];
      for(int i=0;i<c-2;i++) for(int j=0;j<h;j++)
        mem[i][j]=-1.0;
      for(int i=0;i<h;i++) for(int j=0;j<h;j++) err[i][j]=-1.0;
      inp = in.readLine().split(" ");
      for(int i=0;i<h;i++) s[i] = Double.parseDouble(inp[i]);
      System.out.printf("%.4f\n",solve(c,0,h-1)/((double)h));
    }
  }
}
