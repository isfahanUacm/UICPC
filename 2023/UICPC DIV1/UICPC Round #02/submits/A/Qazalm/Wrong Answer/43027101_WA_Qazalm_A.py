def how_many_tasks(time, tasks):
    for task_id in range(len(tasks)):
        if time < 0:
            return task_id
        time -= tasks[task_id]
    return len(tasks)

taskNtime= list(map(int, input().split()))
task_count= taskNtime[0]
time= taskNtime[1]
tasks= list(map(int, input().split()))
print(how_many_tasks(time, tasks))