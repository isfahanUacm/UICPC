count = int(input())

container = []

for counter in range(0, count):
    arguments = input().split(' ')
    command = arguments[0]
    if command == '1':
        container.append([])

    elif command == '2':
        i = int(arguments[1]) - 1
        x = int(arguments[2])
        container[i].append(x)

    elif command == '3':
        i = int(arguments[1]) - 1
        j = int(arguments[2]) - 1
        target = container[i]
        print(target[j])

    arguments.clear()