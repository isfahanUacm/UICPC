n = int(input())
a = input()
b = input()

ans = ""
i =0
j =0
while len(ans) < n//2:

    if a[i] == b[j]:
        ans += a[i]
        i += 1
        j += 1
    elif i < j:
        i+=1
    else:
        j+=1

print(ans)