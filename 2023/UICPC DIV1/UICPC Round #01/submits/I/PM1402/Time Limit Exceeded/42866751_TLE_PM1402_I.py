ent=int(input())
num=[]
for i in range(ent):
    num.append(int(input()))
i=1
maxx=0
t=True
while t:
    sum_list=sum([y for y in num[i+1:]])
    power_sum_list = sum([x**2 for x in num[:i+1]])
    end=sum_list*power_sum_list
    if end>maxx:
        maxx=end
    i+=1
    if i==ent-1:
        t=False
print(maxx)