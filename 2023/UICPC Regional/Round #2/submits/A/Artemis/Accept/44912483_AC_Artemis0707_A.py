for _ in range(int(input())):
    n = int(input())
    ph = []
    for i in range(n):
        ph.append(input())
    
    ph.sort()
    flag = True
    for i in range(n-1):
        if ph[i] == ph[i+1][:len(ph[i])]:
            flag = False
            break
    if flag:
        print("YES")
    else:
        print("NO")