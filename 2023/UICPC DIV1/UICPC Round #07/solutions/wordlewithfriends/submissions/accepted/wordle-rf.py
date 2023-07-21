#!/bin/python3
from collections import Counter

WORDLEN = 5
def feedback(guess, hidden):
    f = ['-']*WORDLEN
    cg = Counter(guess)
    ch = Counter(hidden)
    #print(cg,ch,guess,hidden,f)
    for i in range(WORDLEN):
        if guess[i]==hidden[i]:
            f[i] = 'G'
            cg[guess[i]] -= 1
            ch[guess[i]] -= 1
        #print(cg,ch,guess,hidden,f)
    for i in range(WORDLEN):
        if f[i]=='G':
            continue # already dealt with
        elif guess[i] in hidden and ch[guess[i]]>0:
            f[i] = 'Y'
            cg[guess[i]] -= 1
            ch[guess[i]] -= 1
        else:
            f[i] = '-'
            cg[guess[i]] -= 1
    return ''.join(f)

if __name__ == '__main__':

    N,W = map(int,input().split(' '))

    guesses = []
    for _ in range(N):
        g,f = input().split(' ')
        guesses.append( (g,f) )

    dictionary = []
    for _ in range(W):
        dictionary.append( input() )


    for word in dictionary:
        consistent = True
        for g,f in guesses:
            if not feedback(g,word)==f:
                consistent = False
                break
        if consistent:
            print(word)
