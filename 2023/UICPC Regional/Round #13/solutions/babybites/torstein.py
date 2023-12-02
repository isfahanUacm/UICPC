#!/usr/bin/env python3

def babybites():
    input()
    for i, word in enumerate(input().split()):
        if word != "mumble" and int(word) != i+1:
            return "something is fishy"
    return "makes sense"
    
print(babybites())
