values = input().split()

row = int(values[0])
col = int(values[1])

turn = 0
total = row * col

for i in range(0, total):
    turn = not turn

print('W' if turn == 1 else 'P')