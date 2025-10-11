egypt = 1
ghana = 6
scores = []
number_of_valid_scores = 0

num_test = int(input())
if 1 <= num_test <= 10**4:
    for number in range(num_test):
        res = input().strip()
        score = res.split(':')
        if len(score) == 2 and all(s.isdigit() for s in score):
            if (0 <= int(score[0]) <= 100) and (0 <= int(score[1]) <= 100):
                scores.append(score)
                number_of_valid_scores += 1

    for lev in range(number_of_valid_scores):
        egypt_total = egypt + int(scores[lev][0])
        ghana_total = ghana + int(scores[lev][1])

        if egypt_total > ghana_total:
            print(f'Case {lev + 1}: YES')
        elif egypt_total == ghana_total:
            print(f'Case {lev + 1}: PENALTIES')
        else:
            print(f'Case {lev + 1}: NO')

    scores.clear()
