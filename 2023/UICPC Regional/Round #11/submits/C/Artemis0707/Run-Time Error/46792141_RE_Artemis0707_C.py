import math

while True:
    s = input()
    if len(s) == 0:
        break
    
    R, S = s.split()
    R = int(R)
    S = float(S)

    aim = math.sqrt(R * (S + 0.16) / 0.067)
    c = math.ceil(aim)
    f = math.floor(aim)
    
    if aim - f > c - aim:
        print(c)
    else:
        print(f)