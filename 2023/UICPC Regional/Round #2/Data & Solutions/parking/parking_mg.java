public class parking_mg 
{
    public static void main(String[] a) throws Exception
    {
	java.util.Scanner in = new java.util.Scanner(System.in);
	for (int t=in.nextInt(); t>0; --t) {
	    int lo,hi, n=in.nextInt();
	    lo=hi=in.nextInt();
	    for (int i=1; i<n; ++i) {
		int x=in.nextInt();
		if (x<lo) lo=x;
		if(x>hi)hi=x;
	    }
	    System.out.println(2*(hi-lo));
	    
	}
    }
}
