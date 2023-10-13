// @EXPECTED_RESULTS@: CORRECT

import java.io.*;
import java.util.*;

public class tobi {

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
			TreeMap<Integer, TreeSet<String> > result = new TreeMap<Integer, TreeSet<String> >();
//			multiset<pair<int,string> > result;
			String buf, orig;
			orig = sc.next();
			numStrings = sc.nextInt();

			for (int i = 0; i < numStrings; i++) {
				int cur = 0;
				buf = sc.next();
				for (int j = 0; j < buf.length(); j++) {
					cur += distMatrix[(int)buf.charAt(j)][(int)orig.charAt(j)];
				}

				if (!result.containsKey(cur)) {
					result.put(cur, new TreeSet<String>());
				}
				TreeSet<String> s = result.get(cur);
				s.add(buf);
			}

			for (Map.Entry<Integer, TreeSet<String> > entry : result.entrySet()) {
				Integer key = entry.getKey();
				TreeSet<String> s = entry.getValue();

				for (String o : s) {
					System.out.println(o + " " + key);
				}
			}

//			for (multiset<pair<int,string> >::iterator it = result.begin(); it != result.end(); it++) {
//				printf("%s %d\n", it->second.c_str(), it->first);
//			}
		}
	}

}
