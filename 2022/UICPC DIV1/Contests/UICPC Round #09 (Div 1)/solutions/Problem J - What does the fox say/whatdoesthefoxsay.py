for i in range(int(input())):
    sounds = input().split()
    u_sounds = set()
    while True:
        line = input().split()
        if len(line)==3:
            u_sounds.add(line[2])
        else:
            p = []
            for s in sounds:
                if s not in u_sounds:
                    p.append(s)
            print(" ".join(p))
            break