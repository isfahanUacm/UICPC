ta = input()
td = input()
p = int(input())
h = int(input())
x = 0

if (ta == "F" and td == "G") or (ta == "G" and td == "W") or (ta == "W" and td == "F"):
    x = h - p*2
else:
    x = h - p/2

if x <= 0:
    print('Nocaute!')
else:
    print(f'Sobraram {int(x)} pontos de vida!')