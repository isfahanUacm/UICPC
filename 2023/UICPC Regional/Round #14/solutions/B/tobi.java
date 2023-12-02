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

public class tobi {

	public static DateFormat formatter = new SimpleDateFormat("yyyy-MM-dd HH:mm");
	public static long getTime(String dateS, String timeS) throws Exception {
		Date date = formatter.parse(dateS + " " + timeS);
		Calendar calendar = Calendar.getInstance();
		calendar.setTime(date);
		return calendar.getTimeInMillis();
	}

	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);

		int numCases = sc.nextInt();
		while (numCases --> 0) {
			int numBookings = sc.nextInt();
			int cleanTime = sc.nextInt();
			ArrayList<Pair> list = new ArrayList<Pair>();
			for (int i = 0; i < numBookings; i++) {
				String tmp = sc.next();

				Pair before = new Pair(getTime(sc.next(), sc.next()), true);
				Pair after = new Pair(getTime(sc.next(), sc.next()) + cleanTime * 60 * 1000, false);
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
