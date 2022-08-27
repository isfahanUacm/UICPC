/**
 * Solver for Urban Design
 */

import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.stream.Stream;
import java.util.Arrays;

public class UrbanDesign{
    static int[][] streets;
    
    public static void main(String[] args) throws Exception {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	// Read the input
	int S = Integer.valueOf(br.readLine());
	streets = new int[S][4];
	for(int i = 0; i < S; i++){
	    String line = br.readLine();
	    StringTokenizer st = new StringTokenizer(line);
	    for(int j = 0; j < 4; j++){
		streets[i][j] = Integer.parseInt(st.nextToken());
	    }
	}
	// Process the towns
	int T = Integer.valueOf(br.readLine());
	for(int i = 0; i < T; i++){
	    String line = br.readLine();
	    StringTokenizer st = new StringTokenizer(line);
	    int[] towns = new int[4];
	    for(int j = 0; j < 4; j++){
		towns[j] = Integer.parseInt(st.nextToken());
	    }
	    solve(towns);
	}
    }

    static void solve(int[] towns){
	int a = towns[0], b = towns[1], c = towns[2], d = towns[3];
	boolean same = true;
	for(int[] street : streets){
	    int x1 = street[0], y1 = street[1], x2 = street[2], y2 = street[3];
	    same = same ^ ( (x2-x1)*(d-y1) - (y2-y1)*(c-x1) < 0)
		^ ( (x2-x1)*(b-y1) - (y2-y1)*(a-x1) < 0);
	}
	System.out.println(same ? "same" : "different");
    }
}
