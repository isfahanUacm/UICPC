s = input()

if s.__len__() % 2 == 0:
    print(':)')
else:
    print(s[(s.__len__()//2 +1)-1])