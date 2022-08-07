import java.io.*;
import java.util.*;

public class Main {
    
    static class FastScanner {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringTokenizer st = new StringTokenizer("");
    	String next() {
    		while (!st.hasMoreTokens())
    			try { 
                        st=new StringTokenizer(br.readLine());				               
                    } catch (IOException e) {}
    		return st.nextToken();
    	}
    	
    	int nextInt() {
    		return Integer.parseInt(next());
    	}
    }

    public static void main(String args[]) {
        FastScanner scanner = new FastScanner();
        int n = scanner.nextInt();
        Integer[] p = new Integer[n * n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int a = scanner.nextInt();
                p[a - 1] = i * n + j;
            }
        }
        
        Long[] rowCnt = new Long[n];
        Long[] colCnt = new Long[n];
        for(int i = 0; i < n; ++i) {
            rowCnt[i] = new Long(0);
            colCnt[i] = new Long(0);
        }
        Long ans = (new Long(n)) * n * (n - 1) * (n - 1) / 2;
        for(int k : p) {
            int i = k / n;
            int j = k % n;
            ans -= rowCnt[i] * colCnt[j];
            rowCnt[i]++;
            colCnt[j]++;
        }
        
        System.out.println(ans);
    }
}
