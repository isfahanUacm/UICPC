import java.util.*;
import java.text.*;

public class moogle_mg 
{
    static Scanner in = new Scanner(System.in);
    static DecimalFormat format = new  DecimalFormat("0.0000\n");
    static FieldPosition fp = new FieldPosition(format.FRACTION_FIELD);
    static StringBuffer sb =  new StringBuffer();    

    double [][] mem;
    boolean[][] memok;
    
    public static void main(String[] a) throws Exception
    {
	int T=in.nextInt();
	while (T-->0)  new moogle_mg().solve();	    
	System.out.print(sb);	
    }

    
    double opt2(int[] v, int i, int k) 
    {
	if (k <= i+1) return 0;
	if (!memok[i][k]) {
	    memok[i][k]=true;
	    double sum=0;
	    double step=1.0/(k-i);	
	    double q=step;	
	    for (int j=i+1; j<k; ++j, q+=step) {	    
		double x = v[i]*(1-q) + v[k]*q;
		double err = v[j]-x;
		if (err<0) err=-err;
		sum += err;	    
	    }
	    mem[i][k]= sum;
	}
	return mem[i][k];
    }
    
    void solve()  throws Exception
    {
	int H=in.nextInt(), C=in.nextInt();
	int [] loc=new int[H];
	for (int i=0; i<H; ++i) loc[i]=in.nextInt();
	Arrays.sort(loc);
	double [] opt = new double[H]; // opt[i] best solution for houses 0..i
	double [] prevopt = new double[H];
	double [] tmp;
	mem = new double[H][H];
	memok = new boolean[H][H];
	
	for (int i=0; i<H; ++i)  opt[i] = opt2(loc,0,i);
	for (int k=3; k<=C; ++k) {
	    tmp = prevopt;
	    prevopt=opt;
	    opt=tmp;
	    for (int i=0; i<k; ++i) opt[i]=0;
	    double o2;	    
	    for (int i=k; i<H; ++i) {
		// cost of using k-1 for houses 0..k-2 is 0
		opt[i]=opt2(loc,k-2,i);
		for (int j=k-1; j<i; ++j)
		    if (opt[i] > (o2=prevopt[j] + opt2(loc,j,i)))
			opt[i] = o2;
	    }
	}
	//System.out.println(format.format(opt[H-1]/H, new StringBuffer(), fp));
	format.format(opt[H-1]/H, sb, fp);
    }
}

