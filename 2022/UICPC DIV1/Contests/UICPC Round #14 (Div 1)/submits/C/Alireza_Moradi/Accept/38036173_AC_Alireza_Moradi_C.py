lines = []
line1 = input()
line2 = input()
line3 = input()
line4 = input()
line5 = input()
lines.append(line1)
lines.append(line2)
lines.append(line3)
lines.append(line4)
lines.append(line5)

def find(x,y):
    l=[]
    for i in range(1,3,1):# 1, 2
        if i==1:
            j=2
            #l.append(tuple((x+i, y+2)))
        else:
            j=1
        l.append(tuple((x+i, y+j)))
        l.append(tuple((x+i, y-j)))
        i*=-1
        l.append(tuple((x + i, y + j)))
        l.append(tuple((x + i, y - j)))
    return l

is_end=False
k_count = 0

for line in range(5):
    if is_end == False:
        for char in range(5):
            if lines[line][char] == 'k' and is_end == False:
                # list of tuples
                k_count += 1
                indexes = find(line, char)
                for cord in indexes:
                    if cord[0]>-1 and cord[1]>-1 and cord[0]<5 and cord[1]<5:
                        x = cord[0]
                        y = cord[1]
                        if lines[x][y] == 'k':
                            print("invalid")
                            is_end=True
                            break
    else:
        break

if is_end == False and k_count == 9:
    print("valid")
elif is_end == False and k_count != 9:
    print("invalid")