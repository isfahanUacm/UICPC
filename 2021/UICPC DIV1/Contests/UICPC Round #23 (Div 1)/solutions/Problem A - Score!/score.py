def calc(t2, t1):
    t1m, t1s = map(int, t1.split(':'))
    t2m, t2s = map(int, t2.split(':'))
    t1, t2 = t1m * 60 + t1s, t2m * 60 + t2s
    return t2 - t1


def update():
    global tl, lead, time, lasttime
    if lead == 'A':
        tl['A'] += calc(time, lasttime)
    elif lead == 'H':
        tl['H'] += calc(time, lasttime)


def timestr(t):
    tm, ts = t // 60, t % 60
    return f'{tm:01}' + ':' + f'{ts:02}'


n = int(input())
p = {'H': 0, 'A': 0}
tl = {'H': 0, 'A': 0}
lead = '-'
lasttime = '00:00'
for i in range(n):
    team, point, time = map(str, input().split())
    p[team] += int(point)
    if p['H'] > p['A']:
        update()
        lead = 'H'
    elif p['H'] < p['A']:
        update()
        lead = 'A'
    else:
        update()
        lead = '-'
    lasttime = time
if lead == 'H':
    tl['H'] += calc('32:00', lasttime)
else:
    tl['A'] += calc('32:00', lasttime)
ta = timestr(tl['A'])
th = timestr(tl['H'])
print('A' if p['A'] > p['H'] else 'H', th, ta)
