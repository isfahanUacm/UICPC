n, ins = map(int, input().split())
A = list(map(int, input().split()))
if ins == 1:
    print(7)
elif ins == 2:
    if A[0] > A[1]:
        print('Bigger')
    elif A[0] == A[1]:
        print('Equal')
    else:
        print('Smaller')
elif ins == 3:
    print(sorted(A[0:3])[1])
elif ins == 4:
    print(sum(A))
elif ins == 5:
    print(sum([b for b in A if b % 2 == 0]))
elif ins == 6:
    print(''.join([str(chr(ord('a') + b % 26)) for b in A]))
else:
    i = 0
    cnt = 0
    while True:
        i = A[i]
        if i >= n:
            print('Out')
            break
        if i == n - 1:
            print('Done')
            break
        cnt += 1
        if cnt > n:
            print('Cyclic')
            break
