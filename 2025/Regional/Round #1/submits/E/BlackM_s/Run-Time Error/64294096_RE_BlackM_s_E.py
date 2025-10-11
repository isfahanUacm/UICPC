egypt = 1
ghana = 6
scores = []
score = []

num_test = int(input())
if 1 <= num_test <= 10**4:
    for number in range(num_test):
        res = input()
        score = res.split(':')
        if (0 <= int(score[0]) <= 100) and (0 <= int(score[-1]) <= 100):
            scores.append(res)
        
    for lev in range(0, num_test):
        if ((egypt + int(scores[lev][0])) > (ghana + int(scores[lev][-1]))):
            print(f'Case {lev + 1}: YES')
        elif ((egypt + int(scores[lev][0])) == (ghana + int(scores[lev][-1]))):
            print(f'Case {lev + 1}: PENALTIES')
        elif ((egypt + int(scores[lev][0])) < (ghana + int(scores[lev][-1]))):
            print(f'Case {lev + 1}: NO')
    scores.clear()