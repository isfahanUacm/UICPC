n, m = map(int, input().split())
tasks = list(map(int, input().split()))
intervals = list(map(int, input().split()))

# Sort tasks and intervals in ascending order
tasks.sort()
intervals.sort()

task_idx = 0  # Index of the current task
count = 0  # Count of completed tasks

for interval in intervals:
    if task_idx == n:
        # All tasks are completed
        break

    if tasks[task_idx] <= interval:
        # Assign the task to the current interval
        count += 1
        task_idx += 1

print(count)
