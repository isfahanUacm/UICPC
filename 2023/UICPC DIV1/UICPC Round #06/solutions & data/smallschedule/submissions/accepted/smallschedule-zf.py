#!/usr/bin/python3

Q, M, S, L = map(int, input().split())

max_load = (L+(M-1))//M*Q

if L%M: S -= (M-(L%M))*Q

if S > 0: max_load += (S+(M-1))//M

print(max_load)
