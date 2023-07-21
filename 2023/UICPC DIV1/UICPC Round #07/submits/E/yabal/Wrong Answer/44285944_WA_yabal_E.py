from math import floor

n = int(input())
p = input().split()
population = []
answer = 0

for i in range(n):
    population.append(int(p[i]))

sorted(population,reverse=True)

for i in range(n):
    if i < floor(n/2):
        answer += population[i]
    else:
        answer += floor(population[i] / 2)

print(answer)