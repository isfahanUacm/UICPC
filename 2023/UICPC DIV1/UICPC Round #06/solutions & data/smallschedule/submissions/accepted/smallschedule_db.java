import java.util.*;

public class smallschedule_db {
  public static void main(String[] args) {
    new smallschedule_db().run();
  }
  
  void run() {
    Scanner in = new Scanner(System.in);

    int Q = in.nextInt();
    int M = in.nextInt();
    int S = in.nextInt();
    int L = in.nextInt();

    while(L % M != 0 && S > 0){
	L++;
	S -= Q;
    }

    if(S < 0) S = 0;

    System.out.println( Q * ((L+M-1) / M) + (S+M-1) / M);
  }
}
