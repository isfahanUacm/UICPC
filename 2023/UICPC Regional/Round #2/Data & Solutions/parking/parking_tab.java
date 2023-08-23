import java.io.*;

public class parking_tab{
  public static void main(String[] args) throws Exception{
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    int t = Integer.parseInt(in.readLine());
    while(t-->0){
      int n = Integer.parseInt(in.readLine());
      String[] inp = in.readLine().split(" ");
      int min = Integer.MAX_VALUE;
      int max = 0;
      for(int i=0;i<n;i++){
        int v = Integer.parseInt(inp[i]);
        if(v<min) min = v;
        if(v>max) max = v;
      }
      System.out.println((2*(max-min)));
    }
  }
}
