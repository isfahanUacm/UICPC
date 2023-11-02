x, y = map(int, input().split())


r = int(input())


s = 2 * r


x1 = x - r
y1 = y + r

print(x1, y1) # top left corner
print(x1 + s, y1) # top right corner
print(x1 + s, y1 - s) # bottom right corner
print(x1, y1 - s) # bottom left corner