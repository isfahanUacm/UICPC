/*
 * @EXPECTED_RESULTS@: CORRECT
 */

import java.io.*;
import java.util.*;

public class jeroen4
{
	public static void main(String[] args) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int tests = sc.nextInt();
		while (tests-- > 0) {
			System.out.println("3 1 3 6");
			while(true) {
				String cmd = sc.next();
				if(cmd.equals("MOVE")) {
					int r1 = sc.nextInt();
					int c1 = sc.nextInt();
					int r2 = sc.nextInt();
					int c2 = sc.nextInt();
					System.out.println((6-r2)+" "+(7-c2)+" "+(6-r1)+" "+(7-c1));
				} else if(cmd.equals("GAME")) break;
				else throw new Exception();
			}
		}
	}
}