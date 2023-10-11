/*
   Solution for MultiplyDigits
   a problem for DAPC/BAPC 2016
   October 2016
   Peter Kluit

    Joris' algorithm
    Met een eigen twist.
*/

import java.util.*;


public class MultiplyDigits_OD {
  

     public static void main (String []args){
         Scanner st = new Scanner(System.in);
         int base = st.nextInt();
         long n = st.nextLong();
         MultiplyDigits_OD solver = new MultiplyDigits_OD(base);
         System.out.println(solver.solve(n));
    }

////////////////////////////////////////////////////////

   int BASE;
   Hashtable<Long, Long> memo ;
   long [] allDivisors = new long [125000];
   int divCount = 0;


   public MultiplyDigits_OD(int base){
      BASE = base;
      memo = new Hashtable<Long,Long>();
   }

   public String solve (long n){
      if (impossible(n))
         return "impossible";
      else{
         return "" +  leastInv(n);
      }
   }

   private long leastInv(long n){
       if (n < BASE)
          return n;
       mkAllDivisors(n);

       for (long d = 2; d < BASE ; d++)
          if (n % d == 0)
             memo.put(d, d);

       for (int k = 1; k < divCount - 1; k++){
          long deler = allDivisors[k];


          long bestval = memo.get(deler);
          long tbd = n/deler;

          long lastDigit = bestval % BASE;
          for (int d = BASE - 1; d >= lastDigit; d--)
             if (tbd % d == 0)
                if (Long.MAX_VALUE / BASE > bestval && d <= Long.MAX_VALUE - BASE * bestval){
                    long guess = BASE * bestval + d;
                    long nNum = d * deler;
                    if (memo.get(nNum) != null){
                        long present = memo.get(nNum);
                        if (present > guess)
                           memo.put(nNum, guess);
                    }
                    else
                       memo.put(nNum, guess);
                }
       }
       return memo.get(n);
   }

   private void mkAllDivisors(long n){
      allDivisors[divCount++] = 1;
      for (long p = 2; p <= n ; p++){
       	long d = p;
       	int hcount = divCount;
        while (n % p == 0){
             n /= p;
             for (int w = 0; w < divCount; w++)
                allDivisors[hcount++] = d * allDivisors[w];
             d *= p;
        }       
        divCount = hcount;
      }
   }

   private boolean impossible(long n){
      for (int d = 2; d < BASE ; d++)
         while (n % d == 0)
            n /= d;
      return n > 1;
   }
}