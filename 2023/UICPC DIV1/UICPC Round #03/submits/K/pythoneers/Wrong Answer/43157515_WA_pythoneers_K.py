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
    a = list(map(lambda x: x[i] == 'Y', vaccinated)).count(True)
    b = list(map(lambda x: x[i] == 'Y', notVaccinated)).count(True)
    result = (a / b) * 100
    if result > 100:
        return "Not Effective"
    
    return 100 - result 

print(cal(1))
print(cal(2))
print(cal(3))

