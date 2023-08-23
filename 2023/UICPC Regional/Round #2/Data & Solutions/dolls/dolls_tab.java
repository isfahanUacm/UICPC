import java.io.*;
import java.util.*;

public class dolls_tab{
  
  private static class Pair implements Comparable<Pair>{
    int w;
    int h;
    public Pair(int w,int h){ this.w=w; this.h=h;}
    public int compareTo(Pair p){
      if(p.w==w) return p.h-h;
      return w-p.w;
    }
  }

  public static void main(String[] args) throws Exception{
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    int t = Integer.parseInt(in.readLine());
    int[] ans = new int[20000];
    while(t-->0){
      in.readLine();
      String[] inp = in.readLine().split(" ");
      ArrayList<Pair> li = new ArrayList<Pair>();
      for(int i=0;i<inp.length;i+=2)
        li.add(new Pair(Integer.parseInt(inp[i]),Integer.parseInt(inp[i+1])));
      Collections.sort(li);
      int le = 0;
      for(int i=0;i<li.size();i++){
        int h = le;
        int l = 0;
        while(h>l){
          int m = (h+l)/2;
          if(ans[m]<li.get(i).h) h=m;
          else l=m+1;
        }
        ans[l]=li.get(i).h;
        if(l==le) le++;
      }
      System.out.println(le);
    }
  }
}
