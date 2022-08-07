for T in range(int(input())):
    n = int(input())
    problems = [[] for j in range(10)]
    for i in range(n):
        b,d = map(int, input().split())
        problems[d-1].append(b)
    #print(problems)
    beauty = 0
    if n<10:
        print("MOREPROBLEMS")
    else:
        for p in problems:
            if len(p):
                p.sort()
                #print(p)
                beauty+=p[-1]
            else:
                print("MOREPROBLEMS")
                break
        else:
            print(beauty)