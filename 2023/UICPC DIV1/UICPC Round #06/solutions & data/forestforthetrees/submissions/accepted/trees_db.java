import java.util.*;

public class trees_db {
  public static void main(String[] args) {
    new trees_db().run();
  }
  
  void run() {
    Scanner in = new Scanner(System.in);

    long x = in.nextLong(), y = in.nextLong();
    
    long x1 = in.nextLong(), y1 = in.nextLong();
    long x2 = in.nextLong(), y2 = in.nextLong();

    long g = gcd(x,y);

    long X = x/g, Y = y/g;

    if(x1 <= X && X <= x2 && y1 <= Y && Y <= y2){
      long k = Math.min(x2 / X, y2 / Y) + 1;
      X *= k;
      Y *= k;
    }

    if(x <= X){
      System.out.println("Yes");
    } else {
      System.out.println("No");
      System.out.println(X + " " + Y);
    }
  }

  long gcd(long a, long b){
    return b == 0 ? a : gcd(b, a%b);
  }
}
