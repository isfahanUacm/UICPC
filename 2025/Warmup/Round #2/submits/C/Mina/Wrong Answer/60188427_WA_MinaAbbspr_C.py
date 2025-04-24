def calculate(y , m , n):
    sum = 0
    if m != n:
        if y[m + 1] == '+':
            y[m] = int(y[m]) + int(y[n])
        else :
            y[m] = int(y[m]) * int(y[m + 2])
        del y[m + 1]
        del y[m + 1]
        if y[m + 1] == ')':
            del y[m + 1]
        if m != 0:
            del y[m - 1]
    else:
        del y[m + 1]
        del y[m - 1]
    return m





n = int(input())
x = input()
y = ""
for i in range(len(x) - 1):
    if x[i] == ')' and x[i + 1] == '(':
        y += ')*'
    elif x[i] == '(' and x[i + 1] == ')':
        y += '(1'
    elif x[i] == ')' and x[i + 1] == ')':
        y += ')+1'
    else:
        y += '('
y += ')'
y = list(y)
i = len(y) - 1
while i >= 0:
    if y[i] == '(':
        j = i
        while y[j] != ')':
            j += 1
        i = calculate(y , i + 1 , j - 1)
    i -= 1

if len(y) > 1:
    sum = int(y[0])
    f = 1
    while f < len(y) and y[f] != ')':
        if y[f] == '*':
            sum = sum * int(y[f + 1])
            f += 1
        elif y[f] == '+':
            sum = sum + int(y[f + 1])
            f += 1

        f += 1
    print(sum)
else:
    print(y[0])

