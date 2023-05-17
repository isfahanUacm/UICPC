import java.io.*;
import java.util.StringTokenizer;

public class harry_square_sums {

    public static void main(String []args) throws IOException {
        Scanner in = new Scanner(System.in);
        OutputWriter out = new OutputWriter(System.out);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }

}

class Task{
    public void solve(Scanner in, OutputWriter out) throws IOException{
		int n = in.nextInt();
		Long[] a = new Long[n];
		for(int i = 0; i < n; i++)
			a[i] = in.nextLong();

		Long[] pre = new Long[n]; // Sum squares from 0 to i (inclusive)
		Long[] suf = new Long[n]; // Sum from i to n-1 (inclusive)

		pre[0] = a[0] * a[0];
		for(int i = 1; i < n; i++)
			pre[i] = pre[i-1] + a[i] * a[i];

		suf[n-1] = a[n-1];
		for(int j = n-2; j >= 0; j--)
			suf[j] = suf[j+1] + a[j];

		long max = 0;
		for(int i = 0; i < n-1; i++)
		{
			Long prod = pre[i] * suf[i+1];
			max = Math.max(max, prod);
		}
		out.print(max);
		out.print("\n");
    }
}

class Scanner{
    public BufferedReader reader;
    public StringTokenizer st;

    public Scanner(InputStream stream){
        reader = new BufferedReader(new InputStreamReader(stream));
        st = null;
    }

    public String next(){
        while(st == null || !st.hasMoreTokens()){
            try{
                String line  = reader.readLine();
                if(line == null) return null;
                st =  new StringTokenizer(line);
            }catch (Exception e){
                throw (new RuntimeException());
            }
        }
        return st.nextToken();
    }

    public int nextInt(){
        return Integer.parseInt(next());
    }
    public long nextLong(){
        return Long.parseLong(next());
    }
    public double nextDouble(){
        return Double.parseDouble(next());
    }
}

class OutputWriter{
    BufferedWriter writer;

    public OutputWriter(OutputStream stream){
        writer = new BufferedWriter(new OutputStreamWriter(stream));
    }

    public void print(int i) throws IOException {
        writer.write(i);
    }

    public void print(String s) throws IOException {
        writer.write(s);
    }

    public void print(char []c) throws IOException {
        writer.write(c);
    }
    
    public void print(Long l) throws IOException {
        writer.write(Long.toString(l));
    }
    
    
    public  void close() throws IOException {
        writer.close();
    }

}
