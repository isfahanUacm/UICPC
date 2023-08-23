import java.util.*;
/* Sample solution to Circle of Debt (NCPC 2007) by Mikael Goldmann
 *
 * (1): it is never optimal for a person to both give and receive money
 *      of the same denomination.
 * (2): money of denomination 0..i-1 must be exchanged so that the
 *      resulting debts are divisible by GCD(money[i..n.1])
 */


class Config implements Comparable{
    int[] owe = new int[3];
    int cost=0;
    public int compareToNoCost(Object o) 
    {
	Config c = (Config) o;
	for (int i=0; i<3; ++i)
	    if (owe[i] != c.owe[i]) return owe[i]-c.owe[i];
	return 0;
    }

    public int compareTo(Object o) 
    {
	int cmp = compareToNoCost(o);
	if (cmp==0) cmp = cost - ((Config)o).cost;
	return cmp;
    }    
    void print(java.io.PrintStream ps) {
	for (int i=0; i<3; ++i) {
	    ps.print(owe[i] + " :");
	}
	ps.println();
	    
    }
}

public class debt_mg {
    static Scanner in = new Scanner(System.in);
    static final int   INF = 100000000;
    static final int[] VAL = { 1,  5, 10, 20,  50, 100 };
    static final int[] MOD = { 5, 10, 10, 50, 100, INF   };
    
    int best;
    int[][] money = new int[3][VAL.length];
    

    public static void main(String[] a) throws Exception
    {
	int T=in.nextInt();
	for (int i=0; i<T; ++i) {
	    //System.err.println("Case " + (i+1));	    
	    new debt_mg().solve();
	}
    }
    
    void solve() throws Exception{
	best = INF;
	
	int ab = in.nextInt(), bc = in.nextInt(), ca = in.nextInt();
	Config c = new Config();
	c.owe[0] = ab-ca;
	c.owe[1] = bc-ab;
	c.owe[2] = ca-bc;
	for (int i=0; i<3; ++i)
	    for (int j=0; j<VAL.length; ++j)
		money[i][VAL.length-j-1] = in.nextInt();
	ArrayList<Config> lst = new ArrayList<Config>();
	lst.add(c);
	solve(lst,0);
    }

    void solve(ArrayList<Config> lst, int m) 
    {
	if (m==VAL.length) { // find best solution
	    if (best!=INF) System.out.println(best);
	    else System.out.println("impossible");
	}
	else {
	    
	    ArrayList<Config> newlst = new ArrayList<Config>();

	    for (Config c : lst) {		    
		for (int i=0; i<3; ++i) {
		    int j=(i+1)%3;
		    int k=(i+2)%3;
		    int oi, oj, ok;		    

		    int mim=money[i][m];
		    int mjm=money[j][m];
		    int mkm=money[k][m];

		    for (int gj=-mjm; gj<=mim; ++gj) { 
			// gj < 0 <--> i is getting from both j and k
			// gj >= 0 <--> i is giving to both j and k
			oj = c.owe[j]+gj*VAL[m];
			if ((oj+MOD[m])%MOD[m]!=0) continue;
			int gklow = gj < 0 ? -mkm : 0;
			int gkhigh = gj < 0 ? -1 : mim-gj;
			for (int gk=gklow; gk<=gkhigh; ++gk) {
			    oi = c.owe[i]-(gj+gk)*VAL[m];
			    if ((oi+MOD[m])%MOD[m]!=0) continue;
			    ok = c.owe[k]+gk*VAL[m];
			    int cst = c.cost+ Math.abs(gj+gk);
			    if (cst >= best) break;
			    if (oi==0 && oj==0 && ok==0) {
				if ( cst<best) best=cst;
				continue;
			    }
			    Config newc = new Config();
			    newc.cost = cst;
			    newc.owe[i]=oi;
			    newc.owe[j]=oj;
			    newc.owe[k]=ok;
			    newlst.add(newc);
			}
		    
		    }		    
		}
	    }
	    solve(filter(newlst),m+1);	    
	}
    }

    
    ArrayList<Config> filter(ArrayList<Config> lst)
    {
	if (lst.size()==0) return lst;
	Config[] cv = lst.toArray(new Config[0]);
	ArrayList<Config> nlst = new ArrayList<Config>();
	Arrays.sort(cv);	
	Config c=null;
	for (Config c1 : cv) {
	    if (c==null || c.compareToNoCost(c1) != 0) {
		c=c1;
		nlst.add(c);
	    }
	}
	return nlst;
    }
}
