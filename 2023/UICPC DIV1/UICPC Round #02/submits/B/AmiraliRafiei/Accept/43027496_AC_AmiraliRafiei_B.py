n = int(input())

def test(ps,bd, c):
    p = ps.split('/')
    b = bd.split('/')

    p = [int(x) for x in p]
    b = [int(x) for x in b]

    if p[0] >= 2010:
        return 'eligible'
    elif b[0] >= 1991:
        return 'eligible'
    elif c >= 41:
        return 'ineligible'
    else:
        return 'coach petitions'

for i in range (n):
    name, ps, bd, c = input().split()
    c = int(c)
    print(name, test(ps, bd, c))