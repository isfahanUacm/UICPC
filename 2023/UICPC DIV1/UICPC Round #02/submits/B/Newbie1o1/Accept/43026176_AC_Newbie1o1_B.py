import sys


def is_eligible(start_date, birth_date, num_courses):
    if start_date >= '2010/01/01' or birth_date >= '1991/01/01':
        return True
    elif num_courses >= 41:
        return False
    else:
        return None


def main():
    num_cases = int(sys.stdin.readline().strip())
    for i in range(num_cases):
        name, start_date, birth_date, num_courses = sys.stdin.readline().strip().split()
        num_courses = int(num_courses)
        result = is_eligible(start_date, birth_date, num_courses)
        if result == True:
            print(name + " eligible")
        elif result == False:
            print(name + " ineligible")
        else:
            print(name + " coach petitions")


if __name__ == '__main__':
    main()
