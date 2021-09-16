a, b = map(int, input().split())
c, d = map(int, input().split())
t = int(input())
print('Y' if t >= (abs(a-c) + abs(b-d)) and not (t - (abs(a-c) + abs(b-d))) % 2 else 'N')