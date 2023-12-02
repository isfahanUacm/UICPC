import java.util.*;

public class Antti {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		for (int i = 1; i <= n; i++) {
			String x = input.next();
			if (x.equals("mumble") || x.equals(""+i)) continue;
			System.out.println("something is fishy");
			return;
		}
		System.out.println("makes sense");
	}
}
