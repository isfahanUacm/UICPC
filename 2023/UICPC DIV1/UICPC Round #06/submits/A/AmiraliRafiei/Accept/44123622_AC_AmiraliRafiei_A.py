def calculate_qaly(N):
    qaly = 0.0

    for _ in range(N):
        q, y = map(float, input().split())
        qaly += q * y

    return qaly

N = int(input())

accumulated_qaly = calculate_qaly(N)
print(f"{accumulated_qaly:.3f}")