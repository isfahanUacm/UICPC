import java.util.*;
import java.math.*;

public class Antti {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		BigInteger s = new BigInteger(input.next());
		BigInteger[] b = new BigInteger[n];
		HashMap<BigInteger,String> names = new HashMap<>();
		for (int i = 0; i < n; i++) {
			String x = input.next();
			b[i] = new BigInteger(input.next());
			names.put(b[i],x);
		}
		Arrays.sort(b);
		ArrayList<String> list = new ArrayList<>();;
		for (int i = n-1; i >= 0; i--) {
			if (b[i].compareTo(s) <= 0) {
				s = s.subtract(b[i]);
				list.add(names.get(b[i]));
			}
		}
		if (s.equals(BigInteger.ZERO)) {
			System.out.println(list.size());
			for (String x : list) System.out.println(x);
		} else {
			System.out.println("0");
		}
	}
}
