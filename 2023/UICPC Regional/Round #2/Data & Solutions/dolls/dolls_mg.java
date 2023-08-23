import java.util.*;

class Doll implements Comparable
{
    int w,h;
    public int compareTo(Object o) 
    {
	Doll d = (Doll) o;	
	if (w != d.w) return d.w-w;
	return h-d.h;
    }
}

public class dolls_mg 
{
    static Scanner in = new Scanner(System.in);
    
    
    public static void main(String[] a) throws Exception
    {
	int n=in.nextInt();
	while (n-->0)
	    new dolls_mg().run();	
    }

    void run() throws Exception
    {
	int m = in.nextInt();
	Doll[] doll = new Doll[m];
	
	int[] v=new int[m];

	for (int i=0; i<m; ++i) {
	    doll[i]=new Doll();	    
	    doll[i].w=in.nextInt();
	    doll[i].h=in.nextInt();
	}
	Arrays.sort(doll);	
	for (int i=0; i<m; ++i) v[i]=doll[i].h;
	System.out.println(lis(v));	
    }        

    // longest non-decreasing subsequence
    int lis(int[] v) 
    {
	int n=v.length;	
	int[] last = new int[n+1];
	int inf = 1<<28;
	last[0]=-inf;
	for (int i=1; i<=n; ++i) last[i] = inf;
	for (int i=0; i<n; ++i) last[bs(last,v[i],0,n+1)]=v[i];
	int m = n;
	while (last[m]==inf) --m;
	return m;
	
    }
    
    int bs(int[] v, int x, int lo, int hi) 
    {
	if (lo==hi) return lo;
	int m=(lo+hi)>>1;
	if (v[m]>x) return bs(v, x, lo, m);
	else return bs(v, x, m+1, hi);
	
    }
    
	
}
