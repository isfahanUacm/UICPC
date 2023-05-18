input()
print("possible" if max([int(x) for x in input().split()]) == max([int(x) for x in input().split()]) else "impossible")
