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
exec(f"print({y})")
