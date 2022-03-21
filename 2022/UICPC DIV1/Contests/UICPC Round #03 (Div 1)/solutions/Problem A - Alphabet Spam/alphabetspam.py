inp = input()
li = [0, 0, 0, 0]
for a in inp:
    if a == '_':
        li[0] += 1
    elif ord('a') <= ord(a) <= ord('z'):
        li[1] += 1
    elif ord('A') <= ord(a) <= ord('Z'):
        li[2] += 1
    else:
        li[3] += 1
for a in li:
    print("%.6f" % (a/len(inp)))
