// @EXPECTED_RESULTS@: CORRECT

import java.io.*;
import java.util.*;
import java.text.*;

class Pair implements Comparable<Pair> {
	long time;
	boolean begin;

	public Pair(long time, boolean begin) {
		this.time = time;
		this.begin = begin;
	}

	public int compareTo(Pair o) {
		if (time != o.time) return (time < o.time ? -1 : 1);
		if (begin == o.begin) return 0;
		return (begin ? 1 : -1);
	}
}

public class tobi_br {

	public static DateFormat formatter = new SimpleDateFormat("yyyy-MM-dd HH:mm");
	public static long getTime(String dateS, String timeS) throws Exception {
		Date date = formatter.parse(dateS + " " + timeS);
		Calendar calendar = Calendar.getInstance();
		calendar.setTime(date);
		return calendar.getTimeInMillis();
	}

	public static void main(String args[]) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String line = reader.readLine();

		int numCases = Integer.parseInt(line);
		while (numCases --> 0) {
			line = reader.readLine();
			StringTokenizer strtok = new StringTokenizer(line);
			int numBookings = Integer.parseInt(strtok.nextToken());
			int cleanTime = Integer.parseInt(strtok.nextToken());
			ArrayList<Pair> list = new ArrayList<Pair>();
			for (int i = 0; i < numBookings; i++) {
				line = reader.readLine();
				strtok = new StringTokenizer(line);
				strtok.nextToken();

				Pair before = new Pair(getTime(strtok.nextToken(), strtok.nextToken()), true);
				Pair after = new Pair(getTime(strtok.nextToken(), strtok.nextToken()) + cleanTime * 60 * 1000, false);
				list.add(before);
				list.add(after);
			}
			Collections.sort(list);
			int maxRooms = 0;
			int rooms = 0;
			for (Pair p : list) {
				if (p.begin) {
					rooms++;
					maxRooms = Math.max(maxRooms, rooms);
				} else {
					rooms--;
				}
			}
			System.out.println(maxRooms);
		}
	}
}
