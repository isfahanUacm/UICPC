


str1 = input()
str2 = input()
counter = 0
resultt = 0
i = 0
while str1[i] == str2[i]:
    i += 1

j = len(str1)-1
while str1[j] == str2[j]:
    j -= 1
counterj = j+1
counteri = i-1
while i <= counterj-1:
    if str1[i] != str2[j]:
        print(0)
        resultt = -1
        break
    i += 1
    j -= 1 
if resultt != -1:
    i = counteri
    j = counterj
    counter = 1
    # print(i,j)
    while i-counter >= 0 :
        if str1[i-counter] == str1[j+counter]:
            resultt +=1
        counter +=1
    print(counter)

