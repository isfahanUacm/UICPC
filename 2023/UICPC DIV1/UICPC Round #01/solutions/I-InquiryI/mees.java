import java.util.Scanner;
import java.util.ArrayList;
import java.io.*;

public class mees{

	public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        Integer n = Integer.parseInt(reader.readLine());

        ArrayList<Integer> all_ints = new ArrayList<Integer>();

        long s = 0;

        for(int i = 0; i < n; i++) {
            all_ints.add(Integer.parseInt(reader.readLine()));
            s += all_ints.get(i);
        }

        long a = 0, b = s;
        long best = 0;

        for(int i = 0; i < n; i++) {
            Integer k = all_ints.get(i);
            a = a + k*k;
            b = b - k;

            if(a*b > best)
                best = a*b;
        }
        System.out.println(best);
	}
}
