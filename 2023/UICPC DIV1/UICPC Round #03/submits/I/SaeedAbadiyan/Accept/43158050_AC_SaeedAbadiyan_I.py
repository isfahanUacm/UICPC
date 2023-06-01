n = int(input())
last_press = 0
total_time = 0
running = False

for i in range(n):
    press_time = int(input())
    if running:
        total_time += press_time - last_press
    last_press = press_time
    running = not running

if running:
    print("still running")
else:
    print(total_time)