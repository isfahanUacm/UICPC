import java.io.*;

public class debt_tab{
  static int[] cs = new int[]{100,50,20,10,5,1};
  static int[] mods = new int[]{100,50,10,10,5,1};
  static int INF = Integer.MAX_VALUE;
  static int[][][] dp = new int[2][1001][1001];
  static int[] bal = new int[2];
  static int[] sums = new int[2];
  static int[][] c = new int[3][6];
  static int[][] startpos = new int[2][2];
  static int[][] endpos = new int[2][2];

  public static void main(String[] args) throws Exception{
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    int t = Integer.parseInt(in.readLine());
    while(t-->0){
      String[] inp = in.readLine().split(" ");
      int ab = Integer.parseInt(inp[0]);
      int bc = Integer.parseInt(inp[1]);
      int ca = Integer.parseInt(inp[2]);
      bal[0] = ca-ab; bal[1] = ab-bc;
      sums[0] = 0; sums[1] = 0;
      for(int i=0;i<3;i++){
        inp = in.readLine().split(" ");
        for(int j=0;j<6;j++){
          c[i][j] = Integer.parseInt(inp[j]);
          if(i<2) sums[i] += (cs[j]*c[i][j]);
        }
        if(i<2)bal[i]+=sums[i];
      }
      if(bal[0]<0 || bal[1]<0 || bal[0]>1000 || bal[1]>1000)
        System.out.println("impossible");
      else{
        
        for(int k=0;k<2;k++)for(int i=0;i<1001;i++) for(int j=0;j<1001;j++)
          dp[k][i][j]=INF;
        dp[0][sums[0]][sums[1]]=0;
        int s=0;
        startpos[0][0] = sums[0]; startpos[0][1] = sums[1];
        endpos[0][0] = sums[0]; endpos[0][1] = sums[1];
        //for each coin size
        for(int j=5;j>=0;j--){
          s++;
          startpos[s%2][0] = INF; startpos[s%2][1] = INF;
          endpos[s%2][0] = 0; endpos[s%2][1] = 0;
          for(int x = startpos[(s+1)%2][0]; x<=endpos[(s+1)%2][0];x+=mods[j])
            for(int y = startpos[(s+1)%2][1]; y<=endpos[(s+1)%2][1];y+=mods[j])
              if(dp[(s+1)%2][x][y]!=INF){
                //one of them gives to the two others
                for(int f=0;f<3;f++){
                  for(int i=0;i<=c[f][j];i++){
                    for(int a=0;a<=i;a++){
                      int[] vals = new int[]{x,y,0};
                      vals[f]-=(cs[j]*i);
                      vals[(f+1)%3]+=(cs[j]*a);
                      vals[(f+2)%3]+=(cs[j]*(i-a));
                      if(dp[s%2][vals[0]][vals[1]]>=dp[(s+1)%2][x][y]+i 
                          && (j==0 || ((vals[0]%mods[j-1])==(bal[0]%mods[j-1]) 
                          && (vals[1]%mods[j-1])==(bal[1]%mods[j-1])))){
                        if(vals[0]<startpos[s%2][0]) startpos[s%2][0] = vals[0];
                        if(vals[0]>endpos[s%2][0]) endpos[s%2][0] = vals[0];
                        if(vals[1]<startpos[s%2][1]) startpos[s%2][1] = vals[1];
                        if(vals[1]>endpos[s%2][1]) endpos[s%2][1] = vals[1];
                        dp[s%2][vals[0]][vals[1]]=dp[(s+1)%2][x][y]+i;
                      }
                    }
                  }
                }

                //one of them recieves from the two others
                for(int r=0;r<3;r++){
                  //number of coins to recieve from each giver:
                  for(int a1=0;a1<=c[(r+1)%3][j];a1++){
                    for(int a2=0;a2<=c[(r+2)%3][j];a2++){
                      int[] vals = new int[]{x,y,0};
                      vals[r] += (cs[j]*(a1+a2));
                      vals[(r+1)%3] -= (cs[j]*a1);
                      vals[(r+2)%3] -= (cs[j]*a2);
                      if(dp[s%2][vals[0]][vals[1]]>=dp[(s+1)%2][x][y]+a1+a2
                          && (j==0 || ((vals[0]%mods[j-1])==(bal[0]%mods[j-1])
                          &&  (vals[1]%mods[j-1])==(bal[1]%mods[j-1])))){
                        if(vals[0]<startpos[s%2][0]) startpos[s%2][0] = vals[0];
                        if(vals[0]>endpos[s%2][0]) endpos[s%2][0] = vals[0];
                        if(vals[1]<startpos[s%2][1]) startpos[s%2][1] = vals[1];
                        if(vals[1]>endpos[s%2][1]) endpos[s%2][1] = vals[1];
                        dp[s%2][vals[0]][vals[1]]=dp[(s+1)%2][x][y]+a1+a2;
                        
                      }
                    }
                  }
                }
              }
        }
        if(dp[s%2][bal[0]][bal[1]]==Integer.MAX_VALUE)
          System.out.println("impossible");
        else System.out.println(dp[s%2][bal[0]][bal[1]]);
      }     
    }
  }
}
