import numpy as np

numbers = input().split()

count = int(numbers[0])
ranges = int(numbers[1])

stamps = np.array(input().split())

for i in range(0, ranges):
    count = 0
    intervals = input().split()
    left = int(intervals[0])
    right = int(intervals[1])

    for i in range(0, stamps.size):
        if left <= int(stamps[i]) <= right:
            count = count + 1

    print(count)