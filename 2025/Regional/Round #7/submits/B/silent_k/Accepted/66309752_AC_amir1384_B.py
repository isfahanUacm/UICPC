target = input()

min = 1
max = 99

result = []

for i in range(0, len(target) - 1):
    right = target[i + 1:]
    left = target[:i + 1]
    if left.startswith('0') or right.startswith('0'):
        continue

    value_left = int(left)
    value_right = int(right)
    if min <= value_left <= max and min <= value_right <= max:
        result.append((value_left, value_right))


if len(result) != 1:
    print("-1")

else:
    values = result[0]
    print(f"{values[0]} {values[1]}")