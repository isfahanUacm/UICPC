n = int(input())
q = int(input())
k = int(input())
l = input()
f = 10**8 if l == "java" else 5 * 10**8 if l == "cpp" else 2 * 10**7
ml = n*k > 2 * 10 ** 7
tl = n * (5 * k + 2 * q) > f

if ml and tl:
    print("TL and ML")
elif ml:
    print("ML")
elif tl:
    print("TL")
else:
    print("OK")