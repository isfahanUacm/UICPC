n = int(input())

tokens = input().split()
stack = []
should_add = True

for token in tokens:
    if token == "(":
        stack.append("(")
        should_add = not should_add
    elif token == ")":
        ans = 0 if should_add else 1
        while stack[-1] != "(":
            if should_add:
                ans += stack.pop()
            else:
                ans *= stack.pop()

        # Popping open parentheses
        if (stack[-1] == "("):
            stack.pop()
        should_add = not should_add
        stack.append(ans)
    else:
        stack.append(int(token))


print(sum(stack))