word_list = input().split()

if len(word_list) == len(set(word_list)):
    # no repeat
    print("yes")
else:
    print("no")
