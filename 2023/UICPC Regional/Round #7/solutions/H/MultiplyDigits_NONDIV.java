/*
   Solution for MultiplyDigits
   a problem for DAPC/BAPC 2016
   June 2016
   Peter Kluit
 */


/*
    three optimizations are possible:
    MEMO   - memoizing the main function (leastInv). This optimizarion is inevitable.
    MKDIV  - calculate and store beforehand the divisors of n below base.
             the divisors are stored in descending order, with a view to the next optimization:
    NONDIV - remember the digits used at a certain level. 
             If d is used, and d1 is a divisor of d,
                then d1 is not in the solution


    this solution uses: MEMO, NONDIV
*/

import java.util.*;


public class MultiplyDigits_NONDIV{
     public static void main (String []args){
         Scanner st = new Scanner(System.in);
         int base = st.nextInt();
         long n = st.nextLong();
         MultiplyDigits_NONDIV solver = new MultiplyDigits_NONDIV(base);
         System.out.println(solver.solve(n));
    }

////////////////////////////////////////////////////////

   int BASE;

   Hashtable<Long, Long> memo ;

   public MultiplyDigits_NONDIV(int base){
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

       Long res = memo.get(n);
       if (res != null)
          return res.longValue();
       //else
       long result = calculate(n);
       memo.put(n, result);
       return result;
   }

   private long calculate(long n){
       long result = Long.MAX_VALUE;

       int [] local = new int[BASE];
       int dCount = 0;
       for (int digit = BASE - 1; digit >= 2; digit--)
          if (n % digit == 0){
             int index = 0;
             while (index < dCount && local[index] % digit > 0)
                index++;
             if (index == dCount){
                local[dCount++] = digit;
                long rest = leastInv(n/digit);
                if (Long.MAX_VALUE / BASE > rest){
                   long guess = BASE * rest + digit;
                   if (guess < result)
                       result = guess;
                }
             }
          }
        return result;
    }

    private boolean impossible(long n){
       for (int d = 2; d < BASE ; d++)
          while (n % d == 0)
             n /= d;
       return n > 1;
    }
}