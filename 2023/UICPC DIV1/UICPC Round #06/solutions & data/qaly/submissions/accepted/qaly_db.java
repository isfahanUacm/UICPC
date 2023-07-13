import java.util.*;

public class qaly_db {
  public static void main(String[] args) {
    new qaly_db().run();
  }
  
  void run() {
    Scanner in = new Scanner(System.in);

    int n = in.nextInt();

    double ans = 0;
    for(int i=0;i<n;i++)
      ans += in.nextDouble() * in.nextDouble();

    System.out.println(ans);
  }
}
