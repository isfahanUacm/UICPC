s = input()
f = False

ls = s.split(" ")

for w in ls:
    if(ls.count(w)>1):
        f = True
        break

if(f): print("no")
if(not f): print("yes")