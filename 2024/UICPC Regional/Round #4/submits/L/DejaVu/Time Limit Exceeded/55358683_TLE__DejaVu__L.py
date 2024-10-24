s = input()
p = {}
l = 0
stack = []
ans = []
ps = []

for i in range(len(s)):
    if s[i] == '(':
        stack.append(s[i])
    else:
        stack.pop()

    ps.append(s[i])

    if len(stack) == 0:
        ans.append(''.join(ps))
        p[''.join(ps)] = True
        ps = []


if len(p) > 1:
    idx = -1
    next = ans[0]
    for i in range(1, len(ans)):
        if ans[i] != ans[0]:
            idx = i
            break
        next += ans[i]
    
    for i in range(idx, len(ans)):
        print(ans[i], end='')
    for i in range(idx):
        print(ans[i], end='')
    
    print()

else:
    print('no')