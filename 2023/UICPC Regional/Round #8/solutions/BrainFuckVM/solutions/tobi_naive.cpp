// @EXPECTED_RESULTS@: CORRECT

#include <stdio.h>
#include <stack>

using namespace std;

#define MAX_CODE 5000
#define MAX_INPUT 5000
#define MAX_DATA 100000

#define step(m) \
			curInstr++; \
 \
			if (m.codePtr >= codeSize) { \
				break; \
			} \
 \
			switch (code[m.codePtr]) { \
			case '-': \
				m.data[m.dataPtr] += 255; \
				m.data[m.dataPtr] %= 256; \
				break; \
			case '+': \
				m.data[m.dataPtr] += 1; \
				m.data[m.dataPtr] %= 256; \
				break; \
			case '<': \
				m.dataPtr += memSize - 1; \
				m.dataPtr %= memSize; \
				break; \
			case '>': \
				m.dataPtr += 1; \
				m.dataPtr %= memSize; \
				break; \
			case '[': \
				if (m.data[m.dataPtr] == 0) { \
					m.codePtr = loopIndex[m.codePtr]; \
				} \
				break; \
			case ']': \
				if (m.data[m.dataPtr] != 0) { \
					m.codePtr = loopIndex[m.codePtr]; \
				} \
				break; \
			case '.': \
				/* do nothing*/ \
				break; \
			case ',': \
				if (m.inputPtr >= inputSize) { \
					m.data[m.dataPtr] = 255; \
				} else { \
					m.data[m.dataPtr] = (unsigned) input[m.inputPtr]; \
					m.inputPtr++; \
				} \
				break; \
			} \
 \
			m.codePtr++;


char code[MAX_CODE];
char input[MAX_INPUT];
int loopIndex[MAX_CODE];
stack<int> loopStack;
bool marked[MAX_CODE];

struct machine {
	unsigned data[MAX_DATA];
	int codePtr, dataPtr, inputPtr;
};

int memSize, codeSize, inputSize;

bool equal(machine &m1, machine &m2) {
	if (m1.codePtr != m2.codePtr) {
		return false;
	}
	if (m1.inputPtr != m2.inputPtr) {
		return false;
	}
	if (m1.dataPtr != m2.dataPtr) {
		return false;
	}

	for (int i = 0; i < memSize; i++) {
		if (m1.data[i] != m2.data[i]) {
			return false;
		}
	}

	return true;
}

int main(int argc, char **argv) {
	int numCases;
	scanf("%d", &numCases);

	while (numCases --> 0) {
		scanf("%d%d%d", &memSize, &codeSize, &inputSize);
		scanf("%s", code);
		scanf("%s", input);

		machine m;
		for (int i = 0; i < memSize; i++) {
			m.data[i] = 0;
		}
		m.codePtr = m.dataPtr = m.inputPtr = 0;

		for (int i = 0; i < codeSize; i++) {
			if (code[i] == '[') {
				loopStack.push(i);
			} else if (code[i] == ']') {
				int oldIndex = loopStack.top();
				loopStack.pop();
				loopIndex[i] = oldIndex;
				loopIndex[oldIndex] = i;
			}
			marked[i] = false;
		}

		int curInstr = 0;
		while (curInstr < 50000050) {
			step(m);
		}

		if (curInstr < 50000050) {
			puts("Terminates");
		} else {

			curInstr = 0;

			marked[m.codePtr] = true;
			while (curInstr < 50000050) {
				step(m);
				marked[m.codePtr] = true;
			}
			int left, right;
			left = right = -1;
			for (int i = 0; i < codeSize; i++) {
				if (marked[i]) {
					if (left == -1) {
						left = i - 1; // -1 because [ is never reached
					}
					right = i;
				}
			}
			printf("Loops %d %d\n", left, right);
		}
	}

	return 0;
}
