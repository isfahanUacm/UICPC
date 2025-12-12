numbers = input().split()

count = int(numbers[0])
ranges = int(numbers[1])

stamps = input().split()

for i in range(0, ranges):
    count = 0
    intervals = input().split()
    left = int(intervals[0])
    right = int(intervals[1])
    for time in stamps:
        if left <= int(time) <= right:
            count = count + 1

    print(count)