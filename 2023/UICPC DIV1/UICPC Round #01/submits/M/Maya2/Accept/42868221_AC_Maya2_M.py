def OctToBin(octnum):
     
    binary = "" # initialising bin as String
     
    # While loop to extract each digit
    while octnum != 0:
         
        # extracting each digit
        d = int(octnum % 10)
        if d == 0:
             
            # concatenation of string using join function
            binary = "".join(["000", binary])
        elif d == 1:
             
            # concatenation of string using join function
            binary = "".join(["001", binary])
        elif d == 2:
             
            # concatenation of string using join function
            binary = "".join(["010", binary])
        elif d == 3:
             
            # concatenation of string using join function
            binary = "".join(["011", binary])
        elif d == 4:
             
            # concatenation of string using join function
            binary = "".join(["100", binary])
        elif d == 5:
             
            # concatenation of string using join function
            binary = "".join(["101", binary])
        elif d == 6:
             
            # concatenation of string using join function
            binary = "".join(["110",binary])
        elif d == 7:
             
            # concatenation of string using join function
            binary = "".join(["111", binary])
        else:
             
            # an option for invalid input
            binary = "Invalid Octal Digit"
            break
 
        # updating the oct for while loop
        octnum = int(octnum / 10)
         
    # returning the string binary that stores
    # binary equivalent of the number
    return binary
n = int(input())
for j in range(n):
    #print(j)
    o = int(input())
    b = OctToBin(o)
    s = str(b)
    s = "0" * (19 - len(s)) + s 
    s2 = list(s[::-1])
    a = ["0"]*9
    f = False
    for i in range(0,9):
        if s2[i] == '0':
            f = True
            a[i] = 2
        else:
            a[i] = s2[i+9]

    win = ["O", "X"]

    for i in range(0,9):
        a[i] = int(a[i])


    if (a[0] == a[1] and a[1] == a[2]) and a[0] != 2:
        print(win[int(a[0])], "wins")
        continue

    if (a[3] == a[4] and a[4] == a[5]) and a[3] != 2:
        print(win[a[3]], "wins")
        continue


    if (a[6] == a[7] and a[7] == a[8]) and a[6] != 2:
        print(win[a[6]], "wins")
        continue


    if (a[0] == a[3] and a[3] == a[6]) and a[0] != 2:
        print(win[a[0]], "wins")
        continue


    if (a[1] == a[4] and a[4] == a[7]) and a[1] != 2:
        print(win[a[1]], "wins")
        continue


    if (a[2] == a[5] and a[5] == a[8]) and a[2] != 2:
        print(win[a[2]], "wins")
        continue


    if (a[0] == a[4] and a[4] == a[8]) and a[0] != 2: 
        print(win[a[0]], "wins")
        continue


    if (a[2] == a[4] and a[4] == a[6]) and a[2] != 2:
        print(win[a[2]], "wins")
        continue

    if (f == True):
        print("In progress")
        continue

    print("Cat's")
