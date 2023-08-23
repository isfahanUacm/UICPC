import java.util.*;

public class shopaholic_mg 
{
    public static void main(String a[])  throws Exception
    {
	Scanner in = new Scanner(System.in);
	for (int T=in.nextInt(); T>0; --T) {
	    int N=in.nextInt();
	    int[] v = new int[N];
	    for (int i=0; i<N; ++i) v[i]=in.nextInt();
	    Arrays.sort(v);
	    int j=1,sum=0;
	    for (int i=N-1; i>=0; --i, ++j) 
		if (j%3==0) sum += v[i];		
	    System.out.println(sum);
	}
    }
}
