import math
import math
n = int(input())

dis = (60 * math.pi) / 28

for _ in range(n):
    total_dis = 0
    total_time = 0
    word = input()
    if word[0] == " ":
        c_p = 27
    elif word[0] == "'":
        c_p = 28
    else:
        c_p = ord(word[0]) - ord("A") + 1


    for i in word:

        if i == " ":
            ii = 27
        elif i == "'":
            ii = 28
        else:
            ii = ord(i) - ord("A") + 1

        total_time += 1
        if ii != c_p:
            total_dis += dis * min([abs(c_p - ii), 28 - abs(ii - c_p)])

        c_p = ii

    total_time += (total_dis / 15)
    print(round(total_time, 10))

