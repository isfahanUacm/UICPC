s = input()
arr = s.split(" ")

n = int(arr[0])
p = int(arr[1])
ans = 0

tp = min(p-1 , n-(p-1))
tn = n
val =1
mine = 2
val2= 1
val3 = 1
while tp != 0 :
    val *= tn
    tn =- 1
    tp -= 1

tp = min(p-1 , n-(p-1))
while tp != 0 :
    val /= tp
    tp -= 1

val3 = val
n += 1
val3 *= n
tp = min(p-1 , n-(p-1))
p = tp + 1
val3 /= p
ans = val * val2 / val3
temp = ans
while True:
    n += 1
    val2 = mine
    val3 *= n
    val3 /= n - p
    temp = val * val2 / val3
    mine += 1

    if ans > temp:
        break
    else:
        ans = temp



formatted = "{:.7f}".format(ans)
print(formatted)