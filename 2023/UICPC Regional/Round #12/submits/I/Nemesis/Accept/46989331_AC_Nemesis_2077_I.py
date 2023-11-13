def main():
    n1 = int(input())
    n2 = int(input())

    first_choice = abs(n1 - n2)
    second_choice = abs(360 - first_choice)

    if n2 > n1:
        second_choice *= -1

    elif n2 < n1:
        first_choice *= -1

    else:
        pass

    if abs(first_choice) < abs(second_choice):
        print(first_choice)
    
    elif abs(second_choice) < abs(first_choice):
        print(second_choice)
    
    else:
        print(abs(first_choice))

if __name__ == '__main__':
    main()