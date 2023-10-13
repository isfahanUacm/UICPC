// @EXPECTED_RESULTS@: CORRECT

import java.io.*;
import java.util.Stack;
public class Alex_BF{
	static final int MAXP = 5000;
	static final int MAXM = 101000;
	static final int MAXRUN = 50000000;
	static int bracketMatch[], tc, M, S, I;
	static String input, prog;
	static int mem[];
	static int mid, iid, pid;
	static void doStep(){
		switch(prog.charAt(pid)){
		case '-':
			mem[mid] = (mem[mid] - 1) & 255;
			break;
		case '+':
			mem[mid] = (mem[mid] + 1) & 255;
			break;
		case '<':
			if(--mid==-1)mid = M - 1;
			break;
		case '>':
			if(++mid==M)mid = 0;
			break;
		case '.':
// the following line will print the program output of the Brainfuck-program
//			System.out.print((char)mem[mid]);
			break;
		case ',':
			if(iid == I)mem[mid] = 255;
			else mem[mid] = input.charAt(iid++);
			break;
		case '[':
			if(mem[mid]==0)pid = bracketMatch[pid];
			break;
		case ']':
			if(mem[mid]!= 0)pid = bracketMatch[pid];
			break;
		}
		++pid;
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		tc = Integer.parseInt(reader.readLine());
		bracketMatch = new int[MAXP];
		while(tc-->0){
			String arr[] = reader.readLine().split("[ ]+");
			M = Integer.parseInt(arr[0]);
			S = Integer.parseInt(arr[1]);
			I = Integer.parseInt(arr[2]);
			mem = new int[M];
			prog = reader.readLine();
			input = reader.readLine();
			iid = pid = mid = 0;
			Stack<Integer> brack = new Stack<Integer>();
			for(int i = 0; i < S; i++){
				if(prog.charAt(i)=='['){
					brack.push(i);
				} else if(prog.charAt(i)==']'){
					bracketMatch[i] = brack.peek();
					bracketMatch[brack.pop()] = i;
				}
			}
			int ST = 0;
			while(ST <= MAXRUN && pid < S){
				++ST;
				doStep();
			}
			if(pid == S)System.out.println("Terminates");
			else {
				int maxpid = pid;
				int minpid = pid;
				while(ST-->0){
					doStep();
					maxpid = Math.max(maxpid, pid);
					minpid = Math.min(minpid, pid);
				}
				System.out.println("Loops " + (minpid - 1) + " " + maxpid);
			}
		}
		System.exit(0);
	}
}
