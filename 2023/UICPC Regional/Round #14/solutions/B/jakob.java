// @EXPECTED_RESULTS@: CORRECT
import java.util.*;
public class jakob {
	static class booking implements Comparable<booking> {
		public final Date start, end;
		public boolean startpassed = false;
		public booking(Date start, Date end) {
			this.start = start;
			this.end = end;
		}
		public int compareTo(booking b)  {
			if(startpassed) {
				if(b.startpassed) {
					return end.compareTo(b.end);
				} else {
					int r = end.compareTo(b.start);
					if(r == 0)
						return -1;
					return r;
				}
			} else {
				if(b.startpassed) {
					int r = start.compareTo(b.end);
					if(r == 0)
						return 1;
					return r;
				} else {
					return start.compareTo(b.start);
				}
			}
		}
		public String toString() {
			return start + " - " + end;
		}
	}
		

	public static  void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int ntc = s.nextInt();
		PriorityQueue<booking> q = new PriorityQueue<booking>(5000);
		for(int tc = 0; tc < ntc; tc++) {
			int B = s.nextInt();
			int C = s.nextInt();
			booking[] bb = new booking[B];
			s.nextLine();
			for(int j = 0; j < B; j++) {
				String resCode = s.next();
				String[] sday = s.next().split("-");
				String[] sm = s.next().split(":");
				String[] eday = s.next().split("-");
				String[] em = s.next().split(":");
				Calendar c = Calendar.getInstance(TimeZone.getTimeZone("GMT"));
				c.clear();
				c.set(Integer.parseInt(sday[0]), 
				      Integer.parseInt(sday[1])-1, 
				      Integer.parseInt(sday[2]),
				      Integer.parseInt(sm[0]),
				      Integer.parseInt(sm[1]));
				Date sd = c.getTime();
				c.clear();
				c.set(Integer.parseInt(eday[0]),
				      Integer.parseInt(eday[1])-1, 
				      Integer.parseInt(eday[2]),
				      Integer.parseInt(em[0]),
				      Integer.parseInt(em[1]));
				Date tmp = c.getTime();
				if(sd.compareTo(tmp) >= 0) {
					System.err.println("broken booking: " + new booking(sd, tmp));
					System.exit(-1);
				}
				c.add(Calendar.MINUTE, C);
				Date ed = c.getTime();
				q.add(new booking(sd, ed));
			}
			int needed = 0;
			int cneeded = 0;
			while(!q.isEmpty()) {
				booking b = q.poll();
				if(!b.startpassed) {
					cneeded++;
					b.startpassed = true;
					q.add(b);
				} else {
					cneeded--;
				}
				if(cneeded > needed) {
					needed = cneeded;
				}
			}
			System.out.println(needed);
		}

	}
}