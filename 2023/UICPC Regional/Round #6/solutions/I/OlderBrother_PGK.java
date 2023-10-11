import java.util.*;
public class OlderBrother_PGK{

   public static void main (String [] args){
       Scanner scanner  = new Scanner(System.in);
       int n = scanner.nextInt();
       System.out.println( word(isPrimePower(n)));
   }

   public static String word(boolean pp){
       if (pp)
          return "YES";
       else
          return "NO";
   }

   public static boolean isPrimePower(int n){
      if (n == 1)
        return false;
      int mn = n;

      for (int p = 2; p * p <= n; p++){
         while  (n % p == 0)
            n /= p;
         if (n < mn)
            return n == 1;
      }
      return true;

   }

}