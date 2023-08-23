/**
 * Sample solution to Cuckoo hashing (NCPC 2007) by Mikael Goldmann
 * Just simulate the process and detect if we get in infinite cycle.
 * If during insertion of new key i, the key gets reassigned twice, then
 * we have a cycle.
 *
 */

public class cuckoo_mg 
{
    static java.util.Scanner in = new java.util.Scanner(System.in);

    int m,N;
    int[] h1, h2, tab;
    
    public static void main(String[] a) throws Exception
    {
	for (int T=in.nextInt(); T>0; --T)
	    new cuckoo_mg().run();	
    }
    
    void run() throws Exception
    {
	m = in.nextInt();
	N = in.nextInt();
	h1 = new int[m];
	h2 = new int[m];
	tab = new int[N];

	for (int i=0; i<N; ++i) tab[i]=-1;	
	for (int i=0; i<m; ++i) {
	    h1[i]=in.nextInt();
	    h2[i]=in.nextInt();	    
	}
	boolean ok=true;
	
	for (int i=0; ok && i<m; ++i) 
	    ok = insert(i);
	

	System.out.println( ok ? "successful hashing" : "rehash necessary");	
	
    }

    boolean insert(int i) 
    {
	int[] h=h1;
	if (tab[h[i]] != -1) h=h2;	
	if (tab[h[i]]==-1) {
	    tab[h[i]]=i;
	    //System.err.println(i + " goes to " + h[i]);
	    
	    return true;
	}
	int cnt=0;
	int j=tab[h1[i]];
	tab[h1[i]]=i;
	int x = h1[i];	
	while (cnt<2) {
	    
	    if (j==i) ++cnt;
	    if (j==-1) return true;
	    h=h1;
	    if (x == h[j]) h=h2;
	    int k=tab[h[j]];
	    //System.err.println("Moving " + j + " from " + x + " to " + h[j]);
	    tab[h[j]]=j;
	    x=h[j];	    
	    j=k;
	}
	return false;	
    }
    
    
}

	    
