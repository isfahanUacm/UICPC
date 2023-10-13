// @EXPECTED_RESULTS@: CORRECT
import java.util.*;
import java.math.*;
public class Alex_CD{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int tc = scan.nextInt();
		while(tc-->0){
			BigInteger K = scan.nextBigInteger(), C = scan.nextBigInteger();
			if(K.gcd(C).equals(BigInteger.ONE)){
				if(C.equals(BigInteger.ONE))System.out.println(K.add(BigInteger.ONE));
				else if(K.equals(BigInteger.ONE))System.out.println("1");
				else System.out.println(C.modInverse(K));
			} else {
				System.out.println("IMPOSSIBLE");
			}
		}
	}
}
