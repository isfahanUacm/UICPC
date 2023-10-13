// @EXPECTED_RESULTS@: CORRECT

import java.io.*;
import java.util.*;

public class tobi {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);

		int numCases = sc.nextInt();

		while (numCases --> 0) {
			int len, numSuff, pos;
			String buf, suff;

			len = sc.nextInt();
			numSuff = sc.nextInt();
			char bufChars[] = new char[len];
			for (int i = 0; i < len; i++) {
				bufChars[i] = '*';
			}

			boolean possible = true;
			for (int i = 0; i < numSuff; i++) {
				pos = sc.nextInt() - 1;
				suff = sc.next();
				char suffChars[] = suff.toCharArray();
				int suffLen = suff.length();
				for (int j = 0; j < suffLen; j++) {
					if (suffChars[j] == '*') {
						break;
					} else if (bufChars[j + pos] == '*' || bufChars[j + pos] == suffChars[j]) {
						bufChars[j + pos] = suffChars[j];
					} else {
						possible = false;
						break;
					}
				}
				for (int j = 0; j < suffLen; j++) {
					if (suffChars[suffLen - j - 1] == '*') {
						break;
					} else if (bufChars[len - j - 1] == '*' || bufChars[len - j - 1] == suffChars[suffLen - j - 1]) {
						bufChars[len - j - 1] = suffChars[suffLen - j - 1];
					} else {
						possible = false;
						break;
					}
				}
			}
			for (int i = 0; i < len; i++) {
				if (bufChars[i] == '*') {
					possible = false;
				}
			}
			if (possible) {
				System.out.println(bufChars);
			} else {
				System.out.println("IMPOSSIBLE");
			}
		}
	}
}
