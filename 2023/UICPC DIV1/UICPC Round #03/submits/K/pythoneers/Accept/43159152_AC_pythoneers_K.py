
n= int(input())
vaccinated = []
notVaccinated = []

for i in range(n):
    _ = input()
    if _[0] == 'N':
        notVaccinated.append(_)
        continue

    vaccinated.append(_)

def cal(i):
    yInVaccinated = list(map(lambda x: x[i] == 'Y', vaccinated)).count(True)
    yInNotVacinated = list(map(lambda x: x[i] == 'Y', notVaccinated)).count(True)
    a = yInVaccinated / len(vaccinated)
    b = yInNotVacinated / len(notVaccinated)

    if a >= b:
        return "Not Effective"
    _ = ((len(notVaccinated) * yInVaccinated) / len(vaccinated))
    return 100 - (( _ / yInNotVacinated) * 100)

print(cal(1))
print(cal(2))
print(cal(3))
