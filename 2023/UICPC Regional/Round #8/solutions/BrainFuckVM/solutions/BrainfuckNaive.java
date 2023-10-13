// @EXPECTED_RESULTS@: CORRECT

import java.util.Scanner;
import java.io.FileReader;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Stack;
import java.io.IOException;

public class BrainfuckNaive {

	public static class BFData {
		byte[] dataArray;
		int ip;
		int dataIdx;
		int inputPos;
		
		public BFData (int len) { 
			dataArray = new byte[len];
			ip = 0;
			dataIdx = 0;
			inputPos = 0;
		}
	}

	static char[] instructionArray;
	static char[] inputArray;
	static int[] indexMapping;

	private static void genMapping() {
		Stack<Integer> s = new Stack<Integer>();
		for(int i = 0; i < instructionArray.length; i++){
			if(instructionArray[i] == '['){  
				s.push(i); 
			} else if(instructionArray[i] == ']'){
				int j = s.pop();
				indexMapping[i] = j;
				indexMapping[j] = i;
			} else {
				indexMapping[i] = -1;
			}
		}
	} 


	static BFData slow, fast;
	static final int MAXINSTR = 50000000;

	private static void execInstr(BFData x) {
		char c = instructionArray[x.ip];
		switch(c) {
		case '<': 
			x.dataIdx--;
			if(x.dataIdx == -1) x.dataIdx = x.dataArray.length - 1;
			x.ip++;
			break;
		case '>': 
			x.dataIdx++;
			if(x.dataIdx == x.dataArray.length) x.dataIdx = 0;
			x.ip++;
			break;
		case '+': 
			x.dataArray[x.dataIdx]++;
			x.ip++;
			break;
		case '-': 
			x.dataArray[x.dataIdx]--;
			x.ip++;
			break;
		case '[': 
			if(x.dataArray[x.dataIdx] == 0){
				x.ip = indexMapping[x.ip];
			} else {
				x.ip++;
			}
			break;
		case ']': 
			if(x.dataArray[x.dataIdx] != 0){
				x.ip = indexMapping[x.ip];
			} else {
				x.ip++;
			}
			break;
		case '.': 
			dot(x);
			x.ip++;
			break;
		case ',': 
			x.dataArray[x.dataIdx] = comma(x);
			x.ip++;
			break;
		default:
			x.ip++;
			break;
		}
	}

	@SuppressWarnings("fallthrough")
	public static void main(String args []) throws Exception {
		Scanner sc = new Scanner(System.in);
		int ntc;
		ntc = sc.nextInt();
		indexMapping = new int[100000];
		while(ntc-- != 0) {
			int memsize = sc.nextInt();
			int codeLen = sc.nextInt();
			int inputSize = sc.nextInt();
			sc.nextLine();
			instructionArray = sc.nextLine().toCharArray();
			inputArray = sc.nextLine().toCharArray();
			System.err.println("instr: " + new String(instructionArray));
			System.err.println("input: " + new String(inputArray));
			if(inputArray.length != inputSize || instructionArray.length != codeLen) {
				System.exit(1);
			}
			genMapping();
			fast = new BFData(memsize);

			boolean term = false;
			long count = 0;
			int loopstart = 500000;
			int loopend = -50000;
			while(count <= 2 * MAXINSTR) {
				execInstr(fast);
				if(count == MAXINSTR) {
					loopstart = fast.ip;
					loopend = fast.ip;
				}
				if(fast.ip <= loopstart) loopstart = fast.ip;
				if(fast.ip >= loopend)   loopend = fast.ip;
				count++;
				if(fast.ip >= instructionArray.length) {
					term = true;
					System.out.println("Terminates");
					break;
				}
			}
			if(!term) {
				System.out.println("Loops " + loopstart + " " + loopend);
			}
		}
	}

	private static byte comma(BFData d) {
		if(d.inputPos < inputArray.length)
			return (byte) inputArray[d.inputPos++];
		else
			return -1;
	}

	private static void dot(BFData x) {
		if(x == fast) {
			// System.err.print((char)x.dataArray[x.dataIdx]);
		}
	}

}
