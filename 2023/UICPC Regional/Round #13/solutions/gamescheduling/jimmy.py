import sys

def flatten(list):
    return [item for sublist in list for item in sublist]

def flatmap(function, list):
    return flatten(map(function, list))

def tournament_odd(n):
    return map(lambda round: map(lambda no: ((no + round) % n, (n - 2 - no + round ) % n), range(n/2)), range(n))

def tournament_odd_byes(n):
    return map(lambda round: (n - 1 + round) % n, range(n))

def tournament_even(n):
    return map(lambda (round, bye): round + [(bye, n-1)], zip(tournament_odd(n-1), tournament_odd_byes(n-1)))

def tournament(n):
    return tournament_even(n) if n%2 == 0 else tournament_odd(n)

# n participants in every team, m teams
n,m = map(lambda x:int(x), sys.stdin.readline().split(' '))

p1 = flatmap(lambda pairings:
    map(lambda round:
        flatmap(lambda (home,away):
            map(lambda tbl: (tbl, home, (tbl + round) % m, away), range(m)),
            pairings),
        range(1, m)
    ), tournament(n))

if n % 2 == 0:
    pairings = p1 + map(lambda round:
            flatmap(lambda no:
                map(lambda (home,away): (home, no, away, no), round),
            range(n)),
        tournament(m))
else:
    p2 = flatmap(lambda bye: map(lambda x: map(lambda (home,away): (home, bye, away, bye), x)  ,tournament(m)), tournament_odd_byes(n))

    p4 = []
    if m % 2 == 0:
        p3 = p2
    else:
        p3 = []
        for i in range(len(p2)):
            if i % m > 0:
                p3.append(p2[i])
            else:
                p4.append(p2[i])
        p4 = flatten(p4)

    pairings = map(lambda (q1, q2): flatten([q1, q2]), zip(p1, p3))
    if len(p4) > 0:
        pairings.append(p4)

for round in pairings:
    print " ".join(map(lambda (ht, hn, at, an): "%c%d-%c%d" % (chr(ht + ord('a')), hn + 1, chr(at + ord('a')), an + 1), round))
