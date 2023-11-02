#!/usr/bin/env python3
import sys

def parse(s):
    return int(100.0 * float(s.strip()))

def main():
    lines = sys.stdin.readlines()
    tf, tr = map(parse, lines[:2])
    speeds = [parse(s) for s in lines[2:]]

    assert speeds[0] == 0

    for idx, speed in enumerate(speeds):
        i = speed // 100
        lo, hi = 100 * i + tf, 100 * i + tr
        assert 100 * i <= speed

        if i == 0:
            print(0 if speed == 0 else 1)
        elif speed < lo:
            print(i)
        elif hi < speed:
            print(i + 1)
        else:
            # find the previous speed outside this range
            target = None
            for j in range(idx - 1, -1, -1):
                if not (lo <= speeds[j] <= hi):
                    target = speeds[j]
                    break

            assert target is not None
            print(i if target < lo else i + 1)

if __name__ == "__main__":
    main()
