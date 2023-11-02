#!/usr/bin/python3
import sys

def main():
    lines = [line.strip() for line in sys.stdin]

    is_outside = False
    emails = {True: set(), False: set()}
    names = {True: set(), False: set()}
    for line in lines:
        if not line:
            is_outside = True
            continue

        first, last, email = line.split()
        emails[is_outside].add(email.lower())
        names[is_outside].add((first.lower(), last.lower()))

    output = []

    is_outside = False
    for line in lines:
        if not line:
            is_outside = True
            continue

        first, last, email = line.split()
        if email.lower() not in emails[not is_outside] and (first.lower(), last.lower()) not in names[not is_outside]:
            output.append((is_outside, email, last, first))

    if not output:
        print("No mismatches.")

    output.sort(key=lambda u: (u[0], u[1].lower()))

    for is_out, email, last, first in output:
        print("O" if is_out else "I", email, last, first)


if __name__ == "__main__":
    main()
