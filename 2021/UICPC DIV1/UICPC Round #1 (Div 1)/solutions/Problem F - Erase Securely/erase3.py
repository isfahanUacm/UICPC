n = int(input())
s = input()
t = input()
if n % 2:
    for i in range(len(s)):
        if s[i] == t[i]:
            print('Deletion failed')
            exit(0)
else:
    for i in range(len(s)):
        if s[i] != t[i]:
            print('Deletion failed')
            exit(0)
print('Deletion succeeded')
