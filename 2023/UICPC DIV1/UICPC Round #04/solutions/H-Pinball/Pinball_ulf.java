import java.util.Scanner;
import java.io.*;
import java.util.Arrays;
import java.util.TreeSet;

class Line implements Comparable<Line>{
    static long x;
    int x1, x2, y1, y2, i;
    public int compareTo(Line l) {
	//double diff = this.y1+(double)(this.y2-this.y1)*(Line.x-this.x1)/(this.x2-this.x1)
	//    - (double)(l.y1+(l.y2-l.y1)*(Line.x-l.x1)/(l.x2-l.x1));
	long diff = ((this.y1-l.y1)*(this.x2-this.x1)
		+(this.y2-this.y1)*(Line.x-this.x1))*(l.x2-l.x1)
	    -(l.y2-l.y1)*(Line.x-l.x1)*(this.x2-this.x1);
	if (diff > 0)
	    return (this.x2-this.x1)*(l.x2-l.x1);
	if (diff < 0)
	    return -(this.x2-this.x1)*(l.x2-l.x1);
	return 0;
    }
}
class Event implements Comparable<Event>{
    int x, i;
    boolean start;
    public int compareTo(Event e) {
	int diff = this.x-e.x;
	if (diff == 0)
	    return (e.start?1:0) - (this.start?1:0);
    	return diff;
    }
}

public class Pinball_ulf {
    public static void main(String[] args) {
	Scanner sc = new Scanner(new BufferedInputStream(System.in));
	int N = sc.nextInt();
	Line lines[] = new Line[N];
	Event events[] = new Event[2*N];
	for (int i = 0; i < N; ++i) {
	    lines[i] = new Line();
	    lines[i].x1 = sc.nextInt();
	    lines[i].y1 = sc.nextInt();
	    lines[i].x2 = sc.nextInt();
	    lines[i].y2 = sc.nextInt();
	    lines[i].i = i;
	    events[2*i] = new Event();
	    events[2*i].x = lines[i].x1;
	    events[2*i].i = i;
	    events[2*i].start = lines[i].x1<lines[i].x2;
	    events[2*i+1] = new Event();
	    events[2*i+1].x = lines[i].x2;
	    events[2*i+1].i = i;
	    events[2*i+1].start = lines[i].x2<lines[i].x1;
	}
	int x0 = sc.nextInt();
	Arrays.sort(events);
	TreeSet<Line> now = new TreeSet<Line>();
	int next[] = new int[N+1];
	for (int i = 0; i < 2*N; ++i) {
	    if (events[i].start) {
		Line.x = events[i].x;
		Line above = now.ceiling(lines[events[i].i]);
		if (above == null) {
		    next[events[i].i] = next[N];
		    next[N] = events[i].i;
		} else {
		    next[events[i].i] = next[above.i];
		    next[above.i] = events[i].i;
		}
		now.add(lines[events[i].i]);
	    } else {
		now.remove(lines[events[i].i]);
	    }
	}

	int p = N;
	for (int i = 0; i < N; ++i) {
	    p = next[p];
	    if (x0 >= lines[p].x1 && x0 <= lines[p].x2 ||
		    x0 <= lines[p].x1 && x0 >= lines[p].x2) {

		Line l = lines[p];
		//System.out.println(x0 + " " +  (double)(l.y1+(l.y2-l.y1)*(x0-l.x1)/(l.x2-l.x1)));

		if (lines[p].y1 < lines[p].y2) {
		    x0 = lines[p].x1;
		    //System.out.println(x0 + "  " + lines[p].y1);
		} else {
		    x0 = lines[p].x2;
		    //System.out.println(x0 + "  " + lines[p].y2);
		}
	    }
	}

	System.out.println(x0);
    }
}

