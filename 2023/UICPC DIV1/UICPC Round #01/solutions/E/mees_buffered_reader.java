import java.util.Scanner;
import java.util.ArrayList;
import java.io.*;

public class mees_buffered_reader {

	public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] nums = reader.readLine().split(" ");
        
        Integer n = Integer.parseInt(nums[0]);
        Integer m = Integer.parseInt(nums[1]);

        ArrayList<Integer> forward = new ArrayList<Integer>();
        ArrayList<Integer> backward = new ArrayList<Integer>();

        for(int i = 0; i < m; i++) {
            String[] nodes = reader.readLine().split(" ");

            Integer a = Integer.parseInt(nodes[0]);
            Integer b = Integer.parseInt(nodes[1]);

            if(a < b) {
                forward.add(i+1);
            }
            else {
                backward.add(i+1);
            }
        }

        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

        if(forward.size() < backward.size()) {
            out.write(Integer.toString(forward.size()));
            out.write("\n");

            for(int i = 0; i < forward.size(); i++) {
                out.write(Integer.toString(forward.get(i)));
                out.write("\n");
            }
        }
        else {
            out.write(Integer.toString(backward.size()));
            out.write("\n");

            for(int i = 0; i < backward.size(); i++) {
                out.write(Integer.toString(backward.get(i)));
                out.write("\n");
            }
        }
        out.flush();
	}
}
