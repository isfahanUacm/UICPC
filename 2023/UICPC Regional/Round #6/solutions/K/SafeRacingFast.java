/*
  Solution in Java for Safe Racing
  a problem for BAPC2016
  author: Peter Kluit
  September 2016
  linear solution
*/

import java.util.*;
public class SafeRacingFast{

   final static long MOD = 123456789;
   final static int MAXTRACK = 1000000;
   public static void main (String [] args) {
      run();
   }

   private static void run(){
      Scanner ir = new Scanner(System.in);
      int l = ir.nextInt();
      int s = ir.nextInt();
       check (l, s);
      long w = solve(l, s);
      System.out.println(w);
   }

   private static void check(int l, int s){
      if (!(s>= 1)) throw new RuntimeException("S is too small: " + s);
      if (!(s<= l)) throw new RuntimeException("S larger than L: " + s + " " + l);
      if (!(l <= MAXTRACK)) throw new RuntimeException("L is too large: " + l);
   }

   static long [] serie;

   private static long solve (int l, int s){
      serie = new long [l+2];
      serie[1] = 1;
      serie[2] = 1;
      for (int len = 3; len <= l; len++){
         serie[len] = (2 * serie[len - 1]);
         if (len - s > 0)
            serie[len] -= serie[len - s - 1];
         serie[len] = (MOD + serie[len]) % MOD;
      }
      long answer = 0;
      for (int z = 0; z < s; z++){
          answer += (z + 1) * serie[l - z];
          answer = answer % MOD;
      }
      return answer % MOD;
   }

}