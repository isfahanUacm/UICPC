// @EXPECTED_RESULTS@: CORRECT

import java.io.*;
import java.util.*;

public class tobi_ersties {

	public static String keyboard[] = {
	"qwertyuiop",
	"asdfghjkl#",
	"zxcvbnm###"
	};

	public static void main(String args[]) throws IOException {
		Scanner sc = new Scanner(System.in);

		int mapping[][] = new int[256][2];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 10; j++) {
				mapping[(int) keyboard[i].charAt(j)][0] = i;
				mapping[(int) keyboard[i].charAt(j)][1] = j;
			}
		}
		int distMatrix[][] = new int[256][256];
		for (int i = 0; i < 256; i++) {
			for (int j = 0; j < 256; j++) {
				distMatrix[i][j] = Math.abs(mapping[i][0] - mapping[j][0]) +
					Math.abs(mapping[i][1] - mapping[j][1]);
			}
		}
		int numCases = sc.nextInt();

		while (numCases --> 0) {
			int numStrings;
			String buf, orig;
			orig = sc.next();
			numStrings = sc.nextInt();

			String stringList[] = new String[numStrings];
			int stringCost[] = new int[numStrings];
			boolean used[] = new boolean[numStrings];

			for (int i = 0; i < numStrings; i++) {
				int cur = 0;
				buf = sc.next();
				for (int j = 0; j < buf.length(); j++) {
					cur += distMatrix[(int)buf.charAt(j)][(int)orig.charAt(j)];
				}

				stringList[i] = buf;
				stringCost[i] = cur;
			}

			for (int i = 0; i < numStrings; i++) {
				int id = -1;
				for (int j = 0; j < numStrings; j++) {
					if (used[j]) {
						continue;
					}
					if ((id == -1)
						|| (stringCost[j] < stringCost[id])
						|| (stringCost[j] == stringCost[id] && (stringList[j].compareTo(stringList[id]) < 0))) {
						id = j;
					}
				}

				used[id] = true;
				System.out.println(stringList[id] + " " + stringCost[id]);
			}
		}
	}

}
