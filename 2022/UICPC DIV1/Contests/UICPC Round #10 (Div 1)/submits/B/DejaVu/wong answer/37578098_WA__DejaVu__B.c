from re import T


t = int(input())

while t!=0:
    t-=1
    s1 = input()
    s2 = input()
    s1 = s1.replace("AA", "")
    s1 = s1.replace("BB", "")
    s1 = s1.replace("CC", "")
    s1 = s1.replace("ABAB", "")
    s1 = s1.replace("BCBC", "")
    s2 = s2.replace("AA", "")
    s2 = s2.replace("BB", "")
    s2 = s2.replace("CC", "")
    s2 = s2.replace("ABAB", "")
    s2 = s2.replace("BCBC", "")
    
    if(s1==s2):
        print("YES")
        continue
    else:
        ss = s1+s2
        ss2 = s2+s1
        if(ss=="AA" or ss=="BB" or ss=="CC" or ss=="ABAB" or ss=="BCBC"):
            print("YES")
            continue
        elif(ss2=="AA" or ss2=="BB" or ss2=="CC" or ss2=="ABAB" or ss2=="BCBC"):
            print("YES")
            continue
        else: print("NO")
        continue
