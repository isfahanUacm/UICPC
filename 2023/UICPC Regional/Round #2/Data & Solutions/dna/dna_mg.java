public class dna_mg 
{
    static java.util.Scanner in = new java.util.Scanner(System.in);
    static final int inf=1<<28;
    
    public static void main(String[] a) throws Exception
    {
	for (int N=in.nextInt(); N>0; --N) {
	    String s = in.next();
	    String t = in.next();
	    new dna_mg(s.toCharArray(), t.toCharArray());
	}
    }
    
    dna_mg(char[] s, char[] t) 
    {
	int ns = s.length;
	int nt = t.length;
	boolean sA, sC, sG, sT, tA, tC, tG, tT;
	sA=sC=sG=sT=tA=tC=tG=tT=false;
	for (int i=0; i<ns; ++i)
	    switch(s[i]) {
	    case 'A': sA=true; break;
	    case 'C': sC=true; break;
	    case 'G': sG=true; break;
	    case 'T': sT=true; break;
	    default: System.err.println("Bad char in input");System.exit(1);
	    }
	
	for (int i=0; i<nt; ++i)
	    switch(t[i]) {
	    case 'A': tA=true; break;
	    case 'C': tC=true; break;
	    case 'G': tG=true; break;
	    case 'T': tT=true; break;
	    default: System.err.println("Bad char in input");System.exit(1);
	    }
	if (!sA && tA || !sC && tC ||!sG && tG ||!sT && tT) {	    
	    System.out.println("impossible");
	    return;	    
	}
	solve(s, t);	
    }
    
    
    char[] reverse(char[] s)
    {
	char[] t = new char[s.length];
	for (int i=0; i<s.length; ++i) t[s.length-1-i]=s[i];
	return t;	
    }
    
    void solve(char[] s, char[] t)
    {
	//System.err.println("Solving");
	
	int nt=t.length;
	int ns=s.length;
	char[] rs=reverse(s);	
	char[] rt=reverse(t);	
	int N=(1<<nt);

	int[] rev = new int[N];
	rev[0]=0;
	int b=1<<(nt-1);	
	for (int i=1; i<N; ++i) 
	    rev[i] = (rev[(i/2)]>>1) + ((i&1)*b);
	
	//System.err.println("rev[] computed");
	
	// Now just do BFS
	int allOfs =(1<<s.length)-1;
	
	int[] dist = new int[N];	
	for (int i=0; i<N; ++i) dist[i]=inf;
	dist[0]=0;	
	int[] q = new int[N];
	int qh=0, qt=0;
	q[qt++]=0;
	while (qh<qt && dist[N-1]==inf) {
	    int mask = q[qh++];
	    //System.err.println("pop  " + mask);
	    int i;
	    int bit;	    
	    for (i=0, bit=1; i<nt; ++i, bit+=bit)
		if (((1<<i)&mask)==0) {
		    int len1 = tcopy(t,nt,mask,s,ns,allOfs,i);
		    int len2 = tcopy(t,nt,mask,rs,ns,allOfs,i);
		    int len3 = tcopy(t,nt,mask,t,nt,mask,i);
		    int len4 = tcopy(t,nt,mask,rt,nt,rev[mask],i);
		    if (len4 > len3) len3=len4;
		    if (len3 > len2) len2=len3;
		    if (len2 > len1) len1=len2;
		    int m=0;
		    int j=0;
		    while (j < len1) 
			m += (bit << (j++));
		    int mask1= mask + m;
		    if (dist[mask1]==inf) {
			dist[mask1]=1+dist[mask];
			q[qt++]=mask1;			
			//System.err.println("push " + mask1 + "["+dist[mask1]+"]");
		    }
		    
		}
	    
	    
	}
	System.out.println(dist[N-1]);
	
	
    }
    

    /* length of longest prefix of s[i..] that can be
     * copied from t.
     * smask = 0 where we can put symbols
     * tmask = 1 where we can use symbols
     */
    int tcopy(char[] s, int ns, int smask, char[] t, int nt, int tmask, int starts) 
    {
	
	int ends=starts;
	while (ends<ns && (smask & (1<<ends))==0  ) ++ends;
	
	int mx=0;
	
	for (int j=0; j<nt; ++j) {
	    if ((tmask & (1<<j))!=0 && s[starts]==t[j]) {
		int len=1;		
		while(starts+len<ends && j+len<nt 
		      && s[starts+len]==t[j+len]
		      && (tmask & (1<<(j+len))) != 0) ++len;
		if (mx<len) { 
		    mx=len;
		    if (starts+mx==ends) break;
		}
		
	    }
	    
	}
	return mx;
	
    }
    
}
