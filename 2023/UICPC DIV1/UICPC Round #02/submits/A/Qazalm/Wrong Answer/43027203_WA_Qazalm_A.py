def how_many_tasks(time, tasks):
    if tasks[0] > time:
        return 0
    for task_id in range(len(tasks)):
        if time < 0:
            return task_id- 1
        time -= tasks[task_id]
    return len(tasks)

taskNtime= list(map(int, input().split()))
task_count= taskNtime[0]
time= taskNtime[1]
tasks= list(map(int, input().split()))
print(how_many_tasks(time, tasks))