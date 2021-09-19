n = int(input())
s = input()
t = input()
for i in range(len(s)):
    if (n % 2 and s[i] == t[i]) or (not n % 2 and s[i] != t[i]):
        print('Deletion failed')
        exit(0)
print('Deletion succeeded')
