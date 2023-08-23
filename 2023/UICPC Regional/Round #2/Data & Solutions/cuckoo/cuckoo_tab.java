import java.io.*;

public class cuckoo_tab{
  public static void main(String[] args) throws Exception{
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    int t = Integer.parseInt(in.readLine());
    while(t-->0){
      String[] inp = in.readLine().split(" ");
      int m = Integer.parseInt(inp[0]);
      int n = Integer.parseInt(inp[1]);
      int[][] vals = new int[m][2];
      int[] used = new int[n];
      boolean inf = false;
      for(int i=0;i<n;i++) used[i]=-1;
      for(int i=0;i<m;i++){
        inp = in.readLine().split(" ");
        vals[i][0] = Integer.parseInt(inp[0]);
        vals[i][1] = Integer.parseInt(inp[1]);
        if(used[vals[i][0]]==-1) used[vals[i][0]]=i;
        else if(used[vals[i][1]]==-1) used[vals[i][1]]=i;
        else if(!inf){
          int c = vals[i][0];
          int v = i;
          while(used[c]!=-1 && !inf){
            int ind = used[c];
            used[c]=v;
            v = ind;
            c = vals[v][0]+vals[v][1]-c;
            inf = v==i && c==vals[v][0];
          }
          used[c]=v;
        }
      }
      if(inf) System.out.println("rehash necessary");
      else System.out.println("successful hashing");
    }
  }
}

