n, b = map(int, input().split())
print("no" if (2 ** (b + 1)) - 1 < n else "yes")