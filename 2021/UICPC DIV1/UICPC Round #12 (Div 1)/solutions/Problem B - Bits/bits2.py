t = int(input())
for i in range(0,t):
	n = input()
	ans=''
	mx=0
	for j in n:
		ans = ans + j
		mx = max(mx,str(bin(int(ans))).count('1'))
	print(mx)