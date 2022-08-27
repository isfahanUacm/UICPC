"""
Solves Urban Design
"""

def solveProblem((a, b, c, d)):
    global streets

    same = True
    for (x1, y1, x2, y2) in streets:
        same = same ^ ( (x2-x1)*(d-y1) - (y2-y1)*(c-x1) < 0)\
                    ^ ( (x2-x1)*(b-y1) - (y2-y1)*(a-x1) < 0)
    print "same" if same else "different"
    


from sys import stdin
S = int(stdin.readline())
streets = []
for i in range(S):
    streets.append(map(int, stdin.readline().split(" ")))

T = int(stdin.readline())
for i in range(T):
    solveProblem(map(int, stdin.readline().split(" ")))

