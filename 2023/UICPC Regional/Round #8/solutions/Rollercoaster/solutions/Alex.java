// @EXPECTED_RESULTS@: CORRECT
import java.util.*;
public class Alex{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt(), T = 25000;
		int dp[] = new int[T+1];
		while(N-- > 0){
			int a = scan.nextInt(), b = scan.nextInt(), t = scan.nextInt();
			if(b > 0){
				for(int k = 0; true; ++k){
					int fun = a - b * k * k;
					if(fun < 0)break;
					for(int ct = T; ct >= t; ct--)
						dp[ct] = Math.max(dp[ct], dp[ct-t] + fun);
				}
			} else {
				for(int ct = t; ct <= T; ct++)
					dp[ct] = Math.max(dp[ct], dp[ct-t] + a);
			}
		}
		int Q = scan.nextInt();
		while(Q-->0){
			T = scan.nextInt();
			System.out.println(dp[T]);
		}
		System.exit(0);
	}
}
