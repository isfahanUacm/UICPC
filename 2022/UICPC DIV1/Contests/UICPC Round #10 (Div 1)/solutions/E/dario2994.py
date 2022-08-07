def solve():
    s = input()
    t = input()

    def canonical_form(source):
        b = 0;
        dest = []
        for c in source:
            if c == 'B': b += 1
            elif not dest or dest[-1] != c: dest.append(c);
            else: dest.pop()
        if b % 2: dest.append('B')
        return dest

    if canonical_form(s) == canonical_form(t): print('YES')
    else: print('NO')

t = int(input())
for _ in range(t):
    solve()
