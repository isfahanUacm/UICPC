EGYPT = 1   # goals Egypt scored in the first match
GHANA = 6   # goals Ghana scored in the first match

num_test = int(input())
if 1 <= num_test <= 10**4:
    for t in range(1, num_test + 1):
        res = input().strip()
        egypt, ghana = map(int, res.split(':'))

        if not (0 <= egypt <= 100 and 0 <= ghana <= 100):
            continue

        total_egypt = EGYPT + egypt
        total_ghana = GHANA + ghana

        if total_egypt > total_ghana:
            print(f"Case {t}: YES")
        elif total_egypt == total_ghana:
            if egypt > 0:  # Egypt scored away goal
                print(f"Case {t}: YES")
            else:
                print(f"Case {t}: PENALTIES")
        else:
            print(f"Case {t}: NO")