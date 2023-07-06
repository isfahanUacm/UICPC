import math

def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

T = int(input())

for _ in range(T):
    N, first_player = input().split()
    N = int(N)

    if first_player == 'Alice':
        if N == 2 or is_prime(N):
            winner = 'Alice'
        else:
            winner = 'Bob'
    else:
        winner = 'Alice' if is_prime(N) else 'Bob'

    print(winner)
