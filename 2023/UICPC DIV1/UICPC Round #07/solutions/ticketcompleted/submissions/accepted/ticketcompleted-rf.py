#!/bin/python3


if __name__ == '__main__':

    #n,m,k = map(int,input().split(' '))
    n,m = map(int,input().split(' '))

    adj = {i:set() for i in range(1,n+1)}

    for _ in range(m):
        #i,j,p = map(int,input().split(' '))
        #if p==1: # actually don't care about unowned edges!
        i,j = map(int,input().split(' '))
        if True:
            adj[i].add(j)
            adj[j].add(i)


    def dfs(i,adj,visited):
        for j in adj[i]:
            if not j in visited:
                visited.add(j)
                dfs(j,adj,visited)

    def n_choose_2(_n):
        return _n*(_n-1)//2

    total_can_do = 0
    already_checked = set()
    for i in range(1,n+1):
        if i in already_checked:
            continue
        visited = set([i])
        dfs(i,adj,visited)
        already_checked |= visited
        cc_size = len(visited)
        #print('found',cc_size)
        total_can_do += n_choose_2(cc_size)

    total_pairs = n_choose_2(n)
    #print('n=',n)

    #print(total_can_do)
    #print(total_pairs)
    probability = 1.0*total_can_do/total_pairs

    # now do determine chance of at least one in k independent cards;
    # same as 1 - chance of not getting any in k independent cards
    #prob_k = 1.0 - (1.0-probability)**k
    prob_k = probability
    print(prob_k)

