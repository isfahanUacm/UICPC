(l, m) = map(int, raw_input().split())

def parse(s):
    t = s.split(',')
    return [t[0]] + map(int, t[1:])

def check(mower):
    (_, _, c, t, r) = mower
    cut = 0
    phase = 0
    time = 0
    weeks = 0
    while weeks < t+r:
        if time == 10080:
            weeks += 1
            time = 0
            if cut < weeks*l: return False
        if phase < t:
            dt = min(10080-time, t-phase)
            cut += c*dt
            phase += dt
            time += dt
        else:
            dt = min(10080-time, t+r-phase)
            phase += dt
            time += dt
            if phase == t+r: phase = 0
    return True


M = filter(check, [parse(raw_input()) for _ in range(m)])
print '\n'.join(m[0] for m in M if m[1] == min(M, key=lambda x: x[1])[1]) if M else 'no such mower'
