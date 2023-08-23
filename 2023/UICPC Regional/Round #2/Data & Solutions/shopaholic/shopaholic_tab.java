import java.io.*;
import java.util.Arrays;

public class shopaholic_tab{
  public static void main(String[] args) throws Exception{
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    int t = Integer.parseInt(in.readLine());
    while(t-->0){
      int c = Integer.parseInt(in.readLine());
      int[] p = new int[c];
      String[] inp = in.readLine().split(" ");
      for(int i=0;i<c;i++) p[i] = Integer.parseInt(inp[i]);
      Arrays.sort(p);
      int disc = 0;
      for(int i=c-3;i>=0;i-=3) disc+=p[i];
      System.out.println(disc);
    }
  }
}
