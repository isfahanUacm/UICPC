s = input()
f = False

for w in s.split(" "):
    if(s.find(w)!=-1):
        print("no")
        f = True
        break

if(not f): print("yes")