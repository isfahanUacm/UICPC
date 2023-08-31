/* Sample solution to NCPC 2008: I Introspective caching
 * by Mikael Goldmann
 *
 * Simulate the caching algorithm by removing the
 * page that will be used furthest into the future
 */
import java.util.*;

public class caching_mg 
{
    static int infty = (1<<28);
    
    static class Request implements Comparable<Request>
    {
	int p,t;
	
	Request(int page, int time) 
	{
	    p=page;
	    t=time;
	}
	
	public int compareTo(Request r) 
	{
	    return r.t - t;
	}
    }
    
    public static void main(String[] a) 
    {
	Scanner in = new Scanner(System.in);
	int r = in.nextInt(), d = in.nextInt(), m = in.nextInt();
	int[] req = new int[m];
	boolean[] inMem = new boolean[d];
	
	Stack<Request>[] pageTimes = (Stack<Request>[]) new Stack[d];
	
	TreeSet<Request> mem = new TreeSet<Request>();
	
	for (int t = 0; t < m; ++t) 
	    req[t] = in.nextInt();

	for (int i = 0; i < d; ++i) {
	    pageTimes[i] = new Stack<Request>();
	    pageTimes[i].push(new Request(i, infty));
	}
	
	for (int t = m-1; t >= 0; --t)
	    pageTimes[req[t]].push(new Request(req[t],t));
	
	for (int i = 0; i < d; ++i)
	    pageTimes[i].pop();

	int faults = 0;
	
	for (int t = 0; t < m; ++t) {
	    Request rq = pageTimes[req[t]].pop();
	    if (inMem[req[t]]) {
		mem.remove(new Request(rq.p,t));
	    }
	    else {
		++ faults;
		if (mem.size() == r) {
		    Request rq1 = mem.first();
		    mem.remove(rq1);
		    inMem[rq1.p] = false;
		}
	    }
	    
	    mem.add(rq);
	    inMem[req[t]] = true;
	}
	System.out.println(faults);
    }
}

	
