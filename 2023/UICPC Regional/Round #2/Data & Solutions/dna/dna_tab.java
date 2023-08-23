/* Sample solution NCPC 2007: Copying DNA
 * Author: Truls A. Bjoerklund
 *
 * This solution is brute force with some memoization.
 *
 */


import java.io.*;

public class dna_tab{
  final static int MAX_n = 18;
  final static int INF = Integer.MAX_VALUE;
  static int[] matches;
  static int[] rmatches;
  static char[] s;
  static char[] sr;
  static char[] t;
  static char[] tr;
  static int[] mem = new int[1<<MAX_n];;

  public static int longestmatch(int from, int to, char[] a){
    int max = 0;
    int m = 0;
    for(int i=0;i<a.length;i++){
      m = 0;
      while(m<to-from && i+m<a.length && a[i+m]==t[from+m]) m++;
      max = (m>max?m:max);
    }
    return max;
  }
  
  public static int solve(int mask){
    if(mem[mask]==INF){
      char[] done = new char[t.length];
      char[] doner = new char[t.length];
      for(int i=0;i<done.length;i++)
        if((mask&(1<<(t.length-1-i)))>0) done[i]=t[i];
        else done[i]='0';
      reverse(done,doner);
      int m = 0;
      for(int i=0;i<t.length;i++){
        if((mask&(1<<(t.length-i-1)))>0){ m = 0; continue;}
        int l = 1;
        while(i+l<t.length && (mask&(1<<(t.length-1-(i+l))))==0) l++;
        int g = Math.min(l,matches[i]);
        g = Math.max(g, Math.min(l,rmatches[i]));
        g = Math.max(g, longestmatch(i,i+l,done));
        g = Math.max(g, longestmatch(i,i+l,doner));
        if(g>m-1)
          mem[mask] = Math.min(mem[mask], 1+solve(mask^getBitsSet(i,i+g)));
        m = g;
      }
    }
    return mem[mask];
  }

  public static void reverse(char[] a, char[] ar){
    for(int i=0;i<a.length;i++) ar[ar.length-1-i] = a[i];
  }

  public static int getBitsSet(int from, int to){
    return ((1<<(t.length-from))-1)-((1<<(t.length-to))-1);
  }

  public static void main(String[] args) throws Exception{
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    for(int n = Integer.parseInt(in.readLine());n>0;n--){
      for(int i=0;i<MAX_n;i++) mem[i] = INF;
      s = in.readLine().toCharArray();
      t = in.readLine().toCharArray();
      boolean[] imptest = new boolean[4];
      for(int i=0;i<t.length;i++)
        if(t[i]=='A') imptest[0]=true;
        else if(t[i]=='C') imptest[1]=true;
        else if(t[i]=='G') imptest[2]=true;
        else if(t[i]=='T') imptest[3]=true;
      for(int i=0;i<s.length;i++)
        if(s[i]=='A') imptest[0]=false;
        else if(s[i]=='C') imptest[1]=false;
        else if(s[i]=='G') imptest[2]=false;
        else if(s[i]=='T') imptest[3]=false;
      if(imptest[0]||imptest[1]||imptest[2]||imptest[3])
        System.out.println("impossible");
      else{
        sr = new char[s.length];
        matches = new int[t.length];
        rmatches = new int[t.length];
        for(int i=0;i<mem.length;i++) mem[i]=INF;
        mem[(1<<t.length)-1]=0;
        reverse(s,sr);
        for(int i=0;i<t.length;i++){
          matches[i]=longestmatch(i,t.length,s);
          rmatches[i]=longestmatch(i,t.length,sr);
        }
        
        System.out.println(solve(0));
      }
    }
  }
}
