input()
if max([int(x) for x in input().split()]) == max([int(x) for x in input().split()]):
    print("possible")
else:
    print("impossible")
