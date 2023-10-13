// @EXPECTED_RESULTS@: CORRECT

#include <stack>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

const int MAXP = 5000;
const int MAXM = 101000;
const int MAXRUN = 50000000;
int bracketMatch[MAXP], tc, M, S, I;
string input, prog;
struct State{
	unsigned char mem[MAXM];
	int mid, iid, pid;
	void doStep(){
		switch(prog[pid]){
		case '-':
			--mem[mid];
			break;
		case '+':
			++mem[mid];
			break;
		case '<':
			if(--mid==-1)mid = M - 1;
			break;
		case '>':
			if(++mid==M)mid = 0;
			break;
		case '.':
// the following line will print the program output of the Brainfuck-program
//			cout << (char)mem[mid];
			break;
		case ',':
			if(iid == I)mem[mid] = 255;
			else mem[mid] = input[iid++];
			break;
		case '[':
			if(mem[mid]==0)pid = bracketMatch[pid];
			break;
		case ']':
			if(mem[mid])pid = bracketMatch[pid];
			break;
		}
		++pid;
	}
} state;

int main() {
	getline(cin,input);
	{istringstream is(input); is >> tc;}
	while(tc--){
		getline(cin,input);
		{istringstream is(input); is >> M >> S >> I;}
		getline(cin, prog);
		getline(cin, input);
		state.iid = state.pid = state.mid = 0;
		memset(state.mem,0,sizeof(state.mem));
		// precalculation of brackets:
		stack<int> brack;
		FOR(i,0,S){
			if(prog[i]=='['){
				brack.push(i);
			} else if(prog[i]==']'){
				bracketMatch[i] = brack.top();
				bracketMatch[brack.top()] = i;
				brack.pop();
			}
		}
		// simulation:
		int ST = 0;
		while(ST <= MAXRUN && state.pid < S){
			++ST;
			state.doStep();
		}
		if(state.pid == S)cout << "Terminates\n";
		else {
			int maxpid = state.pid;
			int minpid = state.pid;
			// simulate again MAXRUN steps for calculation of the loop
			while(ST--){
				state.doStep();
				maxpid = max(maxpid, state.pid);
				minpid = min(minpid, state.pid);
			}
			cout << "Loops " << minpid - 1 << " " << maxpid << endl;
		}
	}
	return 0;
}
