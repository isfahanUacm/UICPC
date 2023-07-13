import java.util.*;

public class neighbourhoodwatch_db {
  public static void main(String[] args) {
    new neighbourhoodwatch_db().run();
  }
  
  void run() {
    Scanner in = new Scanner(System.in);

    int n = in.nextInt();
    int k = in.nextInt();

    long ans = 0;
    long last = 0;
    for(int i=0;i<k;i++){
      long curr = in.nextLong();
      ans += (curr - last) * (n - curr + 1);
      last = curr;
    }

    System.out.println(ans);
  }
}
