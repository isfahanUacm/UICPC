#!/bin/python3

import sys, collections

n, w = map(int, input().split())

guesses = {}
guesses.update({tuple(input().split()) for _ in range(n)})

def consistent(w, res):
    for t in res:
        cnt_w = collections.defaultdict(int)
        cnt_t = collections.defaultdict(int)
        blk = set()

        for i in range(5):
            if res[t][i] == 'G':
                if w[i] != t[i]: return False
                continue

            if w[i] == t[i]: return False
            cnt_w[w[i]] += 1

            if res[t][i] == '-': blk.add(t[i])
            else: cnt_t[t[i]] += 1

        for x in cnt_t:
            if cnt_w[x] < cnt_t[x]: return False
        for x in blk:
            if cnt_w[x] > cnt_t[x]: return False

    return True

solutions = [w for w in sys.stdin if consistent(w[:-1], guesses)]
print(*solutions, sep="", end="")
