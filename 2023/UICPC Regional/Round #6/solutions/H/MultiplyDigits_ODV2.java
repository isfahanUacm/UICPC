/*
   Solution for MultiplyDigits
   a problem for DAPC/BAPC 2016
   October 2016
   Peter Kluit

   Joris' algorithm
   without markers in the queue
*/

import java.util.*;

public class MultiplyDigits_ODV2 {

     public static void main (String []args){
        run();
     }    

     private static void run(){
         Scanner st = new Scanner(System.in);
         int base = st.nextInt();
         long n = st.nextLong();
         MultiplyDigits_ODV2 solver = new MultiplyDigits_ODV2(base);
         System.out.println(solver.solve(n));
     }

////////////////////////////////////////////////////////

   int BASE;
   Hashtable<Long, Long> memo ;
   long [] queue = new long [125000];
   int front = 0;
   int rear = 0;

   public MultiplyDigits_ODV2(int base){
      BASE = base;
      memo = new Hashtable<Long,Long>();
   }

   public String solve (long n){
      if (impossible(n))
         return "impossible";
      else
         return "" +  leastInv(n);
   }

   private long leastInv(long n){
      if (n < BASE)
         return n;

      for (long d = 2; d < BASE ; d++)
         if (n % d == 0){
            memo.put(d, d);
            enQueue(d);
         }

      for (long deler = dequeue(); deler != n; deler = dequeue()){
         long bestval = memo.get(deler);
         long tbd = n/deler;
         long lastDigit = bestval % BASE;
         for (int d = (int) lastDigit; d < BASE; d++)
            if (tbd % d == 0)
               if (Long.MAX_VALUE / BASE > bestval && d <= Long.MAX_VALUE - BASE * bestval){ //overflow??
                  long guess = BASE * bestval + d;
                  long nNum = d * deler;
                  Long presentO = memo.get(nNum);
                  if (presentO != null){
                     long present = presentO.longValue();
                     if (present > guess)
                        memo.put(nNum, guess);
                  }
                  else{
                     memo.put(nNum, guess);
                     enQueue(nNum);
                  }
               }
      }
      return memo.get(n);
   }

   void enQueue(long n){
       queue[rear++] = n;
   }
   
   long dequeue(){
       return queue[front++];
   }

   private boolean impossible(long n){
      for (int d = 2; d < BASE ; d++)
         while (n % d == 0)
            n /= d;
      return n > 1;
   }
}