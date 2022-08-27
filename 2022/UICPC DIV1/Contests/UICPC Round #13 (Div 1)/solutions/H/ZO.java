/**
 * Solves Zebras and Ocelots
 * Rob Hochberg
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ZO{
    public static void main(String args[]) throws Exception {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	// Read the input
	int numCritters = Integer.valueOf(br.readLine());

	char[] critters = new char[numCritters * 3];

	long numBells = 0;
	br.read(critters, 0, 2*numCritters);
	for(int i = 0; i < numCritters; i++){
	    numBells <<= 1;
	    if(critters[2*i] == 'O')
		numBells++;
	}
	System.out.println(numBells);
    }
}
