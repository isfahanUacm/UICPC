raw_input()
if max([int(x) for x in raw_input().split()]) == max([int(x) for x in raw_input().split()]):
    print("possible")
else:
    print("impossible")
