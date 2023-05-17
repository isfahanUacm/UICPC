def print_hey(e_count):
    print("h", end= "")
    for e in range(1, 2 * e_count +1):
        print("e", end="")
    print("y")

greet= input()
e_count= len(greet) -2
print_hey(e_count)