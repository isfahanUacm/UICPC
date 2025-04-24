

n= int(input())
s= input()

while ')(' in s:
    s= s.replace(")(",")*(")
while '))' in s:
    s= s.replace("))",")+1)")
while '()' in s:
    s=s.replace("()","(1)" )


exec(f"print({s})")