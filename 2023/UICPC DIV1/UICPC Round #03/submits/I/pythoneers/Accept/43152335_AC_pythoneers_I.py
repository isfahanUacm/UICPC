
def main():
    n = int(input())

    inputs = []
    for i in range(n):
        inputs.append(int(input()))
    
    if n % 2 != 0:
        print("still running")
        return

    answer = 0

    for i in range(0, len(inputs), 2):
        answer += inputs[i + 1] - inputs[i]

    print(answer)

main()