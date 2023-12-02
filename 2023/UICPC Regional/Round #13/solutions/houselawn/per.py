(l, m) = map(int, raw_input().split())

def parse(s):
    t = s.split(',')
    return [t[0]] + map(int, t[1:])

M = filter(lambda (n, p, c, t, r): c*t*10080 >= l*(t+r), [parse(raw_input()) for _ in range(m)])
print '\n'.join(m[0] for m in M if m[1] == min(M, key=lambda x: x[1])[1]) if M else 'no such mower'
