n = int(input())

tokens = input().split()
stack = []
should_add = True

temp_num = 0
is_reading_num = False

for token in tokens:
    if token == "(":
        if is_reading_num:
            is_reading_num = False
            stack.append(temp_num)

        stack.append("(")
        should_add = not should_add
    elif token == ")":
        # Popping open parentheses
        if (len(stack) > 0 and stack[-1] == "("):
            stack.pop()

        should_add = not should_add

        if len(stack) > 0 and type(stack[-1]) == int:
            if (should_add):
                stack[-1] += temp_num
            else:
                stack[-1] *= temp_num
            
            temp_num = stack.pop()

    else:
        if not is_reading_num:
            temp_num = 0 if should_add else 1
        
        is_reading_num = True
        if should_add:
            temp_num += int(token)
        else:
            temp_num *= int(token)

print(temp_num % int(1e9+7))