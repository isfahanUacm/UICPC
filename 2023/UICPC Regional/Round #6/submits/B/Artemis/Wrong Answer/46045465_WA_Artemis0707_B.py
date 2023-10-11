s = input()
ans = ""
al= {'R':'S', 'B':'K', 'L':'H'}
i=0
while i < len(s):
    if i < len(s) - 3 and ('L' in s[i:i+3]) and ('B' in s[i:i+3]) and ('R' in s[i:i+3]):
        ans += "C"
        i += 3
    else:
        ans += al[s[i]]
        i+=1

print(ans)