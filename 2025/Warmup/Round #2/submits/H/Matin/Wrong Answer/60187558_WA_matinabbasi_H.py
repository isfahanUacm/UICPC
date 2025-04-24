



# from math import gcd



# n = int(input())


# numbers= list(map(int , input().split()))

# ans = 0
# for i in range(1, n):
#     ans += gcd(numbers[i-1], numbers[i])
# print(ans)


# bits = [0]*21                                                                                                                                                                                                                                                 

# n= int(input())
# numbers= list(map(int , input().split()))



# for a in numbers:
#     for i in range(20):
#         bits[i] += (a>>i)&1

# print(bits)
from math import gcd
n = int(input())
a = list(map(int, input().split()))
a.sort()
ans = 0
for i in range(n):
    t = 0
    for j in range(i+1, n):
        t = max(t, gcd(a[i], a[j]))
    ans += t
print(ans)