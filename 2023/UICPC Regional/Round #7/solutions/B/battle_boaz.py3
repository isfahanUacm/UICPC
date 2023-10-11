import sys
from collections import deque

MAX_LENGTH = 1000000
ALLOWED_MOVES = ['R', 'B', 'L']

instr = sys.stdin

def solve():
    ignore = 0
    moves = []
    length = 0

    for i in range(0, 3):
        move = instr.read(1)
        moves.append(move)
        if move and move != '\n':
            check_move(move)
            length += 1

    assert length > 0

    while moves[0]:
        if not moves[0]: return

        if ignore:
            ignore -= 1
        else:
            if moves[0] == 'R': 
                if (moves[1] == 'B' and moves[2] == 'L') or (moves[1] == 'L' and moves[2] == 'B'): 
                    print("C", end='')
                    ignore = 2
                else: print("S", end='') 
            if moves[0] == 'B': 
                if (moves[1] == 'R' and moves[2] == 'L') or (moves[1] == 'L' and moves[2] == 'R'): 
                    print("C", end='')
                    ignore = 2
                else: print("K", end='')
            if moves[0] == 'L': 
                if (moves[1] == 'B' and moves[2] == 'R') or (moves[1] == 'R' and moves[2] == 'B'):
                    print("C", end='')
                    ignore = 2
                else: print("H", end='')

        input = instr.read(1)
        if input and input != '\n':
            length += 1
            assert length <= MAX_LENGTH
            check_move(input)

        moves[0] = moves[1]
        moves[1] = moves[2]
        moves[2] = input
    print("\n", end='')
	
def check_move(move):
    assert move in ALLOWED_MOVES

def main():
    solve()

if __name__ == "__main__":
    main()
