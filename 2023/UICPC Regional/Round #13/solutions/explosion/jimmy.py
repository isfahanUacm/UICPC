import sys

def read_line_ints():
    return list(map(lambda x:int(x), sys.stdin.readline().split(' ')))

(m,n,expl) = read_line_ints()
my_health = read_line_ints()
opp_health = read_line_ints()

if expl >= sum(my_health) + sum(opp_health):
    print(1.0)
    exit(0)

state = sorted(my_health + [-x for x in opp_health])

q = { str(state) : (state, 1.0) }
#no_iter = 0

for i in range(expl):
    #print('** %d' % i)
    nq = {}
    for (state, prob) in q.values():
        #print('At %s with prob %f' % (state, prob))
        #no_iter += 1
        n = len(state)
        for j in range(n):
            copy = list(state)
            if copy[j] < 0:
                copy[j] += 1
            else:
                copy[j] -= 1
            if copy[j] == 0:
                copy.remove(0)
            else:
                copy.sort() # Decrease state space by orders of magnitude
            copy_str = str(copy)
            nq[copy_str] = (copy, nq.get(copy_str,(0,0.0))[1] + prob/n)

    q = nq

tot_prob = 0.0
for (state, prob) in q.values():
    if state[0] > 0:
        tot_prob += prob

print(tot_prob)
#print(no_iter)
