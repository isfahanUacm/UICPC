# Pretty Good Cube Root

if __name__ == '__main__':
    while True:
        try:
            n = int(input())
            lo, hi = 1, n
            while lo < hi:
                mid = (lo + hi) // 2 + (lo + hi) % 2
                if mid ** 3 > n:
                    hi = mid - 1
                else:
                    lo = mid
            if (lo + 1) ** 3 - n < n - lo ** 3:
                print(lo + 1)
            else:
                print(lo)
        except EOFError:
            break