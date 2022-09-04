mylist = input().split()
mylist.sort()

def find_duplicates():
    for i in range(len(mylist) - 1):
        if mylist[i] == mylist[i + 1]:
            print("no")
            return
    print("yes")

find_duplicates()