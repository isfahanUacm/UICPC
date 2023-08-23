import java.util.*;

public class phone_mg 
{
    static Scanner in = new Scanner(System.in);
    
    public static void main(String[] a) throws Exception
    {
	for (int T=in.nextInt(); T-->0; ) {
	    String[] v = new String[in.nextInt()];
	    for (int i=0; i<v.length; ++i)
		v[i]=in.next();
	    Arrays.sort(v);
	    boolean yes=true;	
	    for (int i=1; i<v.length; ++i) {
		if (v[i].length() >= v[i-1].length()
		    && v[i-1].equals(v[i].substring(0, v[i-1].length()))) {
		    yes=false;
		    break;
		}
	    }
	    if (yes) System.out.println("YES");
	    else System.out.println("NO");
	}
    }
}
