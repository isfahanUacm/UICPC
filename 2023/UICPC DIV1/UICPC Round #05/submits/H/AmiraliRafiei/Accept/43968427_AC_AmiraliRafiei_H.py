N = int(input())

for _ in range(N):
    b, p = map(float, input().split())

    # Calculate ABPM
    actual_BPM = (b / p) * 60
    min_ABPM = actual_BPM - (60 / p)
    max_ABPM = actual_BPM + (60 / p)

    print(f"{min_ABPM:.4f} {actual_BPM:.4f} {max_ABPM:.4f}")
