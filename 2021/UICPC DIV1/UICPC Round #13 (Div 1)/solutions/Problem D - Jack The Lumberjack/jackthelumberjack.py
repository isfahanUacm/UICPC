all_species = []


def calc(t):
    global all_species
    s = 0
    for species in all_species:
        if t < species[3]:
            continue
        elif t <= species[3] + species[0]:
            s += species[2] + (t-species[3]) * species[1]
        else:
            s += max(0, species[2] + species[0] * species[1] - (t-species[3]-species[0]) * species[1])
    return s


n = int(input())
for i in range(n):
    all_species.append(tuple(map(int, input().split())))
res = 0
for species in all_species:
    res = max(res, calc(species[3] + species[0]))
print(res)
