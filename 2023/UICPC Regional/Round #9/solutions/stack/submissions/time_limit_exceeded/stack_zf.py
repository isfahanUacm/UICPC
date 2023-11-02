#!/usr/bin/python3

# takes about 12 seconds on my Mac on sample 02

def solve(i,j,s,memo):
    if (i,j) not in memo:
        if i>j:
            memo[(i,j)] = 0
        else:
            memo[(i,j)] = solve(i,j-1,s,memo) + 1
            for k in range(i,j):
                if s[k] == s[j]:
                    memo[(i,j)] = min(memo[(i,j)],
                                solve(i,k,s,memo) + solve(k+1,j-1,s,memo))

    return memo[(i,j)]

n = int(input())
for i in range(n):
    s = input()
    print(len(s) + 2*solve(0,len(s)-1,s,{}))
