def str2tup( s ):
	#  a     c
	#   \   /
	#     #
	#     |
	#     b
	# a + b + c = 0
	x = ord(s[0])-ord('a')
	y = int(s[1:])
	if x < 5:
		return (5-x,6-y,0)
	else:
		return (0,6-y,x-5)

def canon( s ):
	(a,b,c) = s
	m = min(a,b,c)
	return (a-m,b-m,c-m)

def canmove( s, t ):
	return len({ u-v for (u,v) in zip(s,t) }) == 2

def exists( s ):
	for x in canon(s):
		if abs(x) > 5:
			return False
	return True
	
C = [ str2tup(s) for s in raw_input().split() ]
done = set()
total = 0
for a in range(6):
	for b in range(6):
		for c in range(6):
			s = canon((a,b,c))
			if exists(s) and s not in done:
				done.add(s)
				if canmove( C[0], s ) and canmove( s, C[1] ):
					#print s
					total += 1
print total

