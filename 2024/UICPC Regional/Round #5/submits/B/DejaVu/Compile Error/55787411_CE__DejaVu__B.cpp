from math import pow

p = []

for i in range(55):
    for j in range(37):
        for a in range(19):
            for b in range(19):
                if i + j + a + b > 0 and i // 3 + j // 2 + a + b < 18:
                    p.append(int(pow(2, i) * pow(3, j) * pow(5, a) * pow(7, b)))

p.sort()
print(2)