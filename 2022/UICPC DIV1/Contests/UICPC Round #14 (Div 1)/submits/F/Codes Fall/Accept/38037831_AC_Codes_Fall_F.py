string1 = list(input())
string2 = list(input())

if sorted(string1) != sorted(string2):
    print(0)
    exit()

min_word = 100000
max_word = 0
change = 1
cont = True
ll = len(string1)

for i in range(ll):
    if string1[i] != string2[i]:
        if i < min_word:
            min_word = i
        if i > max_word:
            max_word = i

while cont:
    cont = False
    if min_word != 0 and max_word != ll-1:
        if string1[min_word-1] == string1[max_word+1]:
            cont = True
            change += 1
            min_word -= 1
            max_word += 1

print(change)
