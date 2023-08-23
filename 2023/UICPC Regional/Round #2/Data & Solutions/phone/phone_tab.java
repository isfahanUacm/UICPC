import java.io.*;
import java.util.*;

public class phone_tab{
  public static void main(String[] args) throws Exception{
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    int t = Integer.parseInt(in.readLine());
    while(t-->0){
      int n = Integer.parseInt(in.readLine());
      String[] nrs = new String[n];
      for(int i=0;i<n;i++) nrs[i]=in.readLine();
      Arrays.sort(nrs);
      boolean ok = true;
      for(int i=0;ok && i<n-1;i++)
        ok = nrs[i+1].length()<nrs[i].length() || 
          !nrs[i].regionMatches(0,nrs[i+1],0,nrs[i].length());
      if(ok) System.out.println("YES");
      else System.out.println("NO");
    }
  }
}
